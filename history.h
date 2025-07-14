#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include <QTextEdit>
#include "ui_history.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class history;
}
QT_END_NAMESPACE

class history : public QWidget
{
    Q_OBJECT
public:
    explicit history(QWidget *parent = nullptr);
    QTextEdit * getTextEdit(){ return ui->historytextEdit;}
    ~history();
protected:
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void inputMethodEvent(QInputMethodEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;
signals:
private slots:
    void on_clear_clicked();

private:
    Ui::history *ui;
};

#endif // HISTORY_H
