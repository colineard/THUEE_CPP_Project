#pragma once
#include "base.h"
#include <vector>
#include "student.h"
class Course;
class Grades;
class Student;
class Students_of_course :public base
{
private:
	Course* course;
	std::vector<Grades> students;
	int studentnumber;
	double averagegrades;
public:
	Students_of_course()
	{
		studentnumber = 0;
		averagegrades = 0;
		course = NULL;
	}
	void set_course(Course* c)
	{
		course = c;
	}
	int get_students(Student* s);
	void pushback(Grades&);
	void calculate();
	double get_averagegrades() { return averagegrades; }
	int get_studentnumber() { return studentnumber; }
	void printinfo();
	void sortstudent();
	bool findstudent(char *);
	bool removestudent(int);
	bool changegrades(int choice, double grades);

};

