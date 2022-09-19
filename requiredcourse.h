#pragma once
#include "base.h"
#include "course.h"	
#include <string>
//±ØÐÞ¿ÎÀà

class Requiredcourse :public base, public Course
{
private:
	static int number;
public :
	virtual void printinfo()
	{
		Course::printinfo();
	}
	Requiredcourse():Course()
	{
		number++;
	}
	~Requiredcourse()
	{
		number--;
	}
	static int getnumber() { return number; }
	int getcredit() { return Course::getcredit(); }
	std::string getname() { return Course::getname(); }

	friend std::istream& operator >> (std::istream& input, Requiredcourse& c);
	friend std::ostream& operator <<(std::ostream& output, Requiredcourse& c);

};

