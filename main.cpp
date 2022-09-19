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
void Init_student()  //��ʼ����������ѧ�����γ̵���Ķ�����г�ʼ��
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
void Refresh() //��ʹ�ý����󣬽����¹������гɼ���Ϣ�����ϴ����ļ��У����´�ʹ�òο�
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
		cout << "��������������������������������������������������������������������������������������������" << endl;
		cout << "��   ѧ   ��   ��   ��   ��   ��   ϵ   ͳ    ��" << endl;
		cout << "��������������������������������������������������������������������������������������������" << endl;
		cout << endl;
		cout << "�����������Щ�������������������������������������������������" << endl;
		cout << "��  1 ��   ѧ   ��   ��   ¼    �� " << endl;
		cout << "�����������ة�������������������������������������������������" << endl;
		cout << "�����������Щ�������������������������������������������������" << endl;
		cout << "��  2 ��   ��   ʦ   ��   ¼    �� " << endl;
		cout << "�����������ة�������������������������������������������������" << endl;
		cout << "�����������Щ�������������������������������������������������" << endl;
		cout << "��  3 ��   ��   ��   ��   ¼    �� " << endl;
		cout << "�����������ة�������������������������������������������������" << endl;
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
		default: cout << "ѡ�����������ѡ��" << endl;
		}
	}
	
}
void Student_log_in()
{
		int choice;
		char inputid[11] = { 0 };
		cout << "������id:" << endl;
		cin >> inputid;
		int i;
		for (i = 0; i < STUDENT_NUM; i++)
		{
			if (strcmp(STU[i].getid(), inputid) == 0)
			{
				cout << "���������룺" << endl;
				char password[20] = { 0 };
				cin >> password;
				while (!STU[i].comp_key(password) && strcmp(password, "q") != 0)
				{

					cout << "����������������룺������'q'�˳����룩" << endl;
					cin >> password;
				}
				if (strcmp(password, "q") != 0)
				{
					system("cls");
					cout << "����������������������������������������������������" << endl;
					cout << "��   ��   ¼   ��   ��    ��" << endl;
					cout << "����������������������������������������������������" << endl;
					Student_visiting(STU[i]);
				}
				break;
			}
		}
		if (i == STUDENT_NUM)
		{
			char c;
			cout << "��Ǹ��û�и�id��Ӧ��ѧ����Ϣ" << endl << endl;
			cout << "���������ַ��Է������˵�:" << endl;
			cin >> c;
			mainmenu();
		}
	
}
void Student_visiting(Student&s)
{
	while (1)
	{
		system("cls");
		cout << "�����������Щ�����������������������������������������������������������" << endl;
		cout << "��  1 ��   ��   ��   ��   ��   ѯ    �� " << endl;
		cout << "�����������ة�����������������������������������������������������������" << endl;
		cout << "�����������Щ�������������������������������������������������" << endl;
		cout << "��  2 ��   ��   ��   ��   ��    �� " << endl;
		cout << "�����������ة�������������������������������������������������" << endl;
		cout << "�����������Щ�����������������������������������������������������������" << endl;
		cout << "��  3 ��   ��   ��   ��   ��   ��    �� " << endl;
		cout << "�����������ة�����������������������������������������������������������" << endl;
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
			else cout << "ѡ�����������ѡ��" << endl;
		}
	}
}
void Printgrades(Student& s)
{
	char c;
	system("cls");
	if (s.getcourses()->get_coursenumber() == 0)
		cout << "��Ǹ����ѧ���ɼ���Ϣ��δ¼�룬\n��Ҫͨ����ʦ��¼ѡ���ֶ�����ļ�¼��ѧ���ɼ���Ϣ��" << endl;
	else
	{
		cout << s.getname() << "   " << s.getid() << "   " << s.getdepartment()->getname() << endl;
		s.getcourses()->printinfo();
	}
	cout << "���������ַ�����:" << endl;
	cin >> c;
}
void Printcourses(Student & s)
{
	char c;
	system("cls");
	if (s.getcourses()->get_coursenumber() == 0)
		cout << "��Ǹ����ѧ���ɼ���Ϣ��δ¼�룬\n��Ҫͨ����ʦ��¼ѡ���ֶ�����ļ�¼��ѧ���ɼ���Ϣ��" << endl;
	else
	{
		cout << endl;
		cout << s.getname() << "   " << s.getid() << "   " << s.getdepartment()->getname() << endl;
		cout << "��������������������������������������������������������������������������������" << endl;
		s.getcourses()->printcourses();
		cout << "��������������������������������������������������������������������������������" << endl;
	}
	cout << "���������ַ�����:" << endl;
	cin >> c;
}
void Teacher_log_in()
{
	int num;
	cout << endl << "�������ʦ���:" << endl;
	cin >> num;
	while (num <= 0)
	{
		cout << "���Ϊ������������������" << endl;
		cin >> num;
	}
	cout << endl << "���������룺" << endl;
	char password[20] = { 0 }, right_password[20] = { 0 };

	ifstream input("D:/finalproject/teachers_key.txt");
	for (int i = 0; i < num; i++)
	{
		input >> right_password;
	}
	cin >> password;
	while (strcmp(right_password, password) != 0&&strcmp(password,"q")!=0)
	{
		cout << endl << "����������������룺������'q'�˳����룩" << endl;
		cin >> password;
	}
	if (strcmp(password, "q") != 0)
	{
		system("cls");
		cout << "����������������������������������������������������" << endl;
		cout << "��   ��   ¼   ��   ��    ��" << endl;
		cout << "����������������������������������������������������" << endl;
		Teacher_visiting();
	}
}
void Teacher_visiting()
{
		system("cls");
		cout << "�����������Щ���������������������������������������������������������������������" << endl;
		cout << "��  1 ��   ѧ   ��   ��   ��   ¼   ��    �� " << endl;
		cout << "�����������ة���������������������������������������������������������������������" << endl;
		cout << "�����������Щ�����������������������������������������������������������������������������������������" << endl;
		cout << "��  2 ��   Ժ   ϵ   ��   ��   ��   ��   ��   ѯ    �� " << endl;
		cout << "�����������ة�����������������������������������������������������������������������������������������" << endl;
		cout << "�����������Щ���������������������������������������������������������������������" << endl;
		cout << "��  3 ��   ��   ��   ��   ��   ��   ѯ    �� " << endl;
		cout << "�����������ة���������������������������������������������������������������������" << endl;
		cout << "�����������Щ���������������������������������������������������������������������" << endl;
		cout << "��  4 ��   ��   ��   ��   ��   ��   ��    �� " << endl;
		cout << "�����������ة���������������������������������������������������������������������" << endl;
		cout << "�����������Щ�����������������������������������������������������������" << endl;
		cout << "��  5 ��   ��   ��   ��   ��   ��    �� " << endl;
		cout << "�����������ة�����������������������������������������������������������" << endl;
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
			cout << "��������������ѡ��" << endl;
			Teacher_visiting();
			}
		}
}
void show_department()
{
	system("cls");
	if (GRADE[0].get_student()==NULL)
	{
		cout << "ѧ���ɼ���Ϣ��δ¼�룬����¼��" << endl;
	}
	else
	{
		cout << "��ѡ��Ժϵ��" << endl;
		cout << "��������������������������������������������������������������������������������������������" << endl;
		for (int i = 0; i < DEPARTMENT_NUM; i++)
		{
			cout << "   " << i + 1 << ". ";
			DEPA[i].printinfo();
		}
		cout << "��������������������������������������������������������������������������������������������" << endl;
		int choice;
		cin >> choice;
		int choice2;
		cout << "��ѡ��ɼ����������" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
		cout << "  1. ���ɼ��ߵ�����" << endl;
		cout << "  2. ��ѧ���Ⱥ�����" << endl;
		cout << "����������������������������������������������������������������������������" << endl;
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
	cout << "���������ַ��Է��أ�" << endl;
	cin >> c;
	Teacher_visiting();
}

void student_grades_input()
{
	while (1)
	{
		system("cls");
		cout << "��ѡ��" << endl;
		cout << "�����������Щ�������������������������������������������������" << endl;
		cout << "��  1 ��   ��   ��   ��   ��    �� " << endl;
		cout << "�����������ة�������������������������������������������������" << endl;
		cout << "�����������Щ�������������������������������������������������������������������������������" << endl;
		cout << "��  2 ��   ��   ��   ��   ��   ��   ��   ��    �� " << endl;
		cout << "�����������ة�������������������������������������������������������������������������������" << endl;
		cout << "�����������Щ�������������������������������������������������" << endl;
		cout << "��  3 ��   ��   ��   ��   ��    �� " << endl;
		cout << "�����������ة�������������������������������������������������" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: hand_input(); break;
		case 2: file_input(); break;
		case 3: Teacher_visiting(); break;
		}
		char c;
		cout << "���������ַ��Է��أ�" << endl;
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
		cout << "������ѧ��ѧ�ţ�(���롮q�����˳��ֶ����룺)" << endl;
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
			cout << "��Ǹ��δ�ҵ���ѧ��" << endl;
			continue;
		}
		while (1)
		{
			cout << "������γ����ƣ�(���롮q���Ը�������ɼ���ѧ����)" << endl;
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
				cout << "��Ǹ��δ�ҵ��ÿγ�" << endl;
				continue;
			}
			for (k = 0; k < GRADES_NUM; k++)
			{
				if (GRADE[k].get_student() == NULL)
					break;
			}
			GRADE[k].set_student(&STU[i]);
			GRADE[k].set_course(COUR[j]);
			cout << "��ѡ��γ����� :(���롮0����ֹͣ����)" << endl;
			cout << "����������������������������������������������������" << endl;
			cout << "  1 . ���㼨�� " << endl;
			cout << "  2 . ��p" << endl;
			cout << "  3 . ��f" << endl;
			cout << "  4 . ��withdraw" << endl;
			cout << "����������������������������������������������������" << endl;
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
			cout << "����ɹ�!" << endl;
		}
	} 
	for (i = 0; i < STUDENT_NUM; i++)     //������ѧ���ĳɼ������¼���ÿ��ѧ���ļ��㡣
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
				cout << "�����ļ��е�" << count + 1 << "���ɼ���Ϣ��ѧ��id�Ƿ���ȷ" << endl;
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
				cout << "�����ļ��е�" << count + 1 << "���ɼ���Ϣ�Ŀγ������Ƿ���ȷ" << endl;
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
	cout << "����ɹ�" << endl;
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
	cout << "��ѡ��γ̣�" << endl;
	cout << "����������������������������������������������������" << endl;
	for (int i = 0; i < COURSE_NUM; i++)
	{
		cout << " " << i + 1;
		COUR[i]->printinfo();
	}
	cout << "����������������������������������������������������" << endl;
	int choice;
	cin >> choice;
	if (COUR[choice - 1]->getstudents()->get_studentnumber() == 0)
		cout << "�ÿγ����޶�Ӧѧ���ɼ���Ϣ" << endl;
	else
	{
		COUR[choice - 1]->getstudents()->printinfo();
	}
	char c;
	cout << "���������ַ��Է��أ�" << endl;
	cin >> c;
	Teacher_visiting();
}
void change_courses_grades() 
{
	system("cls");
	cout << "��ѡ����Ҫ�޸ĳɼ��Ŀγ̣�" << endl;
	cout << "����������������������������������������������������" << endl;
	for (int i = 0; i < COURSE_NUM; i++)
	{
		cout << left<<setw(5) << i + 1;
		COUR[i]->printinfo();
	}
	cout << "����������������������������������������������������" << endl;
	int choice1;
	int choice2=1;
	int choice3;
	cin >> choice1;
	if (SOC[choice1 - 1].get_studentnumber() == 0)
		cout << "�ÿγ����޶�Ӧѧ���ɼ���Ϣ" << endl;
	else
	{
		while (choice2 != 0)
		{
			system("cls");
			cout << "��������Ҫ�޸ĵڼ����ɼ���Ŀ��(����'0'�˳��޸ģ�" << endl;
			
			SOC[choice1-1].printinfo();
			cin >> choice2;
			if (choice2 != 0)
			{
				cout << "��ѡ��" << endl;
				cout << "����������������������������������������������������" << endl;
				cout << "1.  ɾ���óɼ���Ŀ" << endl;
				cout << "2.  �޸ķ���" << endl;
				cout << "����������������������������������������������������" << endl;
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
					cout << "�������µĳɼ���" << endl;
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
								COS[k].calculate();//�޸���ɼ������¼��㼨��
							}
						}
					}
				}
				cout << "����'0'�˳��޸�,���롰1�������޸������ɼ���Ŀ��" << endl;
				cin >> choice2;
			}
		}
	}
	char c;
	cout << "���������ַ��Է��أ�" << endl;
	cin >> c;
	Teacher_visiting();
}
void change_grades(int choice1,int choice2,double grades)
{
	
	COUR[choice1 - 1]->getstudents()->changegrades(choice2-1,grades);
	COUR[choice1 - 1]->getstudents()->calculate();//�޸ĳɼ������¼���γ̵�ƽ���ɼ�
	cout << "���³ɼ��ɹ���" << endl;
}
void delete_grades(int choice1, int choice2)
{
	COUR[choice1 - 1]->getstudents()->removestudent(choice2-1);
	COUR[choice1 - 1]->getstudents()->calculate(); //ɾ���ɼ������¼���γ̵�ƽ���ɼ�
	cout << "ɾ���ɹ�" << endl;
}