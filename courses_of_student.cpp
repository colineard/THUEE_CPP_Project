#include "courses_of_student.h"	
#include <iostream>
#include <iomanip>
#include <iterator>
using namespace std;
void Courses_of_student::pushback(Grades& g)
{
	courses.push_back(g);
	coursenumber++;
}
bool Courses_of_student::removecourse(int position)
{
    int i;
    vector<Grades>::iterator it;
    for (i=0,it = courses.begin(); it < courses.end(); it++,i++)
    {
        if (i==position)
        {
            break;
        }
    }
    if (it != courses.end()) 
    {
        courses.erase(it);
        coursenumber--;
        return true;
    }
    else 
    {
        return false;
    }
}
bool Courses_of_student::change_course_grades(int position,double grades)
{
    int i;
    vector<Grades>::iterator it;
    for (i = 0, it = courses.begin(); it < courses.end(); it++, i++)
    {
        if (i == position)
        {
            break;
        }
    }
    if (it != courses.end())
    {
        it->set_grades_point(grades);
        return 1;
    }
    else return 0;
}
void Courses_of_student::calculate()
{
    double sum_gpa=0.0;
    sum_credit = 0;
    for (int i = 0; i < courses.size(); i++)
    {
        sum_credit+=courses[i].get_course()->getcredit();
        sum_gpa += courses[i].get_course()->getcredit() * courses[i].get_point();
    }
    if(courses.size()!=0)
    GPA = sum_gpa / sum_credit;
}
void Courses_of_student::printinfo()
{
    cout << "©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´" << endl;
    for (int i = 0; i < courses.size(); i++)
    {
        courses[i].printgrades();
    }
    cout << "©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼" << endl;
    cout << setiosflags(ios::left);
    cout << " sum_credit:" <<setw(6) << sum_credit ;
    cout << "  GPA:" << setw(6) << GPA << endl;
}
void Courses_of_student::printcourses()
{
    for (int i = 0; i < courses.size(); i++)
    {
        cout << setiosflags(ios::left);
        courses[i].get_course()->printinfo();
        
    }
}
int Courses_of_student::get_courses(Course*c)
{
    for (int k = 0; k < courses.size(); k++)
    {
        if (courses[k].get_course() == c)
        {
            return k;
        }
    }
    return -1;
}
