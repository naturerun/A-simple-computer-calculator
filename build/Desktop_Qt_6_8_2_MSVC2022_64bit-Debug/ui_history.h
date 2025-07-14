/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_history
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *historytextEdit;
    QPushButton *clear;

    void setupUi(QWidget *history)
    {
        if (history->objectName().isEmpty())
            history->setObjectName("history");
        history->resize(705, 466);
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(history->sizePolicy().hasHeightForWidth());
        history->setSizePolicy(sizePolicy);
        history->setMinimumSize(QSize(500, 400));
        verticalLayout = new QVBoxLayout(history);
        verticalLayout->setObjectName("verticalLayout");
        historytextEdit = new QTextEdit(history);
        historytextEdit->setObjectName("historytextEdit");
        sizePolicy.setHeightForWidth(historytextEdit->sizePolicy().hasHeightForWidth());
        historytextEdit->setSizePolicy(sizePolicy);
        historytextEdit->setMinimumSize(QSize(500, 400));
        historytextEdit->setReadOnly(false);

        verticalLayout->addWidget(historytextEdit);

        clear = new QPushButton(history);
        clear->setObjectName("clear");
        sizePolicy.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy);
        clear->setMinimumSize(QSize(100, 40));

        verticalLayout->addWidget(clear);


        retranslateUi(history);

        QMetaObject::connectSlotsByName(history);
    } // setupUi

    void retranslateUi(QWidget *history)
    {
        history->setWindowTitle(QCoreApplication::translate("history", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        clear->setText(QCoreApplication::translate("history", "\346\270\205\347\251\272\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class history: public Ui_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
