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

private slots:
    void setAvailableTrackers();
    void setLocationLabel();
    void on_findPallet_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QNetworkReply *reply;
};

#endif // MAINWINDOW_H
