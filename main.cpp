#include "computer.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile dark_style_file(":/stylesheet/global_style_sheet_dark.qss");
    dark_style_file.open(QFile::ReadOnly);
    QString dark_style = dark_style_file.readAll();
    dark_style_file.close();
    QFile white_style_file(":/stylesheet/global_style_sheet_white.qss");
    white_style_file.open(QFile::ReadOnly);
    QString white_style = white_style_file.readAll();
    white_style_file.close();
    computer w(&dark_style, &white_style);
    w.show();
    return a.exec();
}
