#pragma once
#include "base.h"
#include "course.h"
#include <string>
//任选课类，继承课程类

class Electivecourse : public Course, public base
{
private:
	static int number;
public:
	virtual void printinfo()
	{
		Course::printinfo();
	}
	Electivecourse() :Course()
	{
		number++;
	}
	~Electivecourse()
	{
		number--;
	}
	static int getnumber() { return number; }
	int getcredit() { return Course::getcredit(); }
	std::string getname() { return Course::getname(); }

	friend std::istream& operator >> (std::istream& input, Electivecourse& c);
	friend std::ostream& operator <<(std::ostream& output, Electivecourse& c);
};

