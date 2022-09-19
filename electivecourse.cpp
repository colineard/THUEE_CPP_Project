#include "electivecourse.h"
#include <iostream>	
using namespace std;

int Electivecourse::number = 0;

std::istream& operator >> (std::istream& input, Electivecourse& c)
{
	//cout << "input the infomation of the course:" << endl;
	input >> c.name;
	input >> c.credit;
	//cout << "finish inputing" << endl;
	return input;
}

std::ostream& operator <<(std::ostream& output, Electivecourse& c)
{
	cout << "output the infomation of the course:" << endl;
	output << c.name<<endl;
	output << c.credit << endl;
	cout << "finish" << endl;
	return output;
}