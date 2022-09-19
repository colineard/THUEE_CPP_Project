#pragma once
#include "base.h"
#include <string>
#include "student.h"
class Student;
class Student_
{
private:
	Student* student;
public:
	Student_()
	{
		student = NULL;
	}
	friend bool comp_by_gpa(Student_& a, Student_& b);
	friend bool comp_by_id(Student_& a, Student_& b);
	Student* getstudent()
	{
		return student;
	}
	void setstudent(Student* s)
	{
		student = s;
	}
};

