/********************************************************************************
** Form generated from reading UI file 'opengldemo.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLDEMO_H
#define UI_OPENGLDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "FileTextBox.h"
#include "MyGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OpenGLdemoClass
{
public:
    QWidget *centralWidget;
    MyGLWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    FileTextBox *lineEdit;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OpenGLdemoClass)
    {
        if (OpenGLdemoClass->objectName().isEmpty())
            OpenGLdemoClass->setObjectName(QStringLiteral("OpenGLdemoClass"));
        OpenGLdemoClass->resize(688, 621);
        centralWidget = new QWidget(OpenGLdemoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new MyGLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(100, 10, 561, 461));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(580, 480, 81, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 480, 81, 41));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(200, 480, 81, 41));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(480, 480, 81, 41));
        lineEdit = new FileTextBox(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(290, 480, 181, 20));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(290, 500, 181, 23));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 100, 81, 81));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 10, 81, 81));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 300, 46, 13));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 320, 81, 23));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(10, 410, 81, 23));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 350, 21, 51));
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(70, 350, 21, 51));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(40, 350, 21, 23));
        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(40, 380, 21, 23));
        OpenGLdemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OpenGLdemoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 21));
        OpenGLdemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OpenGLdemoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OpenGLdemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OpenGLdemoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OpenGLdemoClass->setStatusBar(statusBar);

        retranslateUi(OpenGLdemoClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(left()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), widget, SLOT(up()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), widget, SLOT(down()));
        QObject::connect(pushButton, SIGNAL(clicked()), widget, SLOT(right()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), widget, SLOT(zoomIn()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), widget, SLOT(zoomOut()));
        QObject::connect(lineEdit, SIGNAL(sendFilename(string)), widget, SLOT(load(string)));
        QObject::connect(pushButton_5, SIGNAL(clicked()), lineEdit, SLOT(buttonInput()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), widget, SLOT(lightZMinus()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), widget, SLOT(lightXPlus()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), widget, SLOT(lightXMinus()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), widget, SLOT(lightUp()));
        QObject::connect(pushButton_13, SIGNAL(clicked()), widget, SLOT(lightDown()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), widget, SLOT(lightZPlus()));

        QMetaObject::connectSlotsByName(OpenGLdemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenGLdemoClass)
    {
        OpenGLdemoClass->setWindowTitle(QApplication::translate("OpenGLdemoClass", "OpenGLdemo", 0));
        pushButton->setText(QApplication::translate("OpenGLdemoClass", "->", 0));
        pushButton_2->setText(QApplication::translate("OpenGLdemoClass", "<-", 0));
        pushButton_3->setText(QApplication::translate("OpenGLdemoClass", "Up", 0));
        pushButton_4->setText(QApplication::translate("OpenGLdemoClass", "Down", 0));
        lineEdit->setText(QApplication::translate("OpenGLdemoClass", "Extrusion1.dat", 0));
        pushButton_5->setText(QApplication::translate("OpenGLdemoClass", "Load Config", 0));
        pushButton_7->setText(QApplication::translate("OpenGLdemoClass", "-", 0));
        pushButton_8->setText(QApplication::translate("OpenGLdemoClass", "+", 0));
        label->setText(QApplication::translate("OpenGLdemoClass", "Light", 0));
        pushButton_6->setText(QApplication::translate("OpenGLdemoClass", "-z", 0));
        pushButton_9->setText(QApplication::translate("OpenGLdemoClass", "+z", 0));
        pushButton_10->setText(QApplication::translate("OpenGLdemoClass", "-x", 0));
        pushButton_11->setText(QApplication::translate("OpenGLdemoClass", "+x", 0));
        pushButton_12->setText(QApplication::translate("OpenGLdemoClass", "+y", 0));
        pushButton_13->setText(QApplication::translate("OpenGLdemoClass", "-y", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenGLdemoClass: public Ui_OpenGLdemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLDEMO_H
