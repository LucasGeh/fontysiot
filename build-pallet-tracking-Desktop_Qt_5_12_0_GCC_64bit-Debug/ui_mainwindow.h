/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *findPallet;
    QComboBox *selectPallet;
    QTableWidget *tableWidget;
    QLineEdit *locationOne;
    QLineEdit *locationTwo;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *locationFour;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *locationThree;
    QLabel *label_5;
    QPushButton *checkLocationButton;
    QLabel *isInArea;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(595, 419);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        findPallet = new QPushButton(centralWidget);
        findPallet->setObjectName(QString::fromUtf8("findPallet"));
        findPallet->setGeometry(QRect(110, 50, 89, 25));
        selectPallet = new QComboBox(centralWidget);
        selectPallet->setObjectName(QString::fromUtf8("selectPallet"));
        selectPallet->setGeometry(QRect(20, 50, 86, 25));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(220, 30, 211, 61));
        locationOne = new QLineEdit(centralWidget);
        locationOne->setObjectName(QString::fromUtf8("locationOne"));
        locationOne->setGeometry(QRect(110, 210, 113, 23));
        locationTwo = new QLineEdit(centralWidget);
        locationTwo->setObjectName(QString::fromUtf8("locationTwo"));
        locationTwo->setGeometry(QRect(110, 240, 113, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 210, 59, 15));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 240, 71, 16));
        locationFour = new QLineEdit(centralWidget);
        locationFour->setObjectName(QString::fromUtf8("locationFour"));
        locationFour->setGeometry(QRect(110, 320, 113, 23));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 290, 59, 15));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 320, 71, 16));
        locationThree = new QLineEdit(centralWidget);
        locationThree->setObjectName(QString::fromUtf8("locationThree"));
        locationThree->setGeometry(QRect(110, 290, 113, 23));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 149, 411, 51));
        checkLocationButton = new QPushButton(centralWidget);
        checkLocationButton->setObjectName(QString::fromUtf8("checkLocationButton"));
        checkLocationButton->setGeometry(QRect(230, 270, 80, 23));
        isInArea = new QLabel(centralWidget);
        isInArea->setObjectName(QString::fromUtf8("isInArea"));
        isInArea->setGeometry(QRect(350, 270, 59, 15));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 595, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        findPallet->setText(QApplication::translate("MainWindow", "Find Pallet", nullptr));
        label->setText(QApplication::translate("MainWindow", "Latitude 1", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Longitude 1", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Latitude 2", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Longitude 2", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Is selected pallet in areadefined below.\n"
"WARNING: If any of the fields are not set, the program WILL crash!\n"
"WARNING: If no location is set in table above, program WILL crash!", nullptr));
        checkLocationButton->setText(QApplication::translate("MainWindow", "Check", nullptr));
        isInArea->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
