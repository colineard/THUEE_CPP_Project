#ifndef GRADES_H
#define GRADES_H
#include "base.h"
#include "course.h"
#include "student.h"
class Student;
class Course;
class Grades :public base  //分数类，包含了某一学生在某一门课中的成绩信息
{
private:
	Student* student;
	Course* course;
	double grades;
	double point;
	int type;//标记该学生在该门课的类型：计算绩点；记pf；记退课
	static int number;
public:
	Grades()
	{
		student = NULL;
		course = NULL;
		grades = 0.0;
		point = 0.0;
		type = 0;
		number++;
	}
	~Grades()
	{
		number--;
	}
	virtual void printinfo();
	void printgrades();
	static int getnumber() { return number; }
	double get_grades()
	{
		return grades;
	}
	double get_point()
	{
		return point;
	}
	const char * get_type()
	{
		switch (type)
		{
		default: return "绩点课";
		case 1:return "pass";
		case 2: return "fail";
		case 3:return "withdraw";
		}
	}
	int get_int_type()
	{
		return type;
	}
	Student* get_student()
	{
		return student;
	}
	Course* get_course()
	{
		return course;
	}
	void set_student(Student* s) {student = s;}
	void set_course(Course* c) {course = c;}
	void set_grades_point(double grades) { 
		this->grades = grades;
		if (grades >= 90.0) point= 4.0;
		else if (grades >= 85.0) point= 3.6;
		else if (grades >= 80.0) point= 3.3;
		else if (grades >= 77.0) point= 3.0;
		else if (grades >= 73.0) point= 2.6;
		else if (grades >= 70.0) point= 2.3;
		else if (grades >= 67.0) point= 2.0;
		else if (grades >= 63.0) point= 1.6;
		else if (grades >= 60.0) point= 1.3;
		else point= 0.0;
	}
	void set_type(int typenumber)
	{ 
		type = typenumber;
		if (typenumber != 0)    //当该门课是记pf或记w时，置成绩和绩点为0
		{
			grades = 0.0;
			point = 0.0;
		}
	}
	friend bool sortbygrades(Grades& a, Grades& b);
	
	friend std::istream& operator >>(std::istream&, Grades&);
	friend std::ostream& operator <<(std::ostream&, Grades&);
};




#endif

