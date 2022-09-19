#include <iostream>
#include <iomanip>
#include "course.h"
using namespace std;
int Course::number = 0;
Course::Course()
{
	number++;
	credit = 0;
	students = NULL;
}
Course::Course(string name, int credit) :name(name),credit(credit)
{
	number++;
	students = NULL;
}
Course::~Course()
{
	number--;
}
void Course::printinfo()
{
	cout << setiosflags(ios::left);
	cout << "course:";
	cout << setw(25) << name;
	cout << "credit: ";
	cout << setw(5) << credit << endl;
}
istream& operator >>(istream& input, Course& c)
{
	//cout << "input the infomation of the course:" << endl;
	input >> c.name;
	input >> c.credit;
	//cout << "finish inputing" << endl;
	cout << "*";
	return input;
}
ostream& operator <<(ostream& output, Course& c)
{
	//cout << "output the infomation of the course:" << endl;
	output << c.name;
	output << c.credit;
	//cout << "finish" << endl;
	return output;

}