/********************************************************************************
** Form generated from reading UI file 'computer.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPUTER_H
#define UI_COMPUTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "restrictedqtextedit.h"

QT_BEGIN_NAMESPACE

class Ui_computer
{
public:
    QWidget *computer;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QPushButton *E;
    QPushButton *deg_radian;
    QPushButton *MR;
    QPushButton *MS;
    QPushButton *mod;
    QPushButton *fac;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *arctriangle;
    QPushButton *triangle;
    QPushButton *h;
    QGridLayout *gridLayout_2;
    QPushButton *NapierianLogarithm;
    QPushButton *x_y;
    QPushButton *history_record;
    QPushButton *logarithm;
    QPushButton *x10;
    QPushButton *ex;
    QPushButton *sqrt;
    QPushButton *x1y;
    QPushButton *x2;
    QPushButton *floor;
    QPushButton *_2x;
    QPushButton *_1x;
    QPushButton *dark_white_change;
    QPushButton *fabs;
    QPushButton *common_logarithms;
    QPushButton *ceil;
    QPushButton *x3;
    QPushButton *cbrt;
    QHBoxLayout *horizontalLayout;
    QPushButton *e;
    QPushButton *pi;
    QPushButton *backspace;
    QGridLayout *gridLayout;
    QPushButton *c;
    QPushButton *ce;
    QPushButton *add;
    QPushButton *_1;
    QPushButton *_2;
    QPushButton *_3;
    QPushButton *minus;
    QPushButton *_4;
    QPushButton *_5;
    QPushButton *_6;
    QPushButton *multiply;
    QPushButton *_7;
    QPushButton *_8;
    QPushButton *_9;
    QPushButton *divide;
    QPushButton *_0;
    QPushButton *left_bracket;
    QPushButton *right_bracket;
    QPushButton *dot;
    QPushButton *equal;
    restrictedQTextEdit *textEdit;

    void setupUi(QWidget *computer)
    {
        if (computer->objectName().isEmpty())
            computer->setObjectName("computer");
        computer->resize(779, 710);
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(computer->sizePolicy().hasHeightForWidth());
        computer->setSizePolicy(sizePolicy);
        computer->setMinimumSize(QSize(755, 710));
        computer->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4 = new QGridLayout(computer);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName("gridLayout_3");
        E = new QPushButton(computer);
        E->setObjectName("E");
        sizePolicy.setHeightForWidth(E->sizePolicy().hasHeightForWidth());
        E->setSizePolicy(sizePolicy);
        E->setMinimumSize(QSize(30, 25));

        gridLayout_3->addWidget(E, 1, 2, 1, 1);

        deg_radian = new QPushButton(computer);
        deg_radian->setObjectName("deg_radian");
        sizePolicy.setHeightForWidth(deg_radian->sizePolicy().hasHeightForWidth());
        deg_radian->setSizePolicy(sizePolicy);
        deg_radian->setMinimumSize(QSize(30, 25));
        QFont font;
        font.setPointSize(12);
        deg_radian->setFont(font);

        gridLayout_3->addWidget(deg_radian, 1, 0, 1, 2);

        MR = new QPushButton(computer);
        MR->setObjectName("MR");
        sizePolicy.setHeightForWidth(MR->sizePolicy().hasHeightForWidth());
        MR->setSizePolicy(sizePolicy);
        MR->setMinimumSize(QSize(30, 25));
        MR->setFont(font);

        gridLayout_3->addWidget(MR, 2, 0, 1, 2);

        MS = new QPushButton(computer);
        MS->setObjectName("MS");
        sizePolicy.setHeightForWidth(MS->sizePolicy().hasHeightForWidth());
        MS->setSizePolicy(sizePolicy);
        MS->setMinimumSize(QSize(30, 25));
        MS->setFont(font);

        gridLayout_3->addWidget(MS, 2, 2, 2, 1);

        mod = new QPushButton(computer);
        mod->setObjectName("mod");
        sizePolicy.setHeightForWidth(mod->sizePolicy().hasHeightForWidth());
        mod->setSizePolicy(sizePolicy);
        mod->setMinimumSize(QSize(30, 25));
        QFont font1;
        font1.setPointSize(11);
        mod->setFont(font1);

        gridLayout_3->addWidget(mod, 0, 2, 1, 1);

        fac = new QPushButton(computer);
        fac->setObjectName("fac");
        sizePolicy.setHeightForWidth(fac->sizePolicy().hasHeightForWidth());
        fac->setSizePolicy(sizePolicy);
        fac->setMinimumSize(QSize(30, 25));
        fac->setFont(font1);

        gridLayout_3->addWidget(fac, 0, 0, 1, 2);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setRowStretch(2, 1);
        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(2, 1);

        gridLayout_4->addLayout(gridLayout_3, 1, 1, 3, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        arctriangle = new QPushButton(computer);
        arctriangle->setObjectName("arctriangle");
        sizePolicy.setHeightForWidth(arctriangle->sizePolicy().hasHeightForWidth());
        arctriangle->setSizePolicy(sizePolicy);
        arctriangle->setMinimumSize(QSize(50, 25));

        horizontalLayout_2->addWidget(arctriangle);

        triangle = new QPushButton(computer);
        triangle->setObjectName("triangle");
        sizePolicy.setHeightForWidth(triangle->sizePolicy().hasHeightForWidth());
        triangle->setSizePolicy(sizePolicy);
        triangle->setMinimumSize(QSize(50, 25));

        horizontalLayout_2->addWidget(triangle);

        h = new QPushButton(computer);
        h->setObjectName("h");
        sizePolicy.setHeightForWidth(h->sizePolicy().hasHeightForWidth());
        h->setSizePolicy(sizePolicy);
        h->setMinimumSize(QSize(30, 25));

        horizontalLayout_2->addWidget(h);

        horizontalLayout_2->setStretch(2, 2);

        gridLayout_4->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        NapierianLogarithm = new QPushButton(computer);
        NapierianLogarithm->setObjectName("NapierianLogarithm");
        sizePolicy.setHeightForWidth(NapierianLogarithm->sizePolicy().hasHeightForWidth());
        NapierianLogarithm->setSizePolicy(sizePolicy);
        NapierianLogarithm->setMinimumSize(QSize(30, 25));
        NapierianLogarithm->setFont(font);

        gridLayout_2->addWidget(NapierianLogarithm, 4, 0, 1, 1);

        x_y = new QPushButton(computer);
        x_y->setObjectName("x_y");
        sizePolicy.setHeightForWidth(x_y->sizePolicy().hasHeightForWidth());
        x_y->setSizePolicy(sizePolicy);
        x_y->setMinimumSize(QSize(30, 25));
        x_y->setFont(font);
        x_y->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(x_y, 1, 1, 1, 1);

        history_record = new QPushButton(computer);
        history_record->setObjectName("history_record");
        sizePolicy.setHeightForWidth(history_record->sizePolicy().hasHeightForWidth());
        history_record->setSizePolicy(sizePolicy);
        history_record->setMinimumSize(QSize(30, 25));
        history_record->setFont(font);

        gridLayout_2->addWidget(history_record, 5, 1, 1, 1);

        logarithm = new QPushButton(computer);
        logarithm->setObjectName("logarithm");
        sizePolicy.setHeightForWidth(logarithm->sizePolicy().hasHeightForWidth());
        logarithm->setSizePolicy(sizePolicy);
        logarithm->setMinimumSize(QSize(30, 25));
        logarithm->setFont(font);
        logarithm->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(logarithm, 3, 2, 1, 1);

        x10 = new QPushButton(computer);
        x10->setObjectName("x10");
        x10->setEnabled(true);
        sizePolicy.setHeightForWidth(x10->sizePolicy().hasHeightForWidth());
        x10->setSizePolicy(sizePolicy);
        x10->setMinimumSize(QSize(30, 25));
        x10->setFont(font);

        gridLayout_2->addWidget(x10, 5, 0, 1, 1);

        ex = new QPushButton(computer);
        ex->setObjectName("ex");
        sizePolicy.setHeightForWidth(ex->sizePolicy().hasHeightForWidth());
        ex->setSizePolicy(sizePolicy);
        ex->setMinimumSize(QSize(30, 25));
        ex->setFont(font);
        ex->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(ex, 2, 2, 1, 1);

        sqrt = new QPushButton(computer);
        sqrt->setObjectName("sqrt");
        sizePolicy.setHeightForWidth(sqrt->sizePolicy().hasHeightForWidth());
        sqrt->setSizePolicy(sizePolicy);
        sqrt->setMinimumSize(QSize(30, 25));
        sqrt->setFont(font);
        sqrt->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(sqrt, 3, 0, 1, 1);

        x1y = new QPushButton(computer);
        x1y->setObjectName("x1y");
        sizePolicy.setHeightForWidth(x1y->sizePolicy().hasHeightForWidth());
        x1y->setSizePolicy(sizePolicy);
        x1y->setMinimumSize(QSize(30, 25));
        x1y->setFont(font);
        x1y->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(x1y, 1, 2, 1, 1);

        x2 = new QPushButton(computer);
        x2->setObjectName("x2");
        sizePolicy.setHeightForWidth(x2->sizePolicy().hasHeightForWidth());
        x2->setSizePolicy(sizePolicy);
        x2->setMinimumSize(QSize(30, 25));
        x2->setFont(font);
        x2->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(x2, 2, 0, 1, 1);

        floor = new QPushButton(computer);
        floor->setObjectName("floor");
        sizePolicy.setHeightForWidth(floor->sizePolicy().hasHeightForWidth());
        floor->setSizePolicy(sizePolicy);
        floor->setMinimumSize(QSize(30, 25));
        floor->setFont(font);

        gridLayout_2->addWidget(floor, 0, 1, 1, 1);

        _2x = new QPushButton(computer);
        _2x->setObjectName("_2x");
        sizePolicy.setHeightForWidth(_2x->sizePolicy().hasHeightForWidth());
        _2x->setSizePolicy(sizePolicy);
        _2x->setMinimumSize(QSize(30, 25));
        _2x->setFont(font);

        gridLayout_2->addWidget(_2x, 4, 2, 1, 1);

        _1x = new QPushButton(computer);
        _1x->setObjectName("_1x");
        sizePolicy.setHeightForWidth(_1x->sizePolicy().hasHeightForWidth());
        _1x->setSizePolicy(sizePolicy);
        _1x->setMinimumSize(QSize(30, 25));
        _1x->setFont(font);
        _1x->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(_1x, 1, 0, 1, 1);

        dark_white_change = new QPushButton(computer);
        dark_white_change->setObjectName("dark_white_change");
        sizePolicy.setHeightForWidth(dark_white_change->sizePolicy().hasHeightForWidth());
        dark_white_change->setSizePolicy(sizePolicy);
        dark_white_change->setMinimumSize(QSize(30, 25));
        dark_white_change->setFont(font);

        gridLayout_2->addWidget(dark_white_change, 5, 2, 1, 1);

        fabs = new QPushButton(computer);
        fabs->setObjectName("fabs");
        sizePolicy.setHeightForWidth(fabs->sizePolicy().hasHeightForWidth());
        fabs->setSizePolicy(sizePolicy);
        fabs->setMinimumSize(QSize(30, 25));
        fabs->setFont(font);

        gridLayout_2->addWidget(fabs, 0, 0, 1, 1);

        common_logarithms = new QPushButton(computer);
        common_logarithms->setObjectName("common_logarithms");
        sizePolicy.setHeightForWidth(common_logarithms->sizePolicy().hasHeightForWidth());
        common_logarithms->setSizePolicy(sizePolicy);
        common_logarithms->setMinimumSize(QSize(30, 25));
        common_logarithms->setFont(font);

        gridLayout_2->addWidget(common_logarithms, 4, 1, 1, 1);

        ceil = new QPushButton(computer);
        ceil->setObjectName("ceil");
        sizePolicy.setHeightForWidth(ceil->sizePolicy().hasHeightForWidth());
        ceil->setSizePolicy(sizePolicy);
        ceil->setMinimumSize(QSize(30, 25));
        ceil->setFont(font);

        gridLayout_2->addWidget(ceil, 0, 2, 1, 1);

        x3 = new QPushButton(computer);
        x3->setObjectName("x3");
        sizePolicy.setHeightForWidth(x3->sizePolicy().hasHeightForWidth());
        x3->setSizePolicy(sizePolicy);
        x3->setMinimumSize(QSize(30, 25));
        x3->setFont(font);
        x3->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(x3, 2, 1, 1, 1);

        cbrt = new QPushButton(computer);
        cbrt->setObjectName("cbrt");
        sizePolicy.setHeightForWidth(cbrt->sizePolicy().hasHeightForWidth());
        cbrt->setSizePolicy(sizePolicy);
        cbrt->setMinimumSize(QSize(30, 25));
        cbrt->setFont(font);
        cbrt->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(cbrt, 3, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setRowStretch(3, 1);
        gridLayout_2->setRowStretch(4, 1);
        gridLayout_2->setRowStretch(5, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);

        gridLayout_4->addLayout(gridLayout_2, 2, 2, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        e = new QPushButton(computer);
        e->setObjectName("e");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(e->sizePolicy().hasHeightForWidth());
        e->setSizePolicy(sizePolicy1);
        e->setMinimumSize(QSize(30, 30));
        QFont font2;
        font2.setPointSize(20);
        e->setFont(font2);

        horizontalLayout->addWidget(e);

        pi = new QPushButton(computer);
        pi->setObjectName("pi");
        sizePolicy1.setHeightForWidth(pi->sizePolicy().hasHeightForWidth());
        pi->setSizePolicy(sizePolicy1);
        pi->setMinimumSize(QSize(30, 30));
        pi->setFont(font2);

        horizontalLayout->addWidget(pi);

        backspace = new QPushButton(computer);
        backspace->setObjectName("backspace");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(backspace->sizePolicy().hasHeightForWidth());
        backspace->setSizePolicy(sizePolicy2);
        backspace->setMinimumSize(QSize(30, 30));
        QFont font3;
        font3.setPointSize(14);
        backspace->setFont(font3);

        horizontalLayout->addWidget(backspace);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);

        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        c = new QPushButton(computer);
        c->setObjectName("c");
        sizePolicy1.setHeightForWidth(c->sizePolicy().hasHeightForWidth());
        c->setSizePolicy(sizePolicy1);
        c->setMinimumSize(QSize(30, 30));
        c->setFont(font);

        gridLayout->addWidget(c, 0, 2, 1, 1);

        ce = new QPushButton(computer);
        ce->setObjectName("ce");
        sizePolicy1.setHeightForWidth(ce->sizePolicy().hasHeightForWidth());
        ce->setSizePolicy(sizePolicy1);
        ce->setMinimumSize(QSize(30, 30));
        ce->setFont(font);

        gridLayout->addWidget(ce, 0, 3, 1, 1);

        add = new QPushButton(computer);
        add->setObjectName("add");
        sizePolicy1.setHeightForWidth(add->sizePolicy().hasHeightForWidth());
        add->setSizePolicy(sizePolicy1);
        add->setMinimumSize(QSize(30, 30));
        add->setFont(font3);

        gridLayout->addWidget(add, 1, 0, 1, 1);

        _1 = new QPushButton(computer);
        _1->setObjectName("_1");
        sizePolicy1.setHeightForWidth(_1->sizePolicy().hasHeightForWidth());
        _1->setSizePolicy(sizePolicy1);
        _1->setMinimumSize(QSize(30, 30));
        _1->setFont(font1);

        gridLayout->addWidget(_1, 1, 1, 1, 1);

        _2 = new QPushButton(computer);
        _2->setObjectName("_2");
        sizePolicy1.setHeightForWidth(_2->sizePolicy().hasHeightForWidth());
        _2->setSizePolicy(sizePolicy1);
        _2->setMinimumSize(QSize(30, 30));
        _2->setFont(font1);

        gridLayout->addWidget(_2, 1, 2, 1, 1);

        _3 = new QPushButton(computer);
        _3->setObjectName("_3");
        sizePolicy1.setHeightForWidth(_3->sizePolicy().hasHeightForWidth());
        _3->setSizePolicy(sizePolicy1);
        _3->setMinimumSize(QSize(30, 30));
        _3->setFont(font1);

        gridLayout->addWidget(_3, 1, 3, 1, 1);

        minus = new QPushButton(computer);
        minus->setObjectName("minus");
        sizePolicy1.setHeightForWidth(minus->sizePolicy().hasHeightForWidth());
        minus->setSizePolicy(sizePolicy1);
        minus->setMinimumSize(QSize(30, 30));
        minus->setFont(font3);

        gridLayout->addWidget(minus, 2, 0, 1, 1);

        _4 = new QPushButton(computer);
        _4->setObjectName("_4");
        sizePolicy1.setHeightForWidth(_4->sizePolicy().hasHeightForWidth());
        _4->setSizePolicy(sizePolicy1);
        _4->setMinimumSize(QSize(30, 30));
        _4->setFont(font1);

        gridLayout->addWidget(_4, 2, 1, 1, 1);

        _5 = new QPushButton(computer);
        _5->setObjectName("_5");
        sizePolicy1.setHeightForWidth(_5->sizePolicy().hasHeightForWidth());
        _5->setSizePolicy(sizePolicy1);
        _5->setMinimumSize(QSize(30, 30));
        _5->setFont(font1);

        gridLayout->addWidget(_5, 2, 2, 1, 1);

        _6 = new QPushButton(computer);
        _6->setObjectName("_6");
        sizePolicy1.setHeightForWidth(_6->sizePolicy().hasHeightForWidth());
        _6->setSizePolicy(sizePolicy1);
        _6->setMinimumSize(QSize(30, 30));
        _6->setFont(font1);

        gridLayout->addWidget(_6, 2, 3, 1, 1);

        multiply = new QPushButton(computer);
        multiply->setObjectName("multiply");
        sizePolicy1.setHeightForWidth(multiply->sizePolicy().hasHeightForWidth());
        multiply->setSizePolicy(sizePolicy1);
        multiply->setMinimumSize(QSize(30, 30));
        multiply->setFont(font3);

        gridLayout->addWidget(multiply, 3, 0, 1, 1);

        _7 = new QPushButton(computer);
        _7->setObjectName("_7");
        sizePolicy1.setHeightForWidth(_7->sizePolicy().hasHeightForWidth());
        _7->setSizePolicy(sizePolicy1);
        _7->setMinimumSize(QSize(30, 30));
        _7->setFont(font1);

        gridLayout->addWidget(_7, 3, 1, 1, 1);

        _8 = new QPushButton(computer);
        _8->setObjectName("_8");
        sizePolicy1.setHeightForWidth(_8->sizePolicy().hasHeightForWidth());
        _8->setSizePolicy(sizePolicy1);
        _8->setMinimumSize(QSize(30, 30));
        _8->setFont(font1);

        gridLayout->addWidget(_8, 3, 2, 1, 1);

        _9 = new QPushButton(computer);
        _9->setObjectName("_9");
        sizePolicy1.setHeightForWidth(_9->sizePolicy().hasHeightForWidth());
        _9->setSizePolicy(sizePolicy1);
        _9->setMinimumSize(QSize(30, 30));
        _9->setFont(font1);

        gridLayout->addWidget(_9, 3, 3, 1, 1);

        divide = new QPushButton(computer);
        divide->setObjectName("divide");
        sizePolicy1.setHeightForWidth(divide->sizePolicy().hasHeightForWidth());
        divide->setSizePolicy(sizePolicy1);
        divide->setMinimumSize(QSize(30, 30));
        divide->setFont(font3);

        gridLayout->addWidget(divide, 4, 0, 1, 1);

        _0 = new QPushButton(computer);
        _0->setObjectName("_0");
        sizePolicy1.setHeightForWidth(_0->sizePolicy().hasHeightForWidth());
        _0->setSizePolicy(sizePolicy1);
        _0->setMinimumSize(QSize(30, 30));
        _0->setFont(font1);

        gridLayout->addWidget(_0, 4, 2, 1, 1);

        left_bracket = new QPushButton(computer);
        left_bracket->setObjectName("left_bracket");
        sizePolicy1.setHeightForWidth(left_bracket->sizePolicy().hasHeightForWidth());
        left_bracket->setSizePolicy(sizePolicy1);
        left_bracket->setMinimumSize(QSize(30, 30));
        left_bracket->setFont(font);

        gridLayout->addWidget(left_bracket, 0, 0, 1, 1);

        right_bracket = new QPushButton(computer);
        right_bracket->setObjectName("right_bracket");
        sizePolicy1.setHeightForWidth(right_bracket->sizePolicy().hasHeightForWidth());
        right_bracket->setSizePolicy(sizePolicy1);
        right_bracket->setMinimumSize(QSize(30, 30));
        right_bracket->setFont(font);

        gridLayout->addWidget(right_bracket, 0, 1, 1, 1);

        dot = new QPushButton(computer);
        dot->setObjectName("dot");
        sizePolicy1.setHeightForWidth(dot->sizePolicy().hasHeightForWidth());
        dot->setSizePolicy(sizePolicy1);
        dot->setMinimumSize(QSize(30, 30));
        dot->setFont(font3);

        gridLayout->addWidget(dot, 4, 1, 1, 1);

        equal = new QPushButton(computer);
        equal->setObjectName("equal");
        sizePolicy1.setHeightForWidth(equal->sizePolicy().hasHeightForWidth());
        equal->setSizePolicy(sizePolicy1);
        equal->setMinimumSize(QSize(30, 30));
        equal->setFont(font3);

        gridLayout->addWidget(equal, 4, 3, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);

        gridLayout_4->addLayout(gridLayout, 2, 0, 2, 1);

        textEdit = new restrictedQTextEdit(computer);
        textEdit->setObjectName("textEdit");
        textEdit->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(1);
        textEdit->setSizePolicy(sizePolicy3);
        textEdit->setMinimumSize(QSize(751, 401));
        textEdit->setAutoFillBackground(false);
        textEdit->setUndoRedoEnabled(false);
        textEdit->setReadOnly(false);
        textEdit->setCursorWidth(2);

        gridLayout_4->addWidget(textEdit, 0, 0, 1, 3);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 1);
        gridLayout_4->setRowStretch(2, 1);
        gridLayout_4->setRowStretch(3, 1);
        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1);
        gridLayout_4->setColumnStretch(2, 1);
        computer->setLayout(gridLayout_4);
        retranslateUi(computer);

        QMetaObject::connectSlotsByName(computer);
    } // setupUi

    void retranslateUi(QWidget *computer)
    {
        computer->setWindowTitle(QCoreApplication::translate("computer", "\350\256\241\347\256\227\345\231\250", nullptr));
        E->setText(QCoreApplication::translate("computer", "E(\347\247\221\345\255\246\350\256\241\346\225\260\346\263\225)", nullptr));
        deg_radian->setText(QCoreApplication::translate("computer", "\350\247\222\345\272\246\345\210\266", nullptr));
        MR->setText(QCoreApplication::translate("computer", "MR", nullptr));
        MS->setText(QCoreApplication::translate("computer", "MS", nullptr));
        mod->setText(QCoreApplication::translate("computer", "%", nullptr));
        fac->setText(QCoreApplication::translate("computer", "!", nullptr));
        arctriangle->setText(QCoreApplication::translate("computer", "\345\217\215\344\270\211\350\247\222\345\207\275\346\225\260", nullptr));
        triangle->setText(QCoreApplication::translate("computer", "\344\270\211\350\247\222\345\207\275\346\225\260", nullptr));
        h->setText(QCoreApplication::translate("computer", "\345\217\214\346\233\262\345\207\275\346\225\260", nullptr));
        NapierianLogarithm->setText(QCoreApplication::translate("computer", "ln", nullptr));
        x_y->setText(QCoreApplication::translate("computer", "x^y", nullptr));
        history_record->setText(QCoreApplication::translate("computer", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        logarithm->setText(QCoreApplication::translate("computer", "log_b^x", nullptr));
        x10->setText(QCoreApplication::translate("computer", "10^x", nullptr));
        ex->setText(QCoreApplication::translate("computer", "e^x", nullptr));
        sqrt->setText(QCoreApplication::translate("computer", "x^(1/2)", nullptr));
        x1y->setText(QCoreApplication::translate("computer", "x^(1/y)", nullptr));
        x2->setText(QCoreApplication::translate("computer", "x^2", nullptr));
        floor->setText(QCoreApplication::translate("computer", "floor", nullptr));
        _2x->setText(QCoreApplication::translate("computer", "2^x", nullptr));
        _1x->setText(QCoreApplication::translate("computer", "1/x", nullptr));
        dark_white_change->setText(QCoreApplication::translate("computer", "\347\231\275\345\244\251\346\250\241\345\274\217", nullptr));
        fabs->setText(QCoreApplication::translate("computer", "|x|", nullptr));
        common_logarithms->setText(QCoreApplication::translate("computer", "log", nullptr));
        ceil->setText(QCoreApplication::translate("computer", "ceil", nullptr));
        x3->setText(QCoreApplication::translate("computer", "x^3", nullptr));
        cbrt->setText(QCoreApplication::translate("computer", "x^(1/3)", nullptr));
        e->setText(QCoreApplication::translate("computer", "e", nullptr));
        pi->setText(QCoreApplication::translate("computer", "\317\200", nullptr));
        backspace->setText(QCoreApplication::translate("computer", "BackSpace", nullptr));
        c->setText(QCoreApplication::translate("computer", "C", nullptr));
        ce->setText(QCoreApplication::translate("computer", "CE", nullptr));
        add->setText(QCoreApplication::translate("computer", "+", nullptr));
        _1->setText(QCoreApplication::translate("computer", "1", nullptr));
        _2->setText(QCoreApplication::translate("computer", "2", nullptr));
        _3->setText(QCoreApplication::translate("computer", "3", nullptr));
        minus->setText(QCoreApplication::translate("computer", "-", nullptr));
        _4->setText(QCoreApplication::translate("computer", "4", nullptr));
        _5->setText(QCoreApplication::translate("computer", "5", nullptr));
        _6->setText(QCoreApplication::translate("computer", "6", nullptr));
        multiply->setText(QCoreApplication::translate("computer", "\303\227", nullptr));
        _7->setText(QCoreApplication::translate("computer", "7", nullptr));
        _8->setText(QCoreApplication::translate("computer", "8", nullptr));
        _9->setText(QCoreApplication::translate("computer", "9", nullptr));
        divide->setText(QCoreApplication::translate("computer", "\303\267", nullptr));
        _0->setText(QCoreApplication::translate("computer", "0", nullptr));
        left_bracket->setText(QCoreApplication::translate("computer", "(", nullptr));
        right_bracket->setText(QCoreApplication::translate("computer", ")", nullptr));
        dot->setText(QCoreApplication::translate("computer", ".", nullptr));
        equal->setText(QCoreApplication::translate("computer", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class computer: public Ui_computer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPUTER_H
