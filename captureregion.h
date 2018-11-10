#ifndef CAPTUREREGION_H
#define CAPTUREREGION_H

#include <QWidget>
#include <QLabel>
#include <QRubberBand>
namespace Ui {
class captureregion;
}

class captureregion : public QWidget
{
    Q_OBJECT

public:
    explicit captureregion(QWidget *parent = 0);
    void setImageLabel(QPixmap newImage);
    ~captureregion();
    QPixmap *pixmap;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::captureregion *ui;
    QPoint point;
    QRubberBand *rubberBand;
};

#endif // CAPTUREREGION_H
