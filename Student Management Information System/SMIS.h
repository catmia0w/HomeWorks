/*student management information system*/
/*******************************************************************************
学生信息管理系统函数库
void Initialize_SMIS() 初始化学生信息管理系统
void Welcome_SMIS() 欢迎界面
*******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "string.h"

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
Student *link;

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
void InsertOneNode(Student_Link t)
{
     Student_Link p;
	 p=link;
	 while(p->Next)
		 p=p->Next;
	 p->Next=t;
}
void ReadInformationFile()
{
	FILE *fp;
	Student_Link p;
	fp=fopen("student.txt","r");
	if(!fp)
	{
		printf("Can't find File\n");
		return ;
	}
	else 
		printf("Open File Successfully!\n ");
	p=Creat_LinkList();
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%s%d%s%s\n",p->StudentNumber,p->StudentName,p->ClassName,p->Sex,&p->Age,p->Addr);
		if(p!=NULL)
			InsertOneNode(p);
		p=Creat_LinkList();
	}
	fclose(fp);
}
void Initialize_SMIS()//初始化学生信息管理系统
{
    printf("初始化中.......\n");
	ReadInformationFile();
}

void Welcome_SMIS()//欢迎界面
{
	printf("***********************************************************\n");
    printf("Welcome to use SMIS(Student Management Information System)\n");
	printf("The Software maked by Steven Wang from AHUT.\n");
	printf("***********************************************************\n");
}
void DisplayOneInformation(Student_Link t)
{
	printf("%s\t",t->StudentNumber);
	printf("%s\t",t->StudentName);
	printf("%s\t",t->ClassName);
	printf("%s\t",t->Sex);
	printf("%d\t",t->Age);
	printf("%s\t",t->PhoneNumber);
	printf("%s\t",t->Addr);
	printf("\n");
}
void OutputInformation(Student_Link Student)
{
	Student_Link p;
	p=Student->Next;
	if(p==NULL)
	{
		printf("Sorry,No Student Information, Please enter Student Information:\n");
		return;
	}
	printf("StudentNumber/t StudentName/t ClassName/t Sex/t Age/t PhoneNumber/t Addr/t \n");
	while(p)
	{
		DisplayOneInformation(p);
		p=p->Next;
	}
}
void DisplayInformaticaByStudentName()
{
	Student_Link p;
	char StudentName[20];
	char flag=0;
	p=link->Next;
	printf("请输入学生姓名：");
	scanf("%s",StudentName);
	while(p)
	{
		if(strcmp(p->StudentName,StudentName)==0)
		{
			printf("学号\t 姓名\t 班级\t 性别\t 年龄\t 电话\t 地址\t \n");
			DisplayOneInformation(p);
			flag=1;
			break;
		}
		p=p->Next;
	}
    if(!flag)
		printf("对不起，不存在姓名为%s 的学生！\n",StudentName);
}
Student_Link DisplayInformaticaByStudentNumber()
{
	Student_Link p;
	char StudentNumber[20];
	char flag=0;
	p=link->Next;
	printf("请输入学生学号：");
	scanf("%s",StudentNumber);
	while(p)
	{
		if(strcmp(p->StudentNumber,StudentNumber)==0)
		{
			printf("学号\t 姓名\t 班级\t 性别\t 年龄\t 电话\t 地址\t \n");
			DisplayOneInformation(p);
			flag=1;
			break;
		}
		p=p->Next;
	}
    if(!flag)
	{
		printf("对不起，不存在学号为%s 的学生！\n",StudentNumber);
	    return NULL;
	}
	return p;
}
void InforSearch()
{
	int ch;
	printf("\n1按姓名查\n2按学号查\n");
	printf("\n\n请选择：");
	scanf("%d",&ch);
	switch(ch){
        case 1: DisplayInformaticaByStudentName();  break;
	    case 2: DisplayInformaticaByStudentNumber(); break;
		default: break;
	}
}
int GetInfotmation(Student_Link t)
{
	Student_Link p=link->Next;
	char num[20];
	printf("Please enter Student Number:");
	scanf("%s",num);
	while(p)
	{
		if(strcmp(p->StudentNumber,num)!=0)
			p=p->Next;
		else
			break;
	}
	if(p==NULL)
	{
		strcpy(t->StudentNumber,num);
		printf("Please enter student name:    ");
		scanf("%s",t->StudentName);
		printf("Please enter student class:    ");
		scanf("%s",t->ClassName);
		printf("Please enter student sex:     ");
		scanf("%s",t->Sex);
		printf("Please enter student age:     ");
		scanf("%d",&t->Age);
		printf("Please enter student phone number:     ");
		scanf("%s",t->Addr);
		printf("Added Successfully!\n");
		return 1;
	}
	else 
	{
		printf("Student Number %s have saved!\n",num);
	    return 1;
	}
}
void AddInformation(Student_Link p)
{
	int f;
	p=Creat_LinkList();
	f=GetInfotmation(p);
	if(f)
	{
		InsertOneNode(p);
		OutputInformation(p);
	}
}

void InfoModify()
{
	Student_Link t;
	t=DisplayInformaticaByStudentNumber();
	if(t)
	{
		printf("Please enter student name:    ");
		scanf("%s",t->StudentName);
		printf("Please enter student class:    ");
		scanf("%s",t->ClassName);
		printf("Please enter student sex:     ");
		scanf("%s",t->Sex);
		printf("Please enter student age:     ");
		scanf("%d",&t->Age);
		printf("Please enter student phone number:     ");
		scanf("%s",t->Addr);
		printf("Modify Successfully!\n");
	}
}
void DeleteNodeByStudentNumber()
{
	char StudentNumber[10];
	Student_Link p,q;
	char flag=0;
	printf("请输入要删除的学生学号：");
	scanf("%s",StudentNumber);
	p=link;
	q=link->Next;
	while(q)
	{
		if(strcmp(q->StudentNumber,StudentNumber)==0)
		{
			p->Next=q->Next;
			free(q);
			flag=1;
			break;
		}
		p=q;
		q=p->Next;
	}
	if(!flag)
	{
		printf("不存在该学号的学生！\n");
		return;
	}
	printf("陈宫删除！\n");
}
void SaveLinkToFile()
{
	Student_Link p;
	FILE *fp;
	p=link->Next;
	if(p==NULL)
	{
		printf("现在没有学生信息！\n\n");
		return;
	}
	fp=fopen("studnet.txt","w");
	if(!fp)
	{
		printf("文件不存在！\n");
		return;
	}
	while(p)
	{
		fprintf(fp,"%s\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t",p->StudentNumber,p->StudentName,p->ClassName,p->Sex,p->Age,p->PhoneNumber,p->Addr);
		p=p->Next;
	}
	fclose(fp);
	printf("文件保存成功！\n");
}
void DisplayMenu_SMIS(Student_Link Student) //显示菜单，提供选择完成相应功能
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
		printf("Please select:    ");
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
			     OutputInformation(Student);
				 break;
		    case 2:
			     InforSearch();
				 break;
		    case 3:
			    AddInformation(Student);
			    break;
		    case 4:
			    InfoModify();
			    break;
		    case 5:
			    DeleteNodeByStudentNumber();
			    break;
			case 6:
			    SaveLinkToFile();
			    break;
			case 7:
			    flag=1;break;
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
