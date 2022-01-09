/********************************************************************************
** Form generated from reading UI file 'findcourseinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDCOURSEINFO_H
#define UI_FINDCOURSEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindCourseInfo
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FindCourseInfo)
    {
        if (FindCourseInfo->objectName().isEmpty())
            FindCourseInfo->setObjectName(QString::fromUtf8("FindCourseInfo"));
        FindCourseInfo->resize(341, 477);
        actionquit = new QAction(FindCourseInfo);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralwidget = new QWidget(FindCourseInfo);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 90, 321, 341));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 171, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 40, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 72, 15));
        FindCourseInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FindCourseInfo);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 341, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        FindCourseInfo->setMenuBar(menubar);
        statusbar = new QStatusBar(FindCourseInfo);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FindCourseInfo->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(FindCourseInfo);

        QMetaObject::connectSlotsByName(FindCourseInfo);
    } // setupUi

    void retranslateUi(QMainWindow *FindCourseInfo)
    {
        FindCourseInfo->setWindowTitle(QCoreApplication::translate("FindCourseInfo", "MainWindow", nullptr));
        actionquit->setText(QCoreApplication::translate("FindCourseInfo", "\351\200\200\345\207\272", nullptr));
        pushButton->setText(QCoreApplication::translate("FindCourseInfo", "\346\237\245\350\257\242", nullptr));
        label->setText(QCoreApplication::translate("FindCourseInfo", "\345\255\246\345\217\267", nullptr));
        menu->setTitle(QCoreApplication::translate("FindCourseInfo", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindCourseInfo: public Ui_FindCourseInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDCOURSEINFO_H
