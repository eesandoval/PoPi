#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QAbstractNativeEventFilter>
#include <QWidget>

class EventFilter: public QAbstractNativeEventFilter
{
public:
    void setup(QWidget *target);
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result);
private:
    int keycode;
    QWidget * target;
};

#endif // EVENTFILTER_H
