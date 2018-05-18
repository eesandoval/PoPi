#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <qxtglobalshortcut.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void handleGlobalShortcut();

private slots:
    void replyFinished(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    void shootScreen();
    void saveScreenshot();
    void uploadScreenshot();
    QString convertScreenshot();

    QxtGlobalShortcut m_globalShortcut;
    QPixmap originalPixmap;
    QString fileName;
    QUrl imgurURL;
};

#endif // MAINWINDOW_H
