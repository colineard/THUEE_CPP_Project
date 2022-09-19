#include "requiredcourse.h"	
#include <iostream>
using namespace std;
int Requiredcourse::number = 0;
std::istream& operator >> (std::istream& input, Requiredcourse& c)
{
	//cout << "input the infomation of the course:" << endl;
	input >> c.name;
	input >> c.credit;
	//cout << "finish inputing" << endl;
	return input;
}
std::ostream& operator <<(std::ostream& output, Requiredcourse& c)
{

	cout << "output the infomation of the course:" << endl;
	output << c.name << endl;
	output << c.credit<<endl;
	cout << "finish" << endl;
	return output;

}
