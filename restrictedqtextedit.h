#ifndef RESTRICTEDQTEXTEDIT_H
#define RESTRICTEDQTEXTEDIT_H

#include <QTextEdit>
#include <stack>
#include <QString>
#include "parser.h"
typedef int CURSOR_POSITION;
class QKeyEvent;

struct BlockInfo
{
    CURSOR_POSITION p;
    CURSOR_POSITION end;
    enum class type{EXPR, ERR, RESULT}flag;
    BlockInfo() = default;
    BlockInfo(CURSOR_POSITION p, CURSOR_POSITION e, type f):p(p), end(e), flag(f){}
};

class restrictedQTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    restrictedQTextEdit(QWidget *parent = nullptr);
    ~restrictedQTextEdit(){delete expr_parse;}
    void putC();
    void insertStr(const QString &_str);
    CURSOR_POSITION getValue();
    void backSpace();
    void putCE();
    void MSOp();
    void MROp();
    void setRAMode(bool r){expr_parse->setRAMode(r);}
protected:
    void keyPressEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void inputMethodEvent(QInputMethodEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;
private:
    std::stack<BlockInfo> work_stack;
    QString interResult;
    ParseExpr *expr_parse;
};

#endif // RESTRICTEDQTEXTEDIT_H
