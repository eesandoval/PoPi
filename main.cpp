#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "eventfilter.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    EventFilter filter;
    a.installNativeEventFilter(&filter);
    filter.setup(&w);

    return a.exec();
}
