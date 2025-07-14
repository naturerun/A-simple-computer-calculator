#include "history.h"
#include <QCloseEvent>
#include <QMenu>
#include <QStyle>
#include <QTextCursor>
#include <QTextEdit>
#include <QAction>
history::history(QWidget *parent)
    : QWidget{parent}, ui(new Ui::history)
{
    ui->setupUi(this);
}

history::~history()
{
    delete ui;
}

void history::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = new QMenu(this);
    QAction *copyAction = menu->addAction(style()->standardIcon(QStyle::SP_CommandLink),"复制");
    copyAction->setEnabled(ui->historytextEdit->textCursor().hasSelection());
    connect(copyAction, &QAction::triggered, ui->historytextEdit, &QTextEdit::copy);

    menu->exec(event->globalPos());
    delete menu;
}

void history::dragEnterEvent(QDragEnterEvent *event)
{
    event->ignore();
}

void history::dragMoveEvent(QDragMoveEvent *event)
{
    event->ignore();
}

void history::dropEvent(QDropEvent *event)
{
    event->ignore();
}

void history::inputMethodEvent(QInputMethodEvent *event)
{
    event->ignore();
}

void history::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
}

void history::keyPressEvent(QKeyEvent* event)
{
    event->ignore();
}

void history::on_clear_clicked()
{
    ui->historytextEdit->clear();
}

