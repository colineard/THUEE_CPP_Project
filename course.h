#ifndef COURSE_H
#define COURSE_H
#include "base.h"
#include <string>
#include "students_of_course.h"
//课程类
class Students_of_course;
class Course : public base
{
protected:
	std::string name;
	static int number;//用于计数课程的数目
	int credit;
	Students_of_course* students; //指向上这门课的所有学生成绩
public:
	//无参构造函数、有参构造函数、析构函数
	Course();
	Course(std::string name, int credit);
	~Course();

	std::string getname() { return name; }
	int getcredit() { return credit; }
	//获取课程总数的函数
	static int getnumber() { return number; }
	Students_of_course* getstudents()
	{
		return students;
	}
	void  setname(std::string newname) { name = newname; }
	void setcredit(int newcredit) {credit = newcredit;}
	void setstudents(Students_of_course* soc) { students = soc; }
	//打印课程信息的虚函数
	virtual void printinfo();

	//重载流操作符，向流输入或输出对象的基本信息
	friend std::istream& operator >> (std::istream&, Course&);
	friend std::ostream& operator <<(std::ostream&, Course&);
};






#endif
