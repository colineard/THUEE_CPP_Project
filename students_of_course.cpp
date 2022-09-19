#include <iostream>
#include "students_of_course.h"
#include <iomanip>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
void Students_of_course::pushback(Grades& g)
{
	students.push_back(g);
	studentnumber++;
}
bool Students_of_course::removestudent(int choice)
{
	int i;
	vector<Grades>::iterator it = students.begin();
	for (it = students.begin(),i=0; it < students.end(); it++,i++)
	{
		if (i== choice)
			break;
	}
	if (it != students.end())
	{
		students.erase(it);
		studentnumber--;
		return true;
	}
	else
	{
		return false;
	}
}
bool Students_of_course::changegrades(int choice, double grades)
{
	int i = 0;
	vector<Grades>::iterator it = students.begin();
	for (it = students.begin(),i=0; it < students.end(); it++,i++)
	{
		if (i==choice)
			break;
	}
	if (it != students.end())
	{
		it->set_grades_point(grades);
		
		return 1;
	}
	else return 0;
}
void Students_of_course::calculate()
{
	double sum_grades = 0;
	for (int i = 0; i < students.size(); i++)
	{
		sum_grades += students[i].get_grades();
	}
	if(studentnumber!=0)
	averagegrades = sum_grades / studentnumber;
}
void Students_of_course::printinfo()
{
	course->printinfo();
	cout << "┌────────────────────────────────────────────────┐" << endl;
	for (int i = 0; i < students.size(); i++)
	{
		cout << i + 1 << ".  ";
		students[i].printinfo();
	}
	cout << "└────────────────────────────────────────────────┘" << endl;
	cout << "averagegrades:" << setw(6) << averagegrades << endl;

}
bool sortbygrades(Grades& a, Grades& b)
{
	{
		if (a.get_grades() > b.get_grades())
			return 1;
		else return 0;
	}
}
int Students_of_course:: get_students(Student* s)
{
	for (int k = 0; k < students.size(); k++)
	{
		if (students[k].get_student() == s)
			return k;
	}
	return -1;   //如果没有找到该学生，就返回-1
}
void Students_of_course::sortstudent()
{
	sort(students.begin(), students.end(), sortbygrades);
}
bool Students_of_course::findstudent(char * target_id)
{
	vector<Grades>::iterator it = students.begin();
	for (it = students.begin(); it < students.end(); it++)
	{
		if (strcmp(it->get_student()->getid(), target_id) == 0)
			break;
	}
	if (it != students.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}