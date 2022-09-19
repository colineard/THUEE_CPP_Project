#pragma once
#include "base.h"
#include <string>
#include "courses_of_student.h"
#include "department.h"
class Courses_of_student;
class Department;
class Student :public base
{
private:
	std::string name;
	static int number;//���ڼ���ѧ������Ŀ
	char id[11] = {0};
	char key[20] = {0};
	Department* department;
	Courses_of_student* courses;
public:
	Student(std::string name, char* id,char *key, Department * department);
	Student();
	Student(const Student&);
	
	~Student();

	std::string getname() { return name; }
	char* getid() { return id; }

	//��ӡѧ����Ϣ���麯��
	virtual void printinfo();

	void changename(std::string newname) { name = newname; }
	void setid(char*);
	void setkey(char*);
	void setdepartment(Department* d) { department = d; }
	void setcourses(Courses_of_student* cos) { courses = cos; }
	bool comp_key(char*);
	Courses_of_student * getcourses()
	{
		return courses;
	}
	//��ȡѧ����Ŀ
	static int getnumber() { return number; }
	Department* getdepartment()
	{
		return department;
	}
	//������������������������������Ļ�����Ϣ
	friend std::istream& operator >> (std::istream&, Student&);
	friend std::ostream& operator <<(std::ostream&, Student&);

	
	
};