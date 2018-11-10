#-------------------------------------------------
#
# Project created by QtCreator 2018-05-14T19:47:11
#
#-------------------------------------------------

QT += core gui network multimedia widgets x11extras

LIBS += -lX11

TARGET = PoPi
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    mainwindow.h \
    captureregion.h \
    eventfilter.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    captureregion.cpp \
    eventfilter.cpp

FORMS += \
        mainwindow.ui \
    captureregion.ui

DISTFILES +=

RESOURCES += \
    resources.qrc
