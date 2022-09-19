#include <iostream>
#include<iomanip>
#include "student.h"
#include "department.h"
#pragma warning(disable :4996)
using namespace std;
int Student::number = 0;
Student::Student(string name, char* id, char * key,Department * department):name(name),department(department)
{
	strcpy(this->id, id);
	strcpy(this->key, key);
	courses = NULL;
	number++;
}
Student::Student()
{
	number++;
	courses = NULL;
	department = NULL;
}
Student::Student(const Student&)
{
	number++;
}
Student::~Student()
{
	number--;
}
void Student::printinfo()
{
	cout << "name:";
	cout << setw(10) << name;
	cout << "id:";
	cout << setw(13) << id;
	cout << "department:" << setw(10) << department->getname() << endl;
 }
void Student::setid(char* newid)
{
	strcpy(id, newid);
}
void Student::setkey(char* newkey)
{
	strcpy(key, newkey);
}
bool Student::comp_key(char* password)
{
	if (strcmp(key, password) == 0)
		return true;
	else return false;
}
istream& operator>>(istream& input, Student& s)
{
	//cout << "input the name, id and key of the student:" << endl;
	input >> s.name;
	input >> s.id;
	input >> s.key;
	//cout << "finish inputing student's infomation" << endl;
	return input;
}
ostream& operator<<(ostream& output, Student& s)
{
	//cout << "output the infomation of student:" << endl;
	output << s.name<<endl;
	output << s.id << endl;
	output << s.key << endl;
	//cout << "finish" <<endl;
	return output;
}



