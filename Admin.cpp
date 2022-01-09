#include<string>
#include<iostream>
#include<conio.h>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<QMessageBox>
#include<QString>
#include <QDebug>
#include"Admin.h"

using namespace std;

int Admin::StuCouSco(string num, string s) {
	vector<Student>::iterator it;
	for (it = _students.begin();it != _students.end();it++) {
        if (it->_num == num) break;
	}

	vector<course_condition>::iterator it1;
	for (it1 = it->_courses.begin();it1 != it->_courses.end();it1++) {
        if (it1->_course_num == s) return it1->_score;
	}

	return -1;
}

bool Admin::hasStu(string num) {
    int len = _students.size();
    for (int i = 0; i < len; i++) {
        if (_students[i]._num == num) return true;
    }
	return false;
}

bool Admin::temphasStu(string num) {
	vector<Student>::iterator it;
	for (it = _temp.begin();it != _temp.end();it++) {
        if (num == it->_num || num == it->_name) return true;
	}
	return false;
}

bool Admin::hasCou(string s) {
	int len = _courses.size();
	for (int i = 0; i < len; i++) {
        if (_courses[i]._num == s) return true;
	}
	return false;
}

bool Admin::StuhasCou(string num ,string s) {
	vector<Student>::iterator it;
	for (it = _students.begin();it != _students.end();it++) {
        if (it->_num == num) break;
	}

	vector<course_condition>::iterator it1;
	for (it1 = it->_courses.begin();it1 != it->_courses.end();it1++) {
        if (it1->_course_num == s) return true;
	}

	return false;
}
void Admin::Add_student(string num, string name, string major, int sclass, int nums, vector<course_condition> courses) {
	Student my_student;
	my_student._class = sclass;
	my_student._courses = courses;
	my_student._nums = nums;
	
    my_student._num = num;

    my_student._major = major;

    my_student._name = name;

	_students.push_back(my_student);
}

bool Admin::Add_Cou_Info(string s, int score) {
	int len = _courses.size();
	for (int i = 0; i < len; i++) {
        if (_courses[i]._num == s) {
			_courses[i]._stus++;
			_courses[i]._totalscore += score;
			return true;
		}
	}
	return false;
}

void Admin::Add_Cou(string num, int stus, int totalscore) {
	Course my_course;
    my_course._num = num;

	my_course._stus = stus;
	my_course._totalscore = totalscore;

	_courses.push_back(my_course);
}

void Admin::Delete_student(string num) {
	vector<Student>::iterator it;
	for (it = _students.begin();it != _students.end();it++) { 
        if (it->_num == num) break;
	}

	if (it->_courses.empty() == false) {
		int len = it->_courses.size();
		for (int i = 0; i < len; i++) {
			Reduce_Course_Info(it->_courses[i]._course_num, it->_courses[i]._score);
		}
	}
	_students.erase(it);
}

void Admin::Reduce_Course_Info(string s, int score) {
	vector<Course>::iterator it;
	for (it = _courses.begin(); it != _courses.end(); it++) {
        if (it->_num == s) {
			it->_stus--; it->_totalscore -= score; break;
		}
	}
}

void Admin::Show_Student_Info(string num) {
	vector<Student>::iterator it;
	for (it = _students.begin();it != _students.end();it++) {
        if (it->_num == num) break;
	}

	cout << "学号：" << it->_num << endl;
	cout << "姓名：" << it->_name << endl;
	cout << "院系：" << it->_major << endl;
	cout << "班级：" << it->_class << endl;
	cout << "选修课程数：" << it->_nums << endl;
	if (it->_nums != 0) {
		cout << "选修课程号与成绩：" << endl;
		for (int i = 0; i < it->_nums; i++) {
			cout << it->_courses[i]._course_num << setw(15) << it->_courses[i]._score << endl;
		}
	}
}

void Admin::Modify_Student_Info(string num, int n, string s, int l) {
	vector<Student>::iterator it;
	for (it = _students.begin();it != _students.end();it++) {
        if (it->_num == num) break;
	}

	switch (n) {
	case 1:
        it->_name = s;
		break;
	case 2:
        it->_major = s;
		break;
	case 3:
		it->_class = l;
		break;
	case 4:
        if (StuhasCou(num, s) == true) {
			vector<course_condition>::iterator it1;
			for (it1 = it->_courses.begin();it1 != it->_courses.end();it1++) {
                if (it1->_course_num == s) {
					Add_Cou_Info(s, l);
					Reduce_Course_Info(s, it1->_score);
					it1->_score = l;
					break;
				}
			}
		}
        else {
			course_condition temp;
            temp._course_num = s;
			temp._score = l;
			it->_courses.push_back(temp);
			it->_nums++;
            Add_Cou(s, 1, l);
		}
		break;
	case 5:
		vector<course_condition>::iterator it1;
		for (it1 = it->_courses.begin();it1 != it->_courses.end();it1++) {
            if (it1->_course_num == s) break;
		}
		Reduce_Course_Info(s, it1->_score);
		it->_courses.erase(it1);
		it->_nums--;
		
	}
}

void Admin::Save_Info_to_file(ofstream& pfile1, int n, bool b) {
	vector<Student> out;
	if (n == 0) out = _students;
	else out = _temp;

	vector<Student>::iterator it;
	for (it = out.begin();it != out.end();it++) {
        pfile1 << it->_num << " " << it->_name << " " <<  it->_major << " " << it->_class << " " << it->_nums << endl;
        //fprintf(pfile1, "%s %s %s %d %d\n", it->_num, it->_name, it->_major, it->_class, it->_nums);
        if (b == true) {
			vector<course_condition>::iterator it1;
			for (it1 = it->_courses.begin();it1 != it->_courses.end();it1++) {
                pfile1 << it1->_course_num << " " << it1->_score << endl;
                //fprintf(pfile1, "%s %d\n", it1->_course_num, it1->_score);
			}
		}
	}
}

void Admin::Read_info_from_file(ifstream& pfile1) {
	bool fault = false;
    //while (!feof(pfile1)) {
    while (!pfile1.fail()) {
		fault = false;
		Student temp;
        pfile1 >> temp._num >> temp._name >> temp._major >> temp._class >> temp._nums;
        if (pfile1.fail()) break;
        //fscanf(pfile1, "%s %s %s %d %d\n", temp._num, temp._name, temp._major, &temp._class, &temp._nums);
		if (hasStu(temp._num) == true) {

            string temp1 = "读取学生" + temp._num + "时发现系统中已存在该学生信息，该学生信息读取失败";
            QMessageBox::about(NULL,"错误", QString::fromStdString(temp1));
            fault = true;
		}
		if (temp._nums != 0) {
			for (int i = 0; i < temp._nums; i++) {
				course_condition t;
                pfile1 >> t._course_num >> t._score;

                //fscanf(pfile1, "%s %d\n", t._course_num, &t._score);
                if (fault == false) {
					vector<course_condition>::iterator it;
					for (it = temp._courses.begin();it != temp._courses.end();it++) { //检测是否重复
                        //qDebug() << "3" << endl;
                        if (it->_course_num == t._course_num) {
							fault = true;

                            string temp1 = "读取学生" + temp._num + "时发现存在重复课程，该学生信息读取失败";
                            QMessageBox::about(NULL,"错误", QString::fromStdString(temp1));
                            break;
						}
					}
				}
				temp._courses.push_back(t);
			}
		}
        //qDebug() << "1" << fault << endl;
		if (fault == false) {
			_students.push_back(temp); //不出错则读入并更新相应信息
			vector<course_condition>::iterator it;
			for (it = temp._courses.begin();it != temp._courses.end();it++) { 
				if (hasCou(it->_course_num) == true) {
					Add_Cou_Info(it->_course_num, it->_score);
				}
                else Add_Cou(it->_course_num, 1, it->_score);
			}
		}
	}
}

void Admin::Show_Info(int n, string s, int l, bool b1) {
	if (n == 1) {
		vector<Student>::iterator it;
		for (it = _students.begin();it != _students.end();it++) {
			if (StuhasCou(it->_num, s) == true) _temp.push_back(*it);
		}

		vector<Course>::iterator it1;
		for (it1 = _courses.begin(); it1 != _courses.end(); it1++) {
            if (it1->_num == s) break;
		}
		cout << "课程编号：" << s << endl;

		cout << "修读人数：" << it1->_stus << endl;
		cout << "平均分：" << it1->get_avg_score() << endl;

		if (_temp.size() == 0 || it1->_stus == 0) b1 = false;
	}
	else if (n == 2) {
		vector<Student>::iterator it;
		for (it = _students.begin();it != _students.end();it++) {
            if (it->_major == s) _temp.push_back(*it);
		}
		if (_temp.empty() == true) {
			cout << "不存在该院系的学生！" << endl;
			b1 = false;
			return;
		}
		else
		{
			cout << "院系名：" << s << endl;
			cout << "学生数量：" << _temp.size() << endl;
		}
	}
	else if (n == 3) {
		vector<Student>::iterator it;
		for (it = _students.begin();it != _students.end();it++) {
			if (it->_class == l) _temp.push_back(*it);
		}
		if (_temp.empty() == true) {
			cout << "不存在该班级的学生！" << endl;
			b1 = false;
			return;
		}
		else
		{
			cout << "班级：" << l << endl;
			cout << "学生数量：" << _temp.size() << endl;
		}
	}


	if (b1 == true && n == 1)
	{
		cout << "具体学生名单：" << endl;
		cout << setw(20) << "学号" << setw(20) << "姓名" << setw(20) << "院系" << setw(10) << "班级" << setw(15) << "已选课程数" << setw(15) << "当前课程成绩" << endl;
		vector<Student>::iterator it;
		for (it = _temp.begin();it != _temp.end();it++) {
			cout << setw(20) << it->_num << setw(20) << it->_name << setw(20) << it->_major << setw(10) << it->_class << setw(15) << it->_nums << setw(15) << StuCouSco(it->_num, s) << endl;
		}
	}
	else if (b1 == true)
	{
		cout << "具体学生名单：" << endl;
		print_temp();
	}

	cleartemp();
}

void Admin::print_temp() {
	if (_temp.empty() == false) {
		cout << "匹配到的学生信息：" << endl;
		cout << setw(20) << "学号" << setw(20) << "姓名" << setw(20) << "院系" << setw(10) << "班级" << setw(15) << "已选课程数" << endl;
		vector<Student>::iterator it;
		for (it = _temp.begin();it != _temp.end();it++) {
			cout << setw(20) << it->_num << setw(20) << it->_name << setw(20) << it->_major << setw(10) << it->_class << setw(15) << it->_nums << endl;
		}
	}
	else {
		cout << "未能匹配到与条件相符的学生信息！" << endl;
	}
}

void Admin::Vague_Search(string expr, int& ret) {
	reguexpr my_regu(expr, ret);
    if (ret == -1) {
        QMessageBox::about(NULL,"错误", "输入的表达式有误");
        return;
    }

	vector<Student>::iterator it;
	for (it = _students.begin();it != _students.end();it++) { //检查是否匹配
		if (my_regu.match(it->_num) == true || my_regu.match(it->_name) == true) _temp.push_back(*it);
	}

    //print_temp();

    //cleartemp();
}

void Admin::Advanced_Search(string s, int n, int l, bool isand, bool isequal, bool first) {
	bool b1 = false;
	if (first == true) { //第一次
		if (n >= 1 && n <= 4) {
			int ret = 0;
			reguexpr my_regu(s, ret);
			vector<Student>::iterator it;
			for (it = _students.begin();it != _students.end();it++) { //检查是否匹配
				switch (n)
				{
				case 1: //学号
					if ((my_regu.match(it->_num) ^ isequal) == 0) _temp.push_back(*it);
					break;
				case 2: //姓名
					if ((my_regu.match(it->_name) ^ isequal) == 0) _temp.push_back(*it);
					break;
				case 3: //院系
					if ((my_regu.match(it->_major) ^ isequal) == 0) _temp.push_back(*it);
					break;
				case 4: //选课
					vector<course_condition>::iterator it1;
					for (it1 = it->_courses.begin();it1 != it->_courses.end();it1++) {
						if (my_regu.match(it1->_course_num) == true) {
							b1 = true;
							break;
						}
					}
					if ((b1 ^ isequal) == 0) _temp.push_back(*it);
					b1 = false;
					break;
				}
			}
		}
		else { //n == 5 班级
			vector<Student>::iterator it;
			for (it = _students.begin();it != _students.end();it++) {
				if (((it->_class == l) ^ isequal) == 0) _temp.push_back(*it);
			}
		}
	}
	else { //不是第一次
		if (isand == false) { //或
			if (n >= 1 && n <= 4) {
				int ret = 0;
				reguexpr my_regu(s, ret);
				vector<Student>::iterator it;
				for (it = _students.begin();it != _students.end();it++) { //检查是否匹配
					switch (n)
					{
					case 1: //学号
						if ((my_regu.match(it->_num) ^ isequal) == 0 && temphasStu(it->_num) == false) _temp.push_back(*it);
						break;
					case 2: //姓名
						if ((my_regu.match(it->_name) ^ isequal) == 0 && temphasStu(it->_num) == false) _temp.push_back(*it);
						break;
					case 3: //院系
						if ((my_regu.match(it->_major) ^ isequal) == 0 && temphasStu(it->_num) == false) _temp.push_back(*it);
						break;
					case 4: //选课
						vector<course_condition>::iterator it1;

						for (it1 = it->_courses.begin();it1 != it->_courses.end();it1++) {
							//if ((my_regu.match(it1->_course_num) ^ isequal) == 0 && temphasStu(it->_num) == false) {
							if (my_regu.match(it1->_course_num) == true){
								b1 = true;
								break;
							}
						}
						if ((b1 ^ isequal) == 0 && temphasStu(it->_num) == false) _temp.push_back(*it);
						b1 = false;
						break;
					}
				}
			}
			else { //n == 5 班级
				vector<Student>::iterator it;
				for (it = _students.begin();it != _students.end();it++) {
					if (((it->_class == l) ^ isequal) == 0 && temphasStu(it->_num) == false) _temp.push_back(*it);
				}
			}
		}
		else { //与
			if (n >= 1 && n <= 4) {
				int ret = 0;
				reguexpr my_regu(s, ret);
				vector<Student>::iterator it;
				it = _temp.begin();
				while (it != _temp.end()) { //检查是否匹配
					switch (n)
					{
					case 1: //学号
						if ((my_regu.match(it->_num) ^ isequal) == 1) {
							it = _temp.erase(it);
							continue;
						}
						break;
					case 2: //姓名
						if ((my_regu.match(it->_name) ^ isequal) == 1) {
							it = _temp.erase(it);
							continue;
						}
						break;
					case 3: //院系
						if ((my_regu.match(it->_major) ^ isequal) == 1) {
							it = _temp.erase(it);
							continue;
						}
						break;
					case 4: //选课
						vector<course_condition>::iterator it1;
						
						for (it1 = it->_courses.begin();it1 != it->_courses.end();it1++) {
							if (my_regu.match(it1->_course_num) == true) {
								b1 = true;
								break;
							}
						}
						if ((b1 ^ isequal) == 1) {
							it = _temp.erase(it);
							continue;
						}
						b1 = false;
						break;
					}
					it++;
				}
			}
			else { //n == 5 班级
				vector<Student>::iterator it;
				it = _temp.begin();
				while (it != _temp.end()) {
					if (((it->_class == l) ^ isequal) == 1) {
						it = _temp.erase(it);
						continue;
					}
					it++;
				}
			}
		}
	}

}

