#include "captureregion.h"
#include "ui_captureregion.h"
#include <QMouseEvent>
#include "mainwindow.h"
captureregion::captureregion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::captureregion)
{
    ui->setupUi(this);
}

captureregion::~captureregion()
{
    delete ui;
}

void captureregion::setImageLabel(QPixmap newImage)
{
    ui->imageLabel->setPixmap(newImage);
    ui->imageLabel->repaint();
}

void captureregion::mousePressEvent(QMouseEvent *event)
{
    if (ui->imageLabel->underMouse())
    {
        point = event->pos();
        rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
        rubberBand->show();
    }
}

void captureregion::mouseMoveEvent(QMouseEvent *event)
{
    rubberBand->setGeometry(QRect(point, event->pos()).normalized());
}

void captureregion::mouseReleaseEvent(QMouseEvent *event)
{
    QRect rect(point, event->pos());
    rubberBand->hide();
    QPixmap originalPixmap(*ui->imageLabel->pixmap());
    QImage originalImage = originalPixmap.toImage();
    QImage croppedImage = originalImage.copy(rect);
    pixmap = new QPixmap(QPixmap::fromImage(croppedImage));
    ((MainWindow*)parentWidget())->returnRegionShortcut(pixmap);
}
