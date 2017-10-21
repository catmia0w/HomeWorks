/*student management information system*/
/*******************************************************************************
学生信息管理系统函数库
void Initialize_SMIS() 初始化学生信息管理系统
void Welcome_SMIS() 欢迎界面
*******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

typedef struct Student      //建立单链表
{
	char StudentNumber[20]; //学号
	char StudentName[20];   //姓名
	unsigned short int Age; //年龄
	char Sex[4];            //性别
	char Birthday[15];      //出生年月
	char Addr[50];          //地址
	char ClassName[20];     //班级
	char PhoneNumber[11];   //电话
	char email[25];         //e-mail
	struct Student * Next;  //指向下一个节点的位置
}Student, *Student_Link;

void hello()；
Student_Link Creat_LinkList(void)；        //初始化单链表
void Destroy_LinkList(Student_Link *H)；   //销毁单链表
void Initialize_SMIS()；                   //初始化学生信息管理系统
void Welcome_SMIS()；                      //欢迎界面
void OutPutInformation()；
void InforSearch()；
void DisplayMenu_SMIS()；                  //显示菜单，提供选择完成相应功能
void Exit_SMIS(Student_Link H)；           // 退出程序，保存文件

void hello()
{
	printf("Hello World!\n");
}

Student_Link Creat_LinkList(void)  
{
	Student_Link H;
	H = (Student_Link)malloc(sizeof(Student));
	if (H)
		H->Next = NULL;
	return H;
}

void Destroy_LinkList(Student_Link *H)   //销毁单链表
{
	Student_Link p, q;
	p = *H;
	while (p) 
	{
		q = p;
		p = p->Next;
		free(q);
	}
	*H = NULL;
}

void Initialize_SMIS()//初始化学生信息管理系统
{
    printf("初始化中.......\n");
}

void Welcome_SMIS()//欢迎界面
{
	printf("***********************************************************\n");
    printf("Welcome to use SMIS(Student Management Information System)\n");
	printf("The Software maked by Steven Wang from AHUT.\n");
	printf("***********************************************************\n");
}

void OutPutInformation()
{
	printf("AAAAAAAAAAAAAA");
}
void InforSearch()
{
	printf("hhhhhhhhhhhhh");
}
void DisplayMenu_SMIS() //显示菜单，提供选择完成相应功能
{
	int choose;
	int flag=0,f=0;
	while(1)
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
		printf("Please select:  \n");
		printf("\n");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
			     OutPutInformation();
				 break;
		    case 2:
			     InforSearch();
				 break;
		    case 3:
			     break;
		    case 4:
			     break;
		    case 5:
			     break;
			case 6:
			     break;
			case 7:
			     break;
			default:
			    break;
		}
		if(flag==1) break;
	}
}



void Exit_SMIS(Student_Link H)// 退出程序，保存文件
{
	printf("The program is exiting.Please wait for the program to save.\n");
	Destroy_LinkList(&H);
	exit(0);
}


