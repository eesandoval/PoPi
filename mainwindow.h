#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QSoundEffect>
#include <QSystemTrayIcon>
#include <QIcon>
#include "captureregion.h"
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
    void handleRegionShortcut();
    void returnRegionShortcut(QPixmap *image);

protected:
    void changeEvent(QEvent *event);

private slots:
    void replyFinished(QNetworkReply* reply);
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void setSaveDirectory();
    void toggleButton();

private:
    Ui::MainWindow *ui;
    void shootScreen();
    void saveScreenshot();
    void uploadScreenshot();
    QString convertScreenshot();
    bool displayedTrayMessage = false;
    bool overrideMinimize = false;
    void loadSettings();
    void saveSettings();

    QString shutterEffectFileName = ":/media/camera_shutter.wav";
    QString jingleEffectFileName = ":/media/jingle.wav";
    QString iconFileName = ":/media/icon.png";
    QPixmap originalPixmap;
    QString fileName;
    QUrl imgurURL;
    QSoundEffect shutterEffect;
    QSoundEffect jingleEffect;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *quitAction;
    QIcon icon;
    captureregion *region;
    QString localDirectory = "";
    QString settingsFile = "settings.ini";
};

#endif // MAINWINDOW_H
