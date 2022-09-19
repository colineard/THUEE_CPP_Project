#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "base.h"
#include <vector>
#include <string>
#include "student.h"
#include "student_.h"
class Student;
class Student_;
typedef std::vector<Student_> studentlist;
class Department :public base
{
private:
	std::string name;
	studentlist students;
	int studentnumber=0;
	static int number;
public:
	Department();
	~Department();
	void set_name(std::string name) { this->name = name; } //设置院系名称
	std::string getname()
	{
		return name;
	}
	void pushback(Student_&);
	static int getnumber() { return number; }
	int getstudentnumber() { return studentnumber; }
	void print_student();
	void sort_student_by_id();
	void sort_student_by_GPA();
	virtual void printinfo();
	friend std::istream& operator >> (std::istream&, Department&);
	friend std::ostream& operator <<(std::ostream&, Department&);

};







#endif

