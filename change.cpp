#include "change.h"
#include "ui_change.h"
#include"Admin.h"
#include<QMessageBox>

using namespace std;

extern Admin my_admin;

change::change(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
    this->setWindowTitle("修改学生信息");
}

change::~change()
{
    delete ui;
}

void change::on_actionquit_triggered()
{
    close();
}

void change::on_pushButton_clicked()
{
    string num = ui->lineEditNum->text().toStdString();
    if (my_admin.hasStu(num) == false){
        QMessageBox::about(NULL,"错误", "要修改的学号不存在");
        return;
    }

    int index = ui->comboBox->currentIndex() + 1;//1 name 2 major 3 class 4 add 5 del
    if (ui->radioButtonDel->isChecked() && index == 4) index++;
    else if (!ui->radioButtonAdd->isChecked() && index == 4){
        QMessageBox::about(NULL,"错误", "请选择对选课信息修改的模式");
        return;
    }

    string s;
    int l = 0;
    s = ui->lineEditT->text().toStdString();
    if (index <= 3){
        if (index == 3) l = atoi(ui->lineEditT->text().toStdString().c_str());
        my_admin.Modify_Student_Info(num, index, s, l);
    }
    else{
        if (index == 4) l = atoi(ui->lineEditScore->text().toStdString().c_str());
        if (index == 5 && my_admin.StuhasCou(num, s) == false){
            QMessageBox::about(NULL,"错误", "要删除的课程不在该学生选课列表中");
            return;
        }
        my_admin.Modify_Student_Info(num, index, s, l);
    }
    QMessageBox::about(NULL,"提示", "修改成功");
}
