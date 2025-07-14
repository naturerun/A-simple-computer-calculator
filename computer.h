#ifndef COMPUTER_H
#define COMPUTER_H

#include <QWidget>
#include "history.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class computer;
}
QT_END_NAMESPACE

class QMenu;

class computer : public QWidget
{
    Q_OBJECT

public:
    computer(QString *dark, QString *white, QWidget *parent = nullptr);
    ~computer();

protected:
    void resizeEvent(QResizeEvent* event) override;
private slots:
    void on_backspace_clicked();
    void add_sin();
    void add_cos();
    void add_tan();
    void add_csc();
    void add_sec();
    void add_cot();
    void add_arcsin();
    void add_arccos();
    void add_arctan();
    void add_sinh();
    void add_cosh();
    void add_tanh();

    void on_fabs_clicked();

    void on_floor_clicked();

    void on_ceil_clicked();

    void on__1x_clicked();

    void on_x_y_clicked();

    void on_x1y_clicked();

    void on_x2_clicked();

    void on_x3_clicked();

    void on_ex_clicked();

    void on_sqrt_clicked();

    void on_cbrt_clicked();

    void on_logarithm_clicked();

    void on_NapierianLogarithm_clicked();

    void on_common_logarithms_clicked();

    void on__2x_clicked();

    void on_x10_clicked();

    void on_fac_clicked();

    void on_mod_clicked();

    void on_E_clicked();

    void on_e_clicked();

    void on_pi_clicked();

    void on_left_bracket_clicked();

    void on_right_bracket_clicked();

    void on_c_clicked();

    void on_ce_clicked();

    void on_equal_clicked();

    void on_add_clicked();

    void on__1_clicked();

    void on__2_clicked();

    void on__3_clicked();

    void on_minus_clicked();

    void on__4_clicked();

    void on__5_clicked();

    void on__6_clicked();

    void on_multiply_clicked();

    void on__7_clicked();

    void on__8_clicked();

    void on__9_clicked();

    void on_divide_clicked();

    void on_dot_clicked();

    void on__0_clicked();


    void on_dark_white_change_clicked();

    void on_MR_clicked();

    void on_MS_clicked();

    void on_history_record_clicked();

    void on_deg_radian_clicked();

private:
    Ui::computer *ui;
    QMenu *Trimenu;
    QMenu *ArcTrimenu;
    QMenu *Hmenu;
    QString *dark_style_sheet;
    QString *white_style_sheet;
    history *record;
};
#endif // COMPUTER_H
