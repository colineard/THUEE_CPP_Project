#ifndef COURSE_H
#define COURSE_H
#include "base.h"
#include <string>
#include "students_of_course.h"
//�γ���
class Students_of_course;
class Course : public base
{
protected:
	std::string name;
	static int number;//���ڼ����γ̵���Ŀ
	int credit;
	Students_of_course* students; //ָ�������ſε�����ѧ���ɼ�
public:
	//�޲ι��캯�����вι��캯������������
	Course();
	Course(std::string name, int credit);
	~Course();

	std::string getname() { return name; }
	int getcredit() { return credit; }
	//��ȡ�γ������ĺ���
	static int getnumber() { return number; }
	Students_of_course* getstudents()
	{
		return students;
	}
	void  setname(std::string newname) { name = newname; }
	void setcredit(int newcredit) {credit = newcredit;}
	void setstudents(Students_of_course* soc) { students = soc; }
	//��ӡ�γ���Ϣ���麯��
	virtual void printinfo();

	//������������������������������Ļ�����Ϣ
	friend std::istream& operator >> (std::istream&, Course&);
	friend std::ostream& operator <<(std::ostream&, Course&);
};






#endif
