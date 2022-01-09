#include "mainwindow.h"
#include<iostream>
#include<iomanip>
#include<conio.h>
#include"Student.h"
#include"Course.h"
#include"Admin.h"
#include"reguexpr.h"

#include <QApplication>

Admin my_admin;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
