/*student management information system*/
/*******************************************************************************
学生信息管理系统函数库
void Initialize_SMIS() 初始化学生信息管理系统
void Welcome_SMIS() 欢迎界面
*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "string.h"

typedef struct Student      //建立单链表
{
	char Number[20]; //学号
	char Name[20];   //姓名
	char Sex[9];    //性别
	char Birthday[15];      //出生年月
	char Address[50];          //地址
	char Class[20];     //班级
	char PhoneNumber[11];   //电话
	char email[25];         //e-mail
     int Age; //年龄
	struct Student * Next;  //指向下一个节点的位置
}Student, *Student_Node;

void hello()
{
	printf("Hello World!\n");
}

Student_Node Creat_LinkList(void)
{
	Student_Node H;
	H = (Student_Node)malloc(sizeof(Student));
	if (H)
		H->Next = NULL;
	return H;
}

void Destroy_LinkList(Student_Node *H)   //销毁单链表
{
	Student_Node p, q;
	p = *H;
	while (p)
	{
		q = p;
		p = p->Next;
		free(q);
	}
	*H = NULL;
}
void Insert_One_Node(Student_Node Student_head,Student_Node Student_1) //插入节点
{
	Student_Node Student_2 = Creat_LinkList();
	Student_2->Next=Student_head->Next;
    while (Student_2->Next)    //循环找到最后一个节点
		Student_2 = Student_2->Next;
	Student_2->Next = Student_1;
	return;
}
void ReadInformationFile(Student_Node Student_head)    //从磁盘中读取“student.txt”文件
{
	FILE *fp;
	Student_Node Student_1=Creat_LinkList();
	int flag = 1;
	char string_1[4] = "";
	fp = fopen("student.txt", "r");    //只读打开文件
	if (!fp) 
	{
		printf("Can't find File\n");    //文件不存在
		while (flag)
		{
			printf("Do you need to create a new file? (Yes/No)\n");    //创建新文件
			scanf("%s[a-z-A-Z]", &string_1);    //限制字母输入
			if (strcmp(string_1, "Yes") == 0 || strcmp(string_1, "yes") == 0 || strcmp(string_1, "Y") == 0 || strcmp(string_1, "y") == 0)//判断Yes
			{
				fp = fopen("student.txt", "w");    //创建空文件
				fclose(fp);   //关闭文件
				printf("Create File Successfully!\n ");
				flag = 0;
				return;
			}
			else if (strcmp(string_1, "No") == 0 || strcmp(string_1, "no") == 0 || strcmp(string_1, "N") == 0 || strcmp(string_1, "n") == 0)    //判断No
			{
				flag = 0;
				return;    //不做任何操作
			}
			else
			{
				printf("Illegal input！\n");    //不合法输入
			}
		}
	}
	else
		printf("Open File Successfully!\n ");    //打开成功
	while (!feof(fp))    //读取文件内容
	{    //读取学号，班级，姓名，性别，年龄，电话，e-mail，出生年月，地址
		fscanf(fp, "%s%s%s%s%d%s%s%s%s\n", Student_1->Number, Student_1->Class, Student_1->Name, Student_1->Sex, &Student_1->Age,Student_1->PhoneNumber,Student_1->email,Student_1->Birthday, Student_1->Address);
		if (Student_1 != NULL)
			Insert_One_Node(Student_head,Student_1);
		Student_1 = Creat_LinkList();
	}
	fclose(fp);    //关闭文件指针
	return;
}

void Initialize_SMIS(Student_Node Student_head)//初始化学生信息管理系统
{
	printf("初始化中.......\n");
	ReadInformationFile(Student_head);
}

void Welcome_SMIS()//欢迎界面
{
	printf("***********************************************************\n");
	printf("Welcome to use SMIS(Student Management Information System)\n");
	printf("The Software maked by Steven Wang from AHUT.\n");
	printf("***********************************************************\n");
}

void Display_One_Information(Student_Node Student_1)   //输出一条信息
{    //输出学号，班级，姓名，性别，年龄，电话，e-mail，出生年月，地址
	printf("Number\t Class\t Name\t Sex\t Age\t PhoneNumber\t E-Mail\t Birthday\t Address\t\n");
	printf("%s\t", Student_1->Number);
	printf(" %s\t", Student_1->Class);
	printf(" %s\t", Student_1->Name);
	printf(" %s\t", Student_1->Sex);
	printf(" %d\t", Student_1->Age);
	printf(" %s\t\t", Student_1->PhoneNumber);
	printf(" %s\t", Student_1->email);
	printf(" %s\t\t", Student_1->Birthday);
	printf(" %s\t", Student_1->Address);
	printf("\n");
	return;
}
void Output_Information(Student_Node Student)   //输出信息
{
	Student_Node Student_2;
	Student_2 = Student->Next;
	if (Student_2 == NULL)
	{
		printf("Sorry,No Student Information, Please enter Student Information:\n");
		//Get_Infotmation(Student,Student_2);
		return;
	}
	printf("StudentNumber/t StudentName/t ClassName/t Sex/t Age/t PhoneNumber/t Addr/t \n");
	while (Student_2)
	{
		Display_One_Information(Student_2);
		Student_2 = Student_2->Next;
	}
	return;
}
void DisplayInformaticaByStudentName(Student_Node Student)
{
	Student_Node p;
	char StudentName[20];
	char flag = 0;
	p = Student->Next;
	printf("请输入学生姓名：");
	scanf("%s", StudentName);
	while (p)
	{
		if (strcmp(p->Name,StudentName) == 0)
		{
			printf("学号\t 姓名\t 班级\t 性别\t 年龄\t 电话\t 地址\t \n");
			Display_One_Information(p);
			flag = 1;
			break;
		}
		p = p->Next;
	}
	if (!flag)
		printf("对不起，不存在姓名为%s 的学生！\n", StudentName);
}
Student_Node DisplayInformaticaByStudentNumber(Student_Node Student)
{
	Student_Node p;
	char StudentNumber[20];
	char flag = 0;
	p = Student->Next;
	printf("请输入学生学号：");
	scanf("%s", StudentNumber);
	while (p)
	{
		if (strcmp(p->Number, StudentNumber) == 0)
		{
			printf("学号\t 姓名\t 班级\t 性别\t 年龄\t 电话\t 地址\t \n");
			Display_One_Information(p);
			flag = 1;
			break;
		}
		p = p->Next;
	}
	if (!flag)
	{
		printf("对不起，不存在学号为%s 的学生！\n", StudentNumber);
		return NULL;
	}
	return p;
}
void InforSearch(Student_Node Student)
{
	int ch;
	printf("\n1按姓名查\n2按学号查\n");
	printf("\n\n请选择：");
	scanf("%d", &ch);
	switch (ch) {
	case 1: DisplayInformaticaByStudentName(Student);  break;
	case 2: DisplayInformaticaByStudentNumber(Student); break;
	default: break;
	}
}
int Get_Infotmation(Student_Node Student,Student_Node Student_1)    //获取学生信息
{
	Student_Node Student_2=Creat_LinkList();
	Student->Next = Student_2;
	char Student_Number[20];    //建立临时学生学号
	printf("Please enter Student Number: ");    
	scanf("%s[0-9]", Student_Number);
	while (Student_2)    //链表查询学号
	{
		if (strcmp(Student_2->Number, Student_Number) != 0)
			Student_2 = Student_2->Next;
		else
			break;
	}
	if (Student_2 == NULL)   //在链表中加入新学生信息
	{    //读取学号，班级，姓名，性别，年龄，电话，e-mail，出生年月，地址
		strcpy(Student_1->Number, Student_Number);    
		printf("Please enter student class: ");   
		scanf("%s", Student_1->Class);
		printf("Please enter student name: ");    
		scanf("%s", Student_1->Name);
		printf("Please enter student sex: ");
        scanf("%s", Student_1->Sex);
		printf("Please enter student age: ");    
		scanf("%d", &Student_1->Age);
		printf("Please enter student phone number: ");    
		scanf("%s", Student_1->PhoneNumber);
		printf("Please enter student e-mail: ");
		scanf("%s",Student_1->email);
		printf("Please enter student birthday: ");
		scanf("%s",Student_1->Birthday);
		printf("Please enter student address: ");
		scanf("%s",Student_1->Address);
		printf("Added Successfully!\n");
		return 1;
	}
	else
	{
		printf("\nStudent Number %s have saved!\n", Student_Number);
		return 1;
	}
}
void Add_Information(Student_Node Student_head)   //增加学生信息
{
	int Flag;    //设置Flag来查询是否出现已有学号的学生
	Student_Node Student_1 = Creat_LinkList();
	Flag = Get_Infotmation(&Student_head, &Student_1);
	if(Flag)
	{
		Insert_One_Node(&Student_head,&Student_1);
        Display_One_Information(&Student_1);
	}
	return;
}

void InfoModify(Student_Node Student)
{
	Student_Node t;
	t = DisplayInformaticaByStudentNumber(Student);
	if (t)
	{
		printf("Please enter student name:    ");
		scanf("%s", t->Name);
		printf("Please enter student class:    ");
		scanf("%s", t->Class);
		printf("Please enter student sex:     ");
		scanf("%s", t->Sex);
		printf("Please enter student age:     ");
		scanf("%d", &t->Age);
		printf("Please enter student phone number:     ");
		scanf("%s", t->Address);
		printf("Modify Successfully!\n");
	}
}
void DeleteNodeByStudentNumber(Student_Node Student)
{
	char StudentNumber[10];
	Student_Node p, q;
	char flag = 0;
	printf("请输入要删除的学生学号：");
	scanf("%s", StudentNumber);
	p = Student;
	q = Student->Next;
	while (q)
	{
		if (strcmp(q->Number,StudentNumber) == 0)
		{
			p->Next = q->Next;
			free(q);
			flag = 1;
			break;
		}
		p = q;
		q = p->Next;
	}
	if (!flag)
	{
		printf("不存在该学号的学生！\n");
		return;
	}
	printf("陈宫删除！\n");
}
void SaveLinkToFile(Student_Node Student)
{
	Student_Node p;
	FILE *fp;
	p = Student->Next;
	if (p == NULL)
	{
		printf("现在没有学生信息！\n\n");
		return;
	}
	fp = fopen("studnet.txt", "w");
	if (!fp)
	{
		printf("文件不存在！\n");
		return;
	}
	while (p)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t", p->Number, p->Name, p->Class, p->Sex, p->Age, p->PhoneNumber, p->Address);
		p = p->Next;
	}
	fclose(fp);
	printf("文件保存成功！\n");
}
void Display_Menu_SMIS(Student_Node Student_head) //显示菜单，提供选择完成相应功能
{
	int choose;
	int flag = 0, f = 0;
	while (1)
	{
		printf("------------------------------------------\n");
		printf("\nPlease select the appropriate feature \n");
		printf("【1】 Browse Student Information \n");
		printf("【2】 Information query \n");
		printf("【3】 Add Student Information \n");
		printf("【4】 Revise student information \n");
		printf("【5】 Delete Student Information \n");
		printf("【6】 Save Student Information \n");
		printf("【7】 Exit \n");
		printf("Please select:    ");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			Output_Information(Student_head);
			break;
		case 2:
			InforSearch(Student_head);
			break;
		case 3:
			Add_Information(Student_head);
			break;
		case 4:
			InfoModify(Student_head);
			break;
		case 5:
			DeleteNodeByStudentNumber(Student_head);
			break;
		case 6:
			SaveLinkToFile(Student_head);
			break;
		case 7:
			flag = 1; break;
			break;
		default:
			break;
		}
		if (flag == 1) break;
	}
}



void Exit_SMIS(Student_Node H)// 退出程序，保存文件
{
	printf("The program is exiting.Please wait for the program to save.\n");
	Destroy_LinkList(&H);
	exit(0);
}
