#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_screenshotButton_clicked();
    void replyFinished(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    void shootScreen();
    void saveScreenshot();
    void uploadScreenshot();
    QString convertScreenshot();

    QPixmap originalPixmap;
    QString fileName;
    QUrl imgurURL;
};

#endif // MAINWINDOW_H
