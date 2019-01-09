#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

void getAvailableTrackers();
void getDataForDevice(QString deviceID);
bool isInArea(int trackerLat, int trackerLon, int checkLat1,int checkLon1,int checkLat2,int checkLon2);

private slots:
    void setAvailableTrackers();
    void setLocationLabel();
    void on_findPallet_clicked();
    void on_checkLocationButton_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply *reply;
};

#endif // MAINWINDOW_H
