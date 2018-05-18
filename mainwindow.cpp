#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGuiApplication>
#include <QUrlQuery>
#include <QtNetwork/QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QWindow>
#include <QScreen>
#include <QClipboard>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imgurURL = QUrl("https://api.imgur.com/3/image");
    m_globalShortcut.setShortcut(QKeySequence("CTRL+Shift+4"));
    m_globalShortcut.setEnabled(true);
    connect(&m_globalShortcut, SIGNAL(activated(QxtGlobalShortcut*)), SLOT(handleGlobalShortcut()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleGlobalShortcut()
{
    shootScreen();
}

void MainWindow::shootScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;

    originalPixmap = screen->grabWindow(0);
    saveScreenshot();
    uploadScreenshot();
}

void MainWindow::saveScreenshot()
{
    fileName = "untitled.png";
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    originalPixmap.save(&file, "PNG");
    file.close();
}

void MainWindow::uploadScreenshot()
{
    QString base64String = convertScreenshot();
    QUrlQuery postData = QUrlQuery(base64String);
    QNetworkAccessManager *networkManager = new QNetworkAccessManager(this);
    QNetworkRequest request(imgurURL);

    request.setRawHeader("content-type", "multipart/form-data");
    request.setRawHeader("Authorization", "Client-ID 5c4af49a9b2ebb0");
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    networkManager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
}

void MainWindow::replyFinished(QNetworkReply* reply)
{
    QByteArray buffer = reply->readAll();
    QJsonParseError error;
    QJsonDocument document = QJsonDocument::fromJson(buffer, &error);
    QJsonObject object = document.object();
    QJsonValue dataArray = object["data"];
    QJsonValue link = dataArray["link"];
    QString stringReply =  link.toString();
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(stringReply);
    ui->label->setText(stringReply);
}

QString MainWindow::convertScreenshot()
{
    QString result;
    QByteArray byteArray;
    QFile *file = new QFile(fileName);
    file->open(QIODevice::ReadOnly);
    byteArray = file->readAll();
    result = QString(byteArray.toBase64());
    return result;
}
