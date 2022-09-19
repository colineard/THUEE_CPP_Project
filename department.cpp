#include <iostream>
#include "department.h"
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
int Department::number = 0;
Department::Department()
{
	number++;
}
Department::~Department()
{
	number--;
}
void Department::printinfo()
{
	//cout << "department:";
	
	cout << left<<setw(30)<<name ;
	cout << "学生数量：" << studentnumber << endl;
}
void Department::pushback(Student_& s)
{
	students.push_back(s);
	studentnumber++;
}
bool comp_by_gpa(Student_& a, Student_& b);
bool comp_by_id(Student_& a, Student_& b);
void Department::sort_student_by_id()
{
	
	sort(students.begin(), students.end(), comp_by_id);
}
void Department::sort_student_by_GPA()
{
	
	sort(students.begin(), students.end(), comp_by_gpa);
}
void Department::print_student()
{
	for (int i = 0; i < students.size(); i++)
	{
		cout << setw(14) << students[i].getstudent()->getid() << setw(12) << students[i].getstudent()->getname();
		cout<< setw(12) << students[i].getstudent()->getcourses()->get_GPA() << endl;
	}
}
istream& operator>>(istream& input, Department& d)
{
	input >> d.name;
	return input;
}
ostream& operator<<(ostream& output, Department& d)
{
	output << d.name << endl;
	return output;
}