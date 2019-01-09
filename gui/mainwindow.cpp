#include "mainwindow.h"
#include "ui_mainwindow.h"

QString apiHost="https://pytrackpallettracker.data.thethingsnetwork.org/api/v2/";
const char* apiKey="key ttn-account-v2.RyirGD384KbG2Z8Pa9cXQvelvnkwdZyXWaNaf0XLMqs";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        ui->tableWidget->setRowCount(1);
        ui->tableWidget->setColumnCount(2);
        QStringList headers=QStringList("Latitude");
        headers.append("Longitude");
        ui->tableWidget->setHorizontalHeaderLabels(headers);

        manager = new QNetworkAccessManager(this);

        getAvailableTrackers();
    }

void MainWindow::getAvailableTrackers(){
    request.setUrl(QUrl(apiHost+QString("devices")));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setRawHeader("Authorization",apiKey);
    reply=manager->get(request);
    connect(reply, SIGNAL(readyRead()), this, SLOT(setAvailableTrackers()));
}

void MainWindow::setAvailableTrackers(){
    QByteArray response_data = reply->readAll();
    QJsonDocument json=QJsonDocument::fromJson(response_data);
    QJsonArray deviceArray=json.array();

    qDebug() << response_data;

    QString test ="";
    foreach(QJsonValue s,deviceArray){
        qDebug() << s.toString();
        test+=s.toString()+"\n";
        ui->selectPallet->addItem(s.toString());
    }

    reply->deleteLater();
}

void MainWindow::on_findPallet_clicked()
{
    QString selectedPallet=ui->selectPallet->currentText();
    getDataForDevice(selectedPallet);
}

void MainWindow::getDataForDevice(QString deviceID){
    request.setUrl(QUrl(apiHost+QString("/query/")+deviceID));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setRawHeader("Authorization",apiKey);
    reply=manager->get(request);
    connect(reply,SIGNAL(readyRead()),this,SLOT(setLocationLabel()));
}

void MainWindow::setLocationLabel(){
    QByteArray response_data = reply->readAll();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}
