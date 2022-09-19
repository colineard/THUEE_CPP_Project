#include "student_.h"
using namespace std;


bool comp_by_gpa( Student_& a,  Student_& b)
{
	if (a.student->getcourses()->get_GPA() > b.student->getcourses()->get_GPA())
		return 1;
	else return 0;
}
bool comp_by_id(Student_& a, Student_& b)
{
	if (strcmp(a.student->getid(), b.student->getid()) < 0)
		return 1;
	else return 0;
}