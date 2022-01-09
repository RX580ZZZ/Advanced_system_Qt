#pragma once
#include<string>
using namespace std;
class Course {
private:
    string _num; //课程编号
	int _stus; //学生数
	int _totalscore; //当前所有学生获得的总分
public:
    Course(string num, int stus, int totalscore);
    Course() {_stus = 0; _totalscore = 0; };
	double get_avg_score(); //得到平均分
	friend class Admin;
    friend class add;
    friend class Information;
};
