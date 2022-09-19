#include <iostream>
#include "grades.h"
#include <iomanip>
using namespace std;
int Grades::number = 0;
void Grades::printinfo()
{
	cout << setiosflags(ios::left);
	cout << setw(15) << student->getid();
	cout << setw(20) << student->getname();
	cout << setw(20) << course->getname();
	cout << setw(10) << get_type();
	cout << grades << endl;
}
void Grades::printgrades()
{
	cout << setiosflags(ios::left);
	if (point != 0)
	{
		cout << setw(25) << course->getname() << setw(10) << course->getcredit();
		cout << setw(10) << grades << setw(10) << point << endl;
	}
	else
	{
		cout << setw(25) << course->getname() << setw(10) << course->getcredit();
		cout << setw(10) << grades << setw(10) << get_type() << endl;
	}
}
istream& operator>>(istream& input, Grades& g)
{
	cout << "ÊäÈë³É¼¨£º" << endl;
	double GRADES;
	input >> GRADES;
	g.set_grades_point(GRADES);
	return input;
}
ostream& operator <<(ostream& output, Grades& g)
{
	output << "student:";
	output << setw(10) << g.student->getname();
	output << "course:";
	output << setw(10) << g.course->getname();
	output << setw(10) << g.type;
	output << "grades:";
	output << g.grades;
	return output;
}

