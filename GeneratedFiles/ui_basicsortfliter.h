/********************************************************************************
** Form generated from reading UI file 'basicsortfliter.ui'
**
** Created: Fri Jun 7 21:15:25 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICSORTFLITER_H
#define UI_BASICSORTFLITER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BasicSortFliterClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BasicSortFliterClass)
    {
        if (BasicSortFliterClass->objectName().isEmpty())
            BasicSortFliterClass->setObjectName(QString::fromUtf8("BasicSortFliterClass"));
        BasicSortFliterClass->resize(600, 400);
        menuBar = new QMenuBar(BasicSortFliterClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        BasicSortFliterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BasicSortFliterClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BasicSortFliterClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(BasicSortFliterClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        BasicSortFliterClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BasicSortFliterClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BasicSortFliterClass->setStatusBar(statusBar);

        retranslateUi(BasicSortFliterClass);

        QMetaObject::connectSlotsByName(BasicSortFliterClass);
    } // setupUi

    void retranslateUi(QMainWindow *BasicSortFliterClass)
    {
        BasicSortFliterClass->setWindowTitle(QApplication::translate("BasicSortFliterClass", "BasicSortFliter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BasicSortFliterClass: public Ui_BasicSortFliterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICSORTFLITER_H
