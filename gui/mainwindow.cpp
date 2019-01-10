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

    foreach(QJsonValue s,deviceArray){
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
    request.setUrl(QUrl(apiHost+QString("query/")+deviceID+QString("?last=7d")));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setRawHeader("Authorization",apiKey);
    reply=manager->get(request);
    connect(reply, SIGNAL(readyRead()), this, SLOT(setLocationLabel()));
}

void MainWindow::setLocationLabel(){
    QByteArray response_data = reply->readAll();
    QJsonDocument json=QJsonDocument::fromJson(response_data);
    QJsonArray locationArray=json.array();
    QJsonValue latestLocation = locationArray.last();

    QJsonObject loc= latestLocation.toObject();
    QJsonValue latestLon = loc.value("lon");
    QJsonValue latestLat = loc.value("lat");
    QTableWidgetItem *lon=new QTableWidgetItem(latestLon.toString());
    QTableWidgetItem *lat=new QTableWidgetItem(latestLat.toString());
    ui->tableWidget->setItem(0,0,lat);
    ui->tableWidget->setItem(0,1,lon);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::on_checkLocationButton_clicked()
{
    int checkLat1 = ui->locationOne->text().toInt();
    int checkLon1 = ui->locationTwo->text().toInt();
    int checkLat2 = ui->locationThree->text().toInt();
    int checkLon2 = ui->locationFour->text().toInt();
    QString trackerLat=ui->tableWidget->item(0,0)->text();
    QString trackerLon=ui->tableWidget->item(0,1)->text();
    if(trackerLat.contains("none") || trackerLon.contains("none")){
        ui->isInArea->setText("No");
    }else{
        int trackLat=trackerLat.toInt();
        int trackLon=trackerLon.toInt();
        if(isInArea(trackLat,trackLon,checkLat1,checkLon1,checkLat2,checkLon2)){
            ui->isInArea->setText("Yes");
        }else{
            ui->isInArea->setText("No");
        }
    }
}

bool MainWindow::isInArea(int trackerLat, int trackerLon, int checkLat1,int checkLon1,int checkLat2,int checkLon2){
    if(trackerLat!=NULL && trackerLon!=NULL && checkLat1!=NULL && checkLon1!=NULL && checkLon2!=NULL){
        qDebug() << trackerLat;
        qDebug() << trackerLon;
        qDebug() << checkLat1;
        qDebug() << checkLon1;
        qDebug() << checkLat2;
        qDebug() << checkLon2;
        if(checkLat1>=checkLat2){
            if(checkLon1>=checkLon2){
                return checkLat2<=trackerLat && trackerLat<=checkLat1 && checkLon2<=trackerLon && trackerLon<=checkLon1;
             }else{
                return checkLat2<=trackerLat && trackerLat<=checkLat1 && checkLon1<=trackerLon && trackerLon<=checkLon2;
            }
        }
        else{
            if(checkLon1>checkLon2){
                return checkLat1<=trackerLat && trackerLat<=checkLat2 && checkLon2<=trackerLon && trackerLon<=checkLon1;
            }else{
                return checkLat1<=trackerLat && trackerLat<=checkLat2 && checkLon1<=trackerLon && trackerLon<=checkLon2;
            }
        }
    }
    return false;
}
