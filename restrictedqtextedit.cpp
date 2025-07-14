#include <QKeyEvent>
#include <QTextCursor>
#include <QTextBlockFormat>
#include <QTextBlock>
#include <QMenu>
#include <QStyle>
#include "restrictedqtextedit.h"
restrictedQTextEdit::restrictedQTextEdit(QWidget *parent):QTextEdit(parent)
{
    expr_parse = new ParseExpr();
}

void restrictedQTextEdit::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = new QMenu(this);
    QAction *copyAction = menu->addAction(style()->standardIcon(QStyle::SP_CommandLink),"复制");
    copyAction->setEnabled(textCursor().hasSelection());
    connect(copyAction, &QAction::triggered, this, &QTextEdit::copy);

    menu->exec(event->globalPos());
    delete menu;
}

void restrictedQTextEdit::dragEnterEvent(QDragEnterEvent *event)
{
    event->ignore();
}

void restrictedQTextEdit::dragMoveEvent(QDragMoveEvent *event)
{
    event->ignore();
}

void restrictedQTextEdit::dropEvent(QDropEvent *event)
{
    event->ignore();
}

void restrictedQTextEdit::inputMethodEvent(QInputMethodEvent *event)
{
    event->ignore();
}

void restrictedQTextEdit::keyPressEvent(QKeyEvent* event)
{
    event->ignore();
}

void restrictedQTextEdit::putCE()
{
    clear();
}

void restrictedQTextEdit::MSOp()
{
    if (work_stack.empty() == false)
    {
        if (work_stack.top().flag == BlockInfo::type::RESULT)
        {
            QTextCursor c = textCursor();
            CURSOR_POSITION end = c.position();
            c.setPosition(work_stack.top().p);
            c.setPosition(end, QTextCursor::KeepAnchor);
            QString re =  c.selectedText();
            re.remove("\n");
            interResult = re;
            c.setPosition(c.position());
            setTextCursor(c);
        }
    }
}

void restrictedQTextEdit::MROp()
{
    if (interResult.isEmpty() == false)
        insertStr(interResult);
}

bool blockIsEmpty(const QTextBlock &b)
{
    return b.text().trimmed().isEmpty();
}

void restrictedQTextEdit::backSpace()
{
    QTextCursor c = textCursor();
    if (work_stack.empty() == false)
    {
        if (work_stack.top().flag != BlockInfo::type::EXPR)
            return;
        CURSOR_POSITION p = c.position();
        if (p > work_stack.top().p)
        {
            --(work_stack.top().end);
            c.movePosition(QTextCursor::Left);
            c.deleteChar();
            setTextCursor(c);
        }
        else
        {
            if (blockIsEmpty(c.block()) && work_stack.size() > 1)
            {
                work_stack.pop();
                while (true)
                {
                    c.deletePreviousChar();
                    QTextBlock b = c.block();
                    if (blockIsEmpty(b) == false)
                    {
                        setTextCursor(c);
                        return;
                    }
                }
            }
        }
    }
    else
    {
        if (c.atBlockStart() == false)
        {
            c.deletePreviousChar();
            setTextCursor(c);
        }
    }
}

void restrictedQTextEdit::mousePressEvent(QMouseEvent* event)
{
    QTextEdit::mouseMoveEvent(event);
    if (work_stack.empty() == false)
    {
        QTextCursor c = textCursor();
        if (work_stack.top().flag == BlockInfo::type::EXPR)
        {
            CURSOR_POSITION p = c.position();
            if (p < work_stack.top().p)
            {
                c.setPosition(work_stack.top().p);
                setTextCursor(c);
            }
        }
        else
        {
            c.movePosition(QTextCursor::End);
            setTextCursor(c);
        }
    }
}

void restrictedQTextEdit::putC()
{
    if (work_stack.size() > 1)
    {
        work_stack.pop();
        CURSOR_POSITION p = work_stack.top().end;
        QTextCursor c = textCursor();
        c.setPosition(p);
        CURSOR_POSITION end = document()->characterCount() - 1;
        c.setPosition(end, QTextCursor::KeepAnchor);
        c.removeSelectedText();
        setTextCursor(c);
        return;
    }
    clear();
}

void restrictedQTextEdit::insertStr(const QString &_str)
{
    QTextCursor c = textCursor();
    if (work_stack.empty() == false)
    {
        if (work_stack.top().flag != BlockInfo::type::EXPR)
        {
            c.insertText("\n");
            c.insertText("\n");
            c.insertText("\n");
            work_stack.push(BlockInfo());
            work_stack.top().p = c.position();
            c.insertText(_str);
            work_stack.top().end = c.position();
            work_stack.top().flag = BlockInfo::type::EXPR;
        }
        else
        {
            c.insertText(_str);
            c.movePosition(QTextCursor::End);
            work_stack.top().end = c.position();
        }
    }
    else
    {
        c.insertText(_str);
        work_stack.push(BlockInfo());
        work_stack.top().p = 0;
        work_stack.top().flag = BlockInfo::type::EXPR;
        work_stack.top().end = c.position();
    }
    setTextCursor(c);
}

CURSOR_POSITION restrictedQTextEdit::getValue()
{
    if (work_stack.empty() == true || work_stack.top().flag == BlockInfo::type::EXPR)
    {
       QTextCursor c = textCursor();
       if (work_stack.empty() == false)
       {
           c.setPosition(work_stack.top().p);
       }
       else
       {
           return document()->characterCount();
       }

       CURSOR_POSITION temp = c.position();
       c.setPosition(work_stack.top().end, QTextCursor::KeepAnchor);
       QString _Text = c.selectedText().replace("\n", "");  //注意_Text可能为空
       if (_Text.isEmpty())
       {
           setTextCursor(c);
           return document()->characterCount();
       }
       //解析_Text,保存结果
       string __Text = _Text.toStdString();
       expr_parse->reset();
       expr_parse->set_str(&__Text);
       ParseResult result = expr_parse->parse();

       c.setPosition(c.position());
       c.insertText("\n");
       c.insertText("\n");
       c.insertText("\n");
       //插入error或结果并更新stack
       CURSOR_POSITION origin = c.position();
       switch(result.type_flag)
       {
       case ParseResult::type::INVAILD:
          {
              c.insertText("ERROR");
              work_stack.push(BlockInfo(origin, c.position(), BlockInfo::type::ERR));
              break;
          }
       case ParseResult::type::INTEGER:
          {
              c.insertText("=");
              c.insertText(QString::fromStdString(result.int_value.str()));
              work_stack.push(BlockInfo(origin, c.position(), BlockInfo::type::RESULT));
              break;
          }
       default:
          {
              c.insertText("=");
              c.insertText(QString::fromStdString(result.float_value.str()));
              work_stack.push(BlockInfo(origin, c.position(), BlockInfo::type::RESULT));
              break;
          }
       }
       setTextCursor(c);
       return temp;
    }
    return document()->characterCount();
}

//不允许停留在中间的空段落(空段落一起插一起删),expr可以任意退格,插入，计算,非expr不允许退格且光标被限制在末尾,expr光标仅限expr范围内,work_stack是指示段落组类型的栈
//存放特定类型段落组的起始光标位置和段落组类型,不记录用作分隔有效段落组的空段落
