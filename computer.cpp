#include "computer.h"
#include "ui_computer.h"
#include "history.h"
#include <QMenu>
#include <QTextBlock>
#include <QAction>
#include <QDateTime>

computer::computer(QString *dark, QString *white, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::computer), dark_style_sheet(dark), white_style_sheet(white)
{
    ui->setupUi(this);
    Trimenu = new QMenu(ui->triangle);
    QAction *trigger_sin = Trimenu->addAction("sin");
    QAction *trigger_cos = Trimenu->addAction("cos");
    QAction *trigger_tan = Trimenu->addAction("tan");
    QAction *trigger_csc = Trimenu->addAction("csc");
    QAction *trigger_sec = Trimenu->addAction("sec");
    QAction *trigger_cot = Trimenu->addAction("cot");
    ui->triangle->setMenu(Trimenu);
    ArcTrimenu = new QMenu(ui->arctriangle);
    QAction *trigger_arcsin = ArcTrimenu->addAction("arcsin");
    QAction *trigger_arccos = ArcTrimenu->addAction("arccos");
    QAction *trigger_arctan = ArcTrimenu->addAction("arctan");
    ui->arctriangle->setMenu(ArcTrimenu);
    Hmenu = new QMenu(ui->h);
    QAction *trigger_sinh = Hmenu->addAction("sinh");
    QAction *trigger_cosh = Hmenu->addAction("cosh");
    QAction *trigger_tanh = Hmenu->addAction("tanh");
    ui->h->setMenu(Hmenu);

    QObject::connect(trigger_sin, &QAction::triggered, this, &computer::add_sin);
    QObject::connect(trigger_cos, &QAction::triggered, this, &computer::add_cos);
    QObject::connect(trigger_tan, &QAction::triggered, this, &computer::add_tan);
    QObject::connect(trigger_csc, &QAction::triggered, this, &computer::add_csc);
    QObject::connect(trigger_sec, &QAction::triggered, this, &computer::add_sec);
    QObject::connect(trigger_cot, &QAction::triggered, this, &computer::add_cot);
    QObject::connect(trigger_arcsin, &QAction::triggered, this, &computer::add_arcsin);
    QObject::connect(trigger_arccos, &QAction::triggered, this, &computer::add_arccos);
    QObject::connect(trigger_arctan, &QAction::triggered, this, &computer::add_arctan);
    QObject::connect(trigger_sinh, &QAction::triggered, this, &computer::add_sinh);
    QObject::connect(trigger_cosh, &QAction::triggered, this, &computer::add_cosh);
    QObject::connect(trigger_tanh, &QAction::triggered, this, &computer::add_tanh);

    setStyleSheet(*dark_style_sheet);
    record = new history(nullptr);
    record->setHidden(true);
    record->setStyleSheet(*dark_style_sheet);
}

computer::~computer()
{
    delete record;
    delete ui;
}

void computer::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    update();
}

void computer::on_backspace_clicked()
{
    ui->textEdit->backSpace();
}

void computer::add_sin()
{
    ui->textEdit->insertStr("sin()");
}

void computer::add_cos()
{
    ui->textEdit->insertStr("cos()");
}

void computer::add_tan()
{
    ui->textEdit->insertStr("tan()");
}

void computer::add_csc()
{
    ui->textEdit->insertStr("csc()");
}

void computer::add_sec()
{
    ui->textEdit->insertStr("sec()");
}

void computer::add_cot()
{
    ui->textEdit->insertStr("cot()");
}

void computer::add_arcsin()
{
    ui->textEdit->insertStr("asin()");
}

void computer::add_arccos()
{
    ui->textEdit->insertStr("acos()");
}

void computer::add_arctan()
{
    ui->textEdit->insertStr("atan()");
}

void computer::add_sinh()
{
    ui->textEdit->insertStr("sinh()");
}

void computer::add_cosh()
{
    ui->textEdit->insertStr("cosh()");
}

void computer::add_tanh()
{
    ui->textEdit->insertStr("tanh()");
}

void computer::on_fabs_clicked()
{
    ui->textEdit->insertStr("fabs()");
}


void computer::on_floor_clicked()
{
    ui->textEdit->insertStr("floor()");
}


void computer::on_ceil_clicked()
{
    ui->textEdit->insertStr("ceil()");
}


void computer::on__1x_clicked()
{
    ui->textEdit->insertStr("^(-1)");
}


void computer::on_x_y_clicked()
{
    ui->textEdit->insertStr("^");
}


void computer::on_x1y_clicked()
{
    ui->textEdit->insertStr("^(1/())");
}


void computer::on_x2_clicked()
{
    ui->textEdit->insertStr("^2");
}


void computer::on_x3_clicked()
{
    ui->textEdit->insertStr("^3");
}


void computer::on_ex_clicked()
{
    ui->textEdit->insertStr("e^()");
}


void computer::on_sqrt_clicked()
{
    ui->textEdit->insertStr("sqrt()");
}


void computer::on_cbrt_clicked()
{
    ui->textEdit->insertStr("cbrt()");
}


void computer::on_logarithm_clicked()
{
    ui->textEdit->insertStr("ln()/ln()");
}


void computer::on_NapierianLogarithm_clicked()
{
    ui->textEdit->insertStr("ln()");
}


void computer::on_common_logarithms_clicked()
{
    ui->textEdit->insertStr("log()");
}


void computer::on__2x_clicked()
{
    ui->textEdit->insertStr("2^()");
}


void computer::on_x10_clicked()
{
    ui->textEdit->insertStr("10^()");
}


void computer::on_fac_clicked()
{
    ui->textEdit->insertStr("!");
}


void computer::on_mod_clicked()
{
    ui->textEdit->insertStr("%");
}


void computer::on_E_clicked()
{
    ui->textEdit->insertStr("E");
}


void computer::on_e_clicked()
{
    ui->textEdit->insertStr("e");
}


void computer::on_pi_clicked()
{
    ui->textEdit->insertStr("pi");
}


void computer::on_left_bracket_clicked()
{
    ui->textEdit->insertStr("(");
}


void computer::on_right_bracket_clicked()
{
    ui->textEdit->insertStr(")");
}


void computer::on_c_clicked()
{
    ui->textEdit->putC();
}


void computer::on_ce_clicked()
{
    ui->textEdit->putCE();
}


void computer::on_equal_clicked()
{
    CURSOR_POSITION r = ui->textEdit->getValue();
    if (r != ui->textEdit->document()->characterCount())
    {
        QTextCursor c = ui->textEdit->textCursor();
        c.setPosition(r);
        CURSOR_POSITION end = ui->textEdit->document()->characterCount() - 1;
        c.setPosition(end, QTextCursor::KeepAnchor);
        QString _Text = c.selectedText();
        c.setPosition(c.position());
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString fcurrentDateTime = currentDateTime.toString("yyyy年MM月dd日 HH时mm分ss秒");
        QTextEdit *h_r = record->getTextEdit();
        QTextCursor c_h_r = h_r->textCursor();
        c_h_r.movePosition(QTextCursor::End);
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        c_h_r.setCharFormat(format);

        c_h_r.insertText(fcurrentDateTime);

        QTextCharFormat default_f;
        c_h_r.setCharFormat(default_f);

        c_h_r.insertText("\n\n");
        c_h_r.insertText(_Text);
        h_r->setTextCursor(c_h_r);

        ui->textEdit->setTextCursor(c);
    }
}


void computer::on_add_clicked()
{
    ui->textEdit->insertStr("+");
}


void computer::on__1_clicked()
{
    ui->textEdit->insertStr("1");
}


void computer::on__2_clicked()
{
    ui->textEdit->insertStr("2");
}


void computer::on__3_clicked()
{
    ui->textEdit->insertStr("3");
}


void computer::on_minus_clicked()
{
    ui->textEdit->insertStr("-");
}


void computer::on__4_clicked()
{
    ui->textEdit->insertStr("4");
}


void computer::on__5_clicked()
{
    ui->textEdit->insertStr("5");
}


void computer::on__6_clicked()
{
    ui->textEdit->insertStr("6");
}


void computer::on_multiply_clicked()
{
    ui->textEdit->insertStr("*");
}


void computer::on__7_clicked()
{
    ui->textEdit->insertStr("7");
}


void computer::on__8_clicked()
{
    ui->textEdit->insertStr("8");
}


void computer::on__9_clicked()
{
    ui->textEdit->insertStr("9");
}


void computer::on_divide_clicked()
{
    ui->textEdit->insertStr("/");
}


void computer::on_dot_clicked()
{
    ui->textEdit->insertStr(".");
}


void computer::on__0_clicked()
{
    ui->textEdit->insertStr("0");
}


void computer::on_dark_white_change_clicked()
{
    if (ui->dark_white_change->text() == "白天模式")
    {
        setStyleSheet(*white_style_sheet);
        record->setStyleSheet(*white_style_sheet);
        ui->dark_white_change->setText("黑夜模式");
    }
    else
    {
        setStyleSheet(*dark_style_sheet);
        record->setStyleSheet(*dark_style_sheet);
        ui->dark_white_change->setText("白天模式");
    }
}


void computer::on_MR_clicked()
{
    ui->textEdit->MROp();
}


void computer::on_MS_clicked()
{
    ui->textEdit->MSOp();
}



void computer::on_history_record_clicked()
{
    if (record->isHidden())
    {
        record->show();
    }
    else
    {
        record->setHidden(true);
    }
}


void computer::on_deg_radian_clicked()
{
    if (ui->deg_radian->text() == "弧度制")
    {
        ui->textEdit->setRAMode(true);
        ui->deg_radian->setText("角度制");
    }
    else
    {
        ui->textEdit->setRAMode(false);
        ui->deg_radian->setText("弧度制");
    }
}

