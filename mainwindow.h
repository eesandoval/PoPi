#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <qglobalshortcut.h>
#include <QSoundEffect>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QElapsedTimer>
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

protected:
    void changeEvent(QEvent *event);

private slots:
    void replyFinished(QNetworkReply* reply);
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainWindow *ui;
    void shootScreen();
    void saveScreenshot();
    void uploadScreenshot();
    QString convertScreenshot();

    QString shutterEffectFileName = ":/media/camera_shutter.wav";
    QString iconFileName = ":/media/icon.png";
    QGlobalShortcut  m_globalShortcut;
    QPixmap originalPixmap;
    QString fileName;
    QUrl imgurURL;
    QSoundEffect shutterEffect;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QElapsedTimer *timer;
    QAction *quitAction;
    QIcon icon;
};

#endif // MAINWINDOW_H
