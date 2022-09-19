#ifndef COURSES_OF_STUDENT_H
#define COURSES_OF_STUDENT_H
#include <string>
#include <vector>
#include "course.h"
#include "grades.h"
#include "base.h"
class Student;
class Grades;
class Course;
class Courses_of_student :public base
{
private:
	Student* student;//��¼��Щ�ɼ���˭��
	std::vector <Grades> courses;
	int coursenumber;
	int sum_credit;//��ѧ��
	double GPA;//�ܼ���
public:
	Courses_of_student()
	{
		coursenumber = 0;
		sum_credit = 0;
		GPA = 0.0;
		student = NULL;
	}
	void pushback(Grades &);//����ѧ���Ŀγ̳ɼ�����������
	void calculate();//���ݿγ̳ɼ�������ѧ�ֺ��ܼ���
	virtual void printinfo();
	void printcourses();
	bool removecourse(int);
	bool change_course_grades(int,double);
	void set_student(Student* student)
	{
		this->student = student;
	}
	int get_courses(Course*);
	int get_coursenumber() { return coursenumber; }
	int get_sum_credit() { return sum_credit; }
	double get_GPA() { return GPA; }
};

#endif

