#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include<functional>
#include <vector>
#include <stdlib.h>
#include "base.h"
#include "course.h"
#include "courses_of_student.h"
#include "department.h"
#include "electivecourse.h"
#include "grades.h"
#include "requiredcourse.h"	
#include "student.h"
#include "students_of_course.h"
#include "student_.h"

using namespace std;
#define STUDENT_NUM 17
#define ELE_COURSE_NUM 4
#define REC_COURSE_NUM 10
#define COURSE_NUM 14
#define DEPARTMENT_NUM 4
#define GRADES_NUM 100

void mainmenu();
void Student_log_in();
void Student_visiting(Student& s);
void Printgrades(Student& s);
void Printcourses(Student& s);
void Teacher_log_in();
void Teacher_visiting();
void show_department();
void file_input();
void show_courses_grades();
void student_grades_input();
void hand_input();
void change_courses_grades();
void change_grades(int choice1, int choice2, double grades);
void delete_grades(int choice1, int choice2);
Student STU[STUDENT_NUM];
Student_ STU_[STUDENT_NUM];
Courses_of_student COS[STUDENT_NUM];
Electivecourse ELE_COUR[ELE_COURSE_NUM];
Requiredcourse REC_COUR[REC_COURSE_NUM];
Course* COUR[ELE_COURSE_NUM + REC_COURSE_NUM];
Students_of_course SOC[COURSE_NUM];
Department DEPA[DEPARTMENT_NUM];
Grades GRADE[GRADES_NUM];
void Init_student()  //初始化函数，对学生、课程等类的对象进行初始化
{
	int i, k;
	string department_name;
	ifstream  finput("D:/finalproject/studentlist.txt");
	for ( i = 0; i < STUDENT_NUM; i++)
	{
		finput >> STU[i];
		finput >> department_name;
		int flag = 0;
		for (k = 0 ; k < DEPARTMENT_NUM&&flag==0; k++)
		{
			if (department_name == DEPA[k].getname())
				flag = 1;
		}
		STU[i].setdepartment(&DEPA[k-1]);
		STU[i].setcourses(&COS[i]);
		COS[i].set_student(&STU[i]);
		STU_[i].setstudent(&STU[i]);
		DEPA[k - 1].pushback(STU_[i]);
		
	}
}
void Init_courses()
{
	int i, k;
	ifstream finput("D:/finalproject/electivecourselist.txt");
	for (i = 0; i < ELE_COURSE_NUM; i++)
	{
		finput >> ELE_COUR[i];
		ELE_COUR[i].setstudents(&SOC[i]);
		COUR[i] = &ELE_COUR[i];
		SOC[i ].set_course(COUR[i ]);
	}
	finput.close();
	finput.open("D:/finalproject/requiredcourselist.txt");
	for (k = 0; k < REC_COURSE_NUM; k++)
	{
		finput >> REC_COUR[k];
		REC_COUR[k].setstudents(&SOC[i + k]);
		COUR[i + k] = &REC_COUR[k];
		SOC[i + k].set_course(COUR[i + k]);
	}
}
void Init_department()
{
	int i;
	ifstream finput("D:/finalproject/department.txt");
	for (i = 0; i < DEPARTMENT_NUM; i++)
	{
		finput >> DEPA[i];
	}
}
void Refresh() //在使用结束后，将更新过的所有成绩信息重新上传到文件中，供下次使用参考
{
	int i;
	ofstream foutput("D:/finalproject/studentlist.txt");
	for (i = 0; i < Student::getnumber(); i++)
	{
		foutput << STU[i];
		foutput << STU[i].getdepartment()->getname() << endl;
	}
	foutput.close();
	foutput.open("D:/finalproject/electivecourselist.txt");
	for (i = 0; i < Electivecourse::getnumber(); i++)
	{
		foutput << ELE_COUR[i];
	}
	foutput.close();
	foutput.open("D:/finalproject/requiredcourselist.txt");
	for (i = 0; i < Requiredcourse::getnumber(); i++)
	{
		foutput << REC_COUR[i];
	}
	foutput.close();
	foutput.open("D:/finalproject/department.txt");
	for (i = 0; i < Department::getnumber(); i++)
	{
		foutput << DEPA[i];
	}
	foutput.close();
	foutput.open("D:/finalproject/grades.txt");
	for (i = 0;i<Grades::getnumber()&&GRADE[i].get_student()!=NULL; i++)
	{
			foutput << GRADE[i].get_student()->getid() << endl;
			foutput << GRADE[i].get_course()->getname() << endl;
			foutput << GRADE[i].get_int_type() << endl;
			foutput << GRADE[i].get_grades() << endl;
	}
}
int main()
{
	cout << "inputing the departments'information" << endl;
	Init_department();
	cout << "inputing the students'information" << endl;
	Init_student();
	cout << "inputing the courses'information" << endl;
	Init_courses();
	cout << "finish" << endl;
	mainmenu();
	
}
void mainmenu()
{
	while (1)
	{
		int choice;
		system("cls");
		cout << "┌────────────────────────────────────────────┐" << endl;
		cout << "│   学   生   成   绩   管   理   系   统    │" << endl;
		cout << "└────────────────────────────────────────────┘" << endl;
		cout << endl;
		cout << "┌────┬────────────────────────┐" << endl;
		cout << "│  1 │   学   生   登   录    │ " << endl;
		cout << "└────┴────────────────────────┘" << endl;
		cout << "┌────┬────────────────────────┐" << endl;
		cout << "│  2 │   教   师   登   录    │ " << endl;
		cout << "└────┴────────────────────────┘" << endl;
		cout << "┌────┬────────────────────────┐" << endl;
		cout << "│  3 │   退   出   登   录    │ " << endl;
		cout << "└────┴────────────────────────┘" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: Student_log_in();  break;
		case 2: Teacher_log_in(); break;
		case 3:
		{
			Refresh();
			exit(0);
		}
		default: cout << "选项错误，请重新选择。" << endl;
		}
	}
	
}
void Student_log_in()
{
		int choice;
		char inputid[11] = { 0 };
		cout << "请输入id:" << endl;
		cin >> inputid;
		int i;
		for (i = 0; i < STUDENT_NUM; i++)
		{
			if (strcmp(STU[i].getid(), inputid) == 0)
			{
				cout << "请输入密码：" << endl;
				char password[20] = { 0 };
				cin >> password;
				while (!STU[i].comp_key(password) && strcmp(password, "q") != 0)
				{

					cout << "密码错误，请重新输入：（输入'q'退出输入）" << endl;
					cin >> password;
				}
				if (strcmp(password, "q") != 0)
				{
					system("cls");
					cout << "┌────────────────────────┐" << endl;
					cout << "│   登   录   成   功    │" << endl;
					cout << "└────────────────────────┘" << endl;
					Student_visiting(STU[i]);
				}
				break;
			}
		}
		if (i == STUDENT_NUM)
		{
			char c;
			cout << "抱歉，没有该id对应的学生信息" << endl << endl;
			cout << "输入任意字符以返回主菜单:" << endl;
			cin >> c;
			mainmenu();
		}
	
}
void Student_visiting(Student&s)
{
	while (1)
	{
		system("cls");
		cout << "┌────┬─────────────────────────────┐" << endl;
		cout << "│  1 │   成   绩   单   查   询    │ " << endl;
		cout << "└────┴─────────────────────────────┘" << endl;
		cout << "┌────┬────────────────────────┐" << endl;
		cout << "│  2 │   课   程   列   表    │ " << endl;
		cout << "└────┴────────────────────────┘" << endl;
		cout << "┌────┬─────────────────────────────┐" << endl;
		cout << "│  3 │   返   回   主   菜   单    │ " << endl;
		cout << "└────┴─────────────────────────────┘" << endl;
		int choice=4;
		while (choice > 3 || choice < 1)
		{
			cin >> choice;
			if (choice == 1)
			{
				Printgrades(s);
			}
			else if (choice == 2)
			{
				Printcourses(s);
			}
			else if (choice == 3)
			{
				mainmenu();
			}
			else cout << "选项错误，请重新选择。" << endl;
		}
	}
}
void Printgrades(Student& s)
{
	char c;
	system("cls");
	if (s.getcourses()->get_coursenumber() == 0)
		cout << "抱歉，该学生成绩信息尚未录入，\n需要通过教师登录选择手动或从文件录入学生成绩信息。" << endl;
	else
	{
		cout << s.getname() << "   " << s.getid() << "   " << s.getdepartment()->getname() << endl;
		s.getcourses()->printinfo();
	}
	cout << "输入任意字符返回:" << endl;
	cin >> c;
}
void Printcourses(Student & s)
{
	char c;
	system("cls");
	if (s.getcourses()->get_coursenumber() == 0)
		cout << "抱歉，该学生成绩信息尚未录入，\n需要通过教师登录选择手动或从文件录入学生成绩信息。" << endl;
	else
	{
		cout << endl;
		cout << s.getname() << "   " << s.getid() << "   " << s.getdepartment()->getname() << endl;
		cout << "┌──────────────────────────────────────┐" << endl;
		s.getcourses()->printcourses();
		cout << "└──────────────────────────────────────┘" << endl;
	}
	cout << "输入任意字符返回:" << endl;
	cin >> c;
}
void Teacher_log_in()
{
	int num;
	cout << endl << "请输入教师序号:" << endl;
	cin >> num;
	while (num <= 0)
	{
		cout << "序号为正整数，请重新输入" << endl;
		cin >> num;
	}
	cout << endl << "请输入密码：" << endl;
	char password[20] = { 0 }, right_password[20] = { 0 };

	ifstream input("D:/finalproject/teachers_key.txt");
	for (int i = 0; i < num; i++)
	{
		input >> right_password;
	}
	cin >> password;
	while (strcmp(right_password, password) != 0&&strcmp(password,"q")!=0)
	{
		cout << endl << "密码错误，请重新输入：（输入'q'退出输入）" << endl;
		cin >> password;
	}
	if (strcmp(password, "q") != 0)
	{
		system("cls");
		cout << "┌────────────────────────┐" << endl;
		cout << "│   登   录   成   功    │" << endl;
		cout << "└────────────────────────┘" << endl;
		Teacher_visiting();
	}
}
void Teacher_visiting()
{
		system("cls");
		cout << "┌────┬──────────────────────────────────┐" << endl;
		cout << "│  1 │   学   生   成   绩   录   入    │ " << endl;
		cout << "└────┴──────────────────────────────────┘" << endl;
		cout << "┌────┬────────────────────────────────────────────┐" << endl;
		cout << "│  2 │   院   系   成   绩   情   况   查   询    │ " << endl;
		cout << "└────┴────────────────────────────────────────────┘" << endl;
		cout << "┌────┬──────────────────────────────────┐" << endl;
		cout << "│  3 │   课   程   成   绩   查   询    │ " << endl;
		cout << "└────┴──────────────────────────────────┘" << endl;
		cout << "┌────┬──────────────────────────────────┐" << endl;
		cout << "│  4 │   修   改   课   程   成   绩    │ " << endl;
		cout << "└────┴──────────────────────────────────┘" << endl;
		cout << "┌────┬─────────────────────────────┐" << endl;
		cout << "│  5 │   返   回   主   菜   单    │ " << endl;
		cout << "└────┴─────────────────────────────┘" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
			case 1: student_grades_input(); break;
			case 2:  show_department(); break;
			case 3: show_courses_grades(); break;
			case 4: change_courses_grades(); break;
			case 5: mainmenu(); break;
			default:
			{
			cout << "输入有误，请重新选择" << endl;
			Teacher_visiting();
			}
		}
}
void show_department()
{
	system("cls");
	if (GRADE[0].get_student()==NULL)
	{
		cout << "学生成绩信息尚未录入，请先录入" << endl;
	}
	else
	{
		cout << "请选择院系：" << endl;
		cout << "┌────────────────────────────────────────────┐" << endl;
		for (int i = 0; i < DEPARTMENT_NUM; i++)
		{
			cout << "   " << i + 1 << ". ";
			DEPA[i].printinfo();
		}
		cout << "└────────────────────────────────────────────┘" << endl;
		int choice;
		cin >> choice;
		int choice2;
		cout << "请选择成绩单排序规则：" << endl;
		cout << "┌────────────────────────────────────┐" << endl;
		cout << "  1. 按成绩高低排序" << endl;
		cout << "  2. 按学号先后排序" << endl;
		cout << "└────────────────────────────────────┘" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1: DEPA[choice - 1].sort_student_by_GPA(); break;
		case 2:DEPA[choice - 1].sort_student_by_id(); break;
		}
		system("cls");
		DEPA[choice - 1].print_student();
	}
	char c;
	cout << "输入任意字符以返回：" << endl;
	cin >> c;
	Teacher_visiting();
}

void student_grades_input()
{
	while (1)
	{
		system("cls");
		cout << "请选择：" << endl;
		cout << "┌────┬────────────────────────┐" << endl;
		cout << "│  1 │   手   动   输   入    │ " << endl;
		cout << "└────┴────────────────────────┘" << endl;
		cout << "┌────┬───────────────────────────────────────┐" << endl;
		cout << "│  2 │   从   已   有   文   件   输   入    │ " << endl;
		cout << "└────┴───────────────────────────────────────┘" << endl;
		cout << "┌────┬────────────────────────┐" << endl;
		cout << "│  3 │   退   出   输   入    │ " << endl;
		cout << "└────┴────────────────────────┘" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: hand_input(); break;
		case 2: file_input(); break;
		case 3: Teacher_visiting(); break;
		}
		char c;
		cout << "输入任意字符以返回：" << endl;
		cin >> c;
	}
}
void hand_input()
{
	int i;
	int j;
	int k;
	char Stu_id[11];
	string Cour_name;
	int course_type;
	while (1)
	{
		cout << "请输入学生学号：(输入‘q’以退出手动输入：)" << endl;
		cin >> Stu_id;
		if (strcmp(Stu_id, "q") == 0)
			break;
		
		for (i = 0; i < STUDENT_NUM; i++)
		{
			if (strcmp(STU[i].getid(), Stu_id) == 0)
				break;
		}
		if(i==STUDENT_NUM)
		{
			cout << "抱歉，未找到该学生" << endl;
			continue;
		}
		while (1)
		{
			cout << "请输入课程名称：(输入‘q’以更换输入成绩的学生：)" << endl;
			cin >> Cour_name;
			if (Cour_name == "q")
				break;
			for (j = 0; j < COURSE_NUM; j++)
			{
				if (Cour_name == COUR[j]->getname())
					break;
			}
			if (j == COURSE_NUM)
			{
				cout << "抱歉，未找到该课程" << endl;
				continue;
			}
			for (k = 0; k < GRADES_NUM; k++)
			{
				if (GRADE[k].get_student() == NULL)
					break;
			}
			GRADE[k].set_student(&STU[i]);
			GRADE[k].set_course(COUR[j]);
			cout << "请选择课程类型 :(输入‘0’以停止输入)" << endl;
			cout << "┌────────────────────────┐" << endl;
			cout << "  1 . 计算绩点 " << endl;
			cout << "  2 . 记p" << endl;
			cout << "  3 . 记f" << endl;
			cout << "  4 . 记withdraw" << endl;
			cout << "└────────────────────────┘" << endl;
			cin >> course_type;
			if (course_type == 0)
				break;
			GRADE[k].set_type(course_type - 1);
			if (course_type - 1 == 0)
			{
				cin >> GRADE[k];
			}
			STU[i].getcourses()->pushback(GRADE[k]);
			COUR[j]->getstudents()->pushback(GRADE[k]);
			cout << "输入成功!" << endl;
		}
	} 
	for (i = 0; i < STUDENT_NUM; i++)     //输入完学生的成绩后，重新计算每个学生的绩点。
	{
		STU[i].getcourses()->calculate();
	}
	for (k = 0; k < COURSE_NUM; k++)
	{
		COUR[k]->getstudents()->calculate();
	}
}
void file_input()
{
	int count = 0;
	ifstream finput("D:/finalproject/grades.txt");
	int i;
	int j;
	int k;
	char Stu_id[11] = { 0 };
	string Cour_name;
	int course_type;
	for (count=0;count<GRADES_NUM&&finput.good();count++)
	{
		finput >> Stu_id;
		if(strlen(Stu_id)!=0)
		{
			for (i = 0; i < STUDENT_NUM; i++)
			{
				if (strcmp(STU[i].getid(), Stu_id) == 0)
					break;
			}
			if (i == STUDENT_NUM)
			{
				cout << "请检查文件中第" << count + 1 << "条成绩信息的学生id是否正确" << endl;
				continue;
			}
			finput >> Cour_name;
			for (j = 0; j < COURSE_NUM; j++)
			{
				if (Cour_name == COUR[j]->getname())
					break;
			}
			if (j == COURSE_NUM)
			{
				cout << "请检查文件中第" << count + 1 << "条成绩信息的课程名称是否正确" << endl;
				continue;
			}
			for (k = 0; k < GRADES_NUM; k++)
			{
				if (GRADE[k].get_student() == NULL)
					break;
			}
			GRADE[k].set_student(&STU[i]);
			GRADE[k].set_course(COUR[j]);
			finput >> course_type;
			GRADE[k].set_type(course_type);
			finput >> GRADE[k];
			finput.get();
			STU[i].getcourses()->pushback(GRADE[k]);
			COUR[j]->getstudents()->pushback(GRADE[k]);
		}
	}
	system("cls");
	cout << "输入成功" << endl;
	for (i = 0; i < STUDENT_NUM; i++)
	{
		STU[i].getcourses()->calculate();
	}
	for (k = 0; k < COURSE_NUM; k++)
	{
		COUR[k]->getstudents()->calculate();
	}
}
void show_courses_grades()
{
	system("cls");
	cout << "请选择课程：" << endl;
	cout << "┌────────────────────────┐" << endl;
	for (int i = 0; i < COURSE_NUM; i++)
	{
		cout << " " << i + 1;
		COUR[i]->printinfo();
	}
	cout << "└────────────────────────┘" << endl;
	int choice;
	cin >> choice;
	if (COUR[choice - 1]->getstudents()->get_studentnumber() == 0)
		cout << "该课程尚无对应学生成绩信息" << endl;
	else
	{
		COUR[choice - 1]->getstudents()->printinfo();
	}
	char c;
	cout << "输入任意字符以返回：" << endl;
	cin >> c;
	Teacher_visiting();
}
void change_courses_grades() 
{
	system("cls");
	cout << "请选择你要修改成绩的课程：" << endl;
	cout << "┌────────────────────────┐" << endl;
	for (int i = 0; i < COURSE_NUM; i++)
	{
		cout << left<<setw(5) << i + 1;
		COUR[i]->printinfo();
	}
	cout << "└────────────────────────┘" << endl;
	int choice1;
	int choice2=1;
	int choice3;
	cin >> choice1;
	if (SOC[choice1 - 1].get_studentnumber() == 0)
		cout << "该课程尚无对应学生成绩信息" << endl;
	else
	{
		while (choice2 != 0)
		{
			system("cls");
			cout << "请输入你要修改第几条成绩条目：(输入'0'退出修改）" << endl;
			
			SOC[choice1-1].printinfo();
			cin >> choice2;
			if (choice2 != 0)
			{
				cout << "请选择：" << endl;
				cout << "┌────────────────────────┐" << endl;
				cout << "1.  删除该成绩条目" << endl;
				cout << "2.  修改分数" << endl;
				cout << "└────────────────────────┘" << endl;
				cin >> choice3;
				if(choice3==1)
				{
					delete_grades(choice1,choice2); 
					for (int k = 0; k < GRADES_NUM && GRADE[k].get_student() != NULL; k++)
					{
						if (GRADE[k].get_course() == COUR[choice1 - 1])
						{
							int p = SOC[choice1 - 1].get_students(GRADE[k].get_student());
							if(p==choice2-1)
							GRADE[k].set_student(NULL);
						}
					}
					for (int k = 0; k < STUDENT_NUM; k++)
					{
						int p = SOC[choice1 - 1].get_students(&STU[k]);
						if (p == choice2 - 1)
						{
							for (int j = 0; j < COS[k].get_coursenumber(); j++)
							{
								COS[k].removecourse(COS[k].get_courses(COUR[choice1 - 1]));
								COS[k].calculate();
							}
						}
					}
				}
				else if(choice3==2)
				{
					double grades;
					cout << "请输入新的成绩：" << endl;
					cin >> grades;
					change_grades(choice1, choice2,grades);
					for (int k = 0; k < GRADES_NUM && GRADE[k].get_student() != NULL; k++)
					{
						if (GRADE[k].get_course() == COUR[choice1 - 1])
						{
							int p = SOC[choice1 - 1].get_students(GRADE[k].get_student());
							if(p==choice2-1)
							GRADE[k].set_grades_point(grades);
						}
					}
					for (int k = 0; k < STUDENT_NUM; k++)
					{
						int p = SOC[choice1 - 1].get_students(&STU[k]);
						if (p == choice2 - 1)
						{
							for (int j = 0; j < COS[k].get_coursenumber(); j++)
							{
								COS[k].change_course_grades(COS[k].get_courses(COUR[choice1 - 1]),grades);
								COS[k].calculate();//修改完成绩后重新计算绩点
							}
						}
					}
				}
				cout << "输入'0'退出修改,输入“1”继续修改其他成绩条目：" << endl;
				cin >> choice2;
			}
		}
	}
	char c;
	cout << "输入任意字符以返回：" << endl;
	cin >> c;
	Teacher_visiting();
}
void change_grades(int choice1,int choice2,double grades)
{
	
	COUR[choice1 - 1]->getstudents()->changegrades(choice2-1,grades);
	COUR[choice1 - 1]->getstudents()->calculate();//修改成绩后，重新计算课程的平均成绩
	cout << "更新成绩成功！" << endl;
}
void delete_grades(int choice1, int choice2)
{
	COUR[choice1 - 1]->getstudents()->removestudent(choice2-1);
	COUR[choice1 - 1]->getstudents()->calculate(); //删除成绩后，重新计算课程的平均成绩
	cout << "删除成功" << endl;
}