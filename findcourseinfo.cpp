#include "findcourseinfo.h"
#include "ui_findcourseinfo.h"
#include "Admin.h"
#include"Student.h"
#include <QButtonGroup>
#include<iostream>
#include<fstream>
#include<string>
#include <QHeaderView>
#include <QStandardItemModel>
#include<QMessageBox>
#include<QDebug>
#include<QString>

using namespace std;

extern Admin my_admin;

FindCourseInfo::FindCourseInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FindCourseInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("查找学生选课信息");

    model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"课程号", "分数"});
    ui->tableView->setModel(model);
}

FindCourseInfo::~FindCourseInfo()
{
    delete ui;
}

void FindCourseInfo::on_actionquit_triggered()
{
    close();
}

void FindCourseInfo::on_pushButton_clicked()
{
    string num = ui->lineEdit->text().toStdString();

    if (my_admin.hasStu(num) == false){
        QMessageBox::about(NULL,"错误", "要查找的学号不存在");
        return;
    }

    model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"课程号", "分数"});

    int len = my_admin._students.size();
    int i;
    for (i = 0; i < len; i++) {
        if (my_admin._students[i]._num == num) break;
    }
    len = my_admin._students[i]._courses.size();
    if (len == 0){
        QMessageBox::about(NULL,"提示", "该学生没有选修课程的记录");
    }
    else {
        model = new QStandardItemModel();
        model->setHorizontalHeaderLabels({"课程号", "分数"});
        for (int j = 0; j < len; j++){
            model->setItem(j, 0, new QStandardItem(QString::fromStdString(my_admin._students[i]._courses[j]._course_num)));
            model->setItem(j, 1, new QStandardItem(QString::fromStdString(to_string(my_admin._students[i]._courses[j]._score))));
        }
        ui->tableView->setModel(model);
    }
}
