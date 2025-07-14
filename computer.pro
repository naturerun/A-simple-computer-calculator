QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_PROJECT_DEPTH = 0

INCLUDEPATH += D:\vcpkg\installed\x64-windows\include

LIBS += -LD:\vcpkg\installed\x64-windows\lib

SOURCES += \
    history.cpp \
    main.cpp \
    computer.cpp \
    parser.cpp \
    restrictedqtextedit.cpp

HEADERS += \
    computer.h \
    history.h \
    parser.h \
    restrictedqtextedit.h

FORMS += \
    computer.ui \
    history.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    stylesheet.qrc
