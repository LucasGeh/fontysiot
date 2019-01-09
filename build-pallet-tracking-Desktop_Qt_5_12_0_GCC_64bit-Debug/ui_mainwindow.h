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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *findPallet;
    QComboBox *selectPallet;
    QLCDNumber *palletID1;
    QLCDNumber *palletID2;
    QLabel *pallet1Label;
    QLabel *pallet2Label;
    QLabel *palletLocation;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        findPallet = new QPushButton(centralWidget);
        findPallet->setObjectName(QString::fromUtf8("findPallet"));
        findPallet->setGeometry(QRect(110, 50, 89, 25));
        selectPallet = new QComboBox(centralWidget);
        selectPallet->setObjectName(QString::fromUtf8("selectPallet"));
        selectPallet->setGeometry(QRect(20, 50, 86, 25));
        palletID1 = new QLCDNumber(centralWidget);
        palletID1->setObjectName(QString::fromUtf8("palletID1"));
        palletID1->setGeometry(QRect(30, 150, 64, 23));
        palletID2 = new QLCDNumber(centralWidget);
        palletID2->setObjectName(QString::fromUtf8("palletID2"));
        palletID2->setGeometry(QRect(280, 150, 64, 23));
        pallet1Label = new QLabel(centralWidget);
        pallet1Label->setObjectName(QString::fromUtf8("pallet1Label"));
        pallet1Label->setGeometry(QRect(20, 180, 81, 51));
        pallet2Label = new QLabel(centralWidget);
        pallet2Label->setObjectName(QString::fromUtf8("pallet2Label"));
        pallet2Label->setGeometry(QRect(270, 180, 81, 51));
        palletLocation = new QLabel(centralWidget);
        palletLocation->setObjectName(QString::fromUtf8("palletLocation"));
        palletLocation->setGeometry(QRect(210, 50, 151, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
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
        pallet1Label->setText(QApplication::translate("MainWindow", "Inside of \n"
" designated \n"
" area", nullptr));
        pallet2Label->setText(QApplication::translate("MainWindow", "Outside of \n"
" designated \n"
" area", nullptr));
        palletLocation->setText(QApplication::translate("MainWindow", "Pallet location here..", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
