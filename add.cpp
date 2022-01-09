#include "add.h"
#include "ui_add.h"
#include<string>

add::add(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);

    this->setWindowTitle("添加学生信息");
    left = 0;
}

add::~add()
{
    delete ui;
}

void add::on_pushButtonClose_clicked()
{
    close();
}

void add::on_pushButtonFinish_clicked()
{
    num = ui->lineEditNum->text().toStdString();
    if (my_admin.hasStu(num) == true){
        QMessageBox::about(NULL,"错误", "要添加的学号已存在");
        return;
    }

    name = ui->lineEditName->text().toStdString();
    major = ui->lineEditMajor->text().toStdString();
    classnum = atoi(ui->lineEditClass->text().toStdString().c_str());
    nums = atoi(ui->lineEditNums->text().toStdString().c_str());

    if (nums > 0){
        left = nums;
        string temp = "请在旁边的课程信息区输入学生选修课程及成绩，共" + to_string(left) + "次";
        QMessageBox::about(NULL,"提示", QString::fromStdString(temp));
    }
    else{
        cd.clear();
        my_admin.Add_student(num, name, major, classnum, nums, cd);
        QMessageBox::about(NULL,"提示", "添加成功");
    }
}

void add::on_actionquit_triggered()
{
    if (left != 0){
        QMessageBox:: StandardButton result= QMessageBox::warning(NULL, "警告", "尚有课程信息未录入完，确认要退出吗",QMessageBox::Yes|QMessageBox::No);
        if (result == QMessageBox::Yes) close();
    }
    else {
        close();
    }
}

void add::on_pushButtonConfirm_clicked()
{
    if (left == 0){
        QMessageBox::about(NULL,"提示", "当前没有需要输入的学生选课信息");
        return;
    }

    string cnum = ui->lineEditCnum->text().toStdString();
    vector<course_condition>::iterator it;
    for (it = cd.begin(); it != cd.end(); it++){
        if (cnum == (*it)._course_num) {
            QMessageBox::about(NULL,"错误", "该课程已被添加入学生选课信息");
            return;
        }
    }

    int score = atoi(ui->lineEditScore->text().toStdString().c_str());
    course_condition temp;
    temp._score = score; temp._course_num = cnum;
    cd.push_back(temp);
    left--;
    if (left == 0){
        my_admin.Add_student(num, name, major, classnum, nums, cd);
        for (it = cd.begin(); it != cd.end(); it++){
            if (my_admin.hasCou((*it)._course_num) == true) {
                my_admin.Add_Cou_Info((*it)._course_num, (*it)._score);
            }
            else {
                my_admin.Add_Cou((*it)._course_num, 1, (*it)._score);
            }
        }

        QMessageBox::about(NULL,"提示", "添加成功");
    }
    else {
        string temp = "还需输入" + to_string(left) + "次选课信息";
        QMessageBox::about(NULL,"提示", QString::fromStdString(temp));
    }
}
