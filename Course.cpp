#define _CRT_SECURE_NO_WARNINGS
#include"Course.h"
#include<cstring>

using namespace std;
Course::Course(string num, int stus, int totalscore) {
    _num = num;

	_stus = stus;
	_totalscore = totalscore;
};

double Course::get_avg_score() {
	if (_stus != 0) return (double)_totalscore / _stus;
	else return 0;
}
