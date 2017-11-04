#define _CRT_SECURE_NO_WARNINGS
/*student manAgement information system*/
/*******************************************************************************
1、学生信息管理
（1）问题描述
学生信息包括：学号，姓名，年龄，性别，出生年月，地址，电话，E-mail等。试
设计一学生信息管理系统，使之能提供以下功能：
系统以菜单方式工作
学生信息录入功能（学生信息用文件保存）---输入
学生信息浏览功能---输出
查询、排序功能---算法
1、按学号查询
2、按姓名查询
学生信息的删除与修改（可选项）
（2）功能要求
界面比较美观；
有一定的容错能力，比如输入的成绩不在 0～100 之间，就提示不合法，要求重新
输入；
最好用链表的方式实现。
（3）算法分析
首先，一个学生包括这么多的属性，应该考虑定义一个结构，其次，我们应该考虑数据
的存储形式：是定义一个数组来存储，还是定义一个链表呢？在这里假如我们以数组的方式
来存储，当然可以，但是我们知道，假如我们定义一个数组的话，我们首先必须知道学生人
数大概是多少，以便我们确定数组的大小，但是题目中没有给出，而且题目要求中有大量的
删除、插入操作，所以用链表的方式比较方便。
对于菜单的实现，其实也比较简单，首先我们用 printf 语句把程序的功能列出来，然
后等待用户输入而执行不同的函数，执行完了一个功能后又回到菜单。文件的读写操作大家
参照书中的有关文件的章节。
*******************************************************************************/

/*库文件*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
/*库文件*/

/*定义学生结构*/
typedef struct STUDENT
{
	char Id[10];
	char Name[10];
	char Class[10];
	char Sex[8];
	unsigned short int  Age;
	char Phone[15];
	char Address[50];
	struct STUDENT *Next;
}STUDENT;
/*定义学生结构*/

/*定义全局变量结构*/
STUDENT *link;
/*定义全局变量结构*/

/*函数声明*/
STUDENT * Create_Node();                       //初始化节点
void Read_File();                       //读取文件
void Welcome();
void Display_Menu();                            //显示菜单
int Get_Information(STUDENT *t);              //获取学生信息
void Output_Information();                   //输出学生信息
void Information_Search();                         //搜索信息
void Dispaly_Information_By_Student_Name();          //以学生姓名显示
STUDENT * Display_Information_By_Student_Id();    //以学生学号显示
void Display_One_Node(STUDENT *t);        //显示一条信息
void Information_Modify();              //修改信息
void Insert_One_Node(STUDENT *t);       //插入一条信息
void Delete_By_Student_Id();    //删除信息
void Save_File();              //保存文件
/*函数声明*/

/*主函数*/
int main()
{
	link = Create_Node(); //创造节点
	Read_File();     //读取文件
	Display_Menu();   //显示菜单
	return 0;
}
/*主函数*/

/*初始化节点*/
STUDENT * Create_Node()
{
	STUDENT *p;
	p = (STUDENT *)malloc(sizeof(STUDENT));
	if (p != NULL)
	{
		p->Next = NULL;
		return p;
	}
	else
		return NULL;
}
/*初始化节点*/

//读取文件
void Read_File()
{
	FILE *fp;
	STUDENT *p;
	int flag = 0;     //定义flag
	char string_1[4] = "";
	fp = fopen("student.dat", "r");
	if (!fp)
	{
		printf("Can't find File\n");
		flag = 1;//文件不存在
		while (flag)
		{
			printf("Do you need to create a new file? (Yes/No)\n");    //创建新文件
			if (scanf("%s[a-z-A-Z]", &string_1) == EOF) //限制字母输入
			{
				exit(1); 
			}   
			if (strcmp(string_1, "Yes") == 0 || strcmp(string_1, "yes") == 0 || strcmp(string_1, "Y") == 0 || strcmp(string_1, "y") == 0)//判断Yes
			{
				fp = fopen("student.dat", "w");    //创建空文件
				//fclose(fp);   //关闭文件
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
		printf("Open file successfully!\n");
	p = Create_Node();
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%s%s%d%s%s\n", p->Id, p->Name, p->Class, p->Sex, &p->Age, p->Phone, p->Address);
		if (p != NULL)
			Insert_One_Node(p);
		p = Create_Node();
	}
	fclose(fp);    //关闭文件
}
//读取文件

//欢迎界面
void Welcome()
{
	printf("*******************************************************************************************\n");
	printf("***************************** Welcome to use SMIS Demo ************************************\n");
	printf("***************************** Copyright by Steven Wang ************************************\n");//版权
	printf("*******************************************************************************************\n");
	return;
}
//欢迎界面

//插入一条信息
void Insert_One_Node(STUDENT *t)
{
	STUDENT *p;
	p = link;
	while (p->Next)
		p = p->Next;
	p->Next = t;
	return;
}
//插入一条信息

//输出学生信息
void Output_Information()
{
	STUDENT *p;
	p = link->Next;
	if (p == NULL)
	{
		printf("No student information now, please input student information first!\n\n");
		return;
	}
	printf("Id\tName\tClass\tSex\tAge\tPhone\t\tAdress\n");
	while (p)
	{
		Display_One_Node(p);
		p = p->Next;
	}
}
//输出学生信息

//显示一条信息
void Display_One_Node(STUDENT *t)
{
	printf("%s\t", t->Id);
	printf("%s\t", t->Name);
	printf("%s\t", t->Class);
	printf("%s\t", t->Sex);
	printf("%d\t", t->Age);
	printf("%s\t\t", t->Phone);
	printf("%s\t", t->Address);
	printf("\n");
}
//显示一条信息

//显示菜单
void Display_Menu()
{
	STUDENT *p;
	int choose=0;
	int flag = 0, f = 0;
	Welcome();       //欢迎界面
	while (1)
	{
		printf("\n------------------------Please select the appropriate function-----------------------------\n\n");
		printf("[1] View student information\n");
		printf("[2] Information query\n");
		printf("[3] Add student information\n");
		printf("[4] Modify student information\n");
		printf("[5] Delete student information\n");
		printf("[6] Save student information\n");
		printf("[7] Exit\n\n");
		printf("\nPlease select：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			Output_Information();
			break;
		case 2:
			Information_Search();
			break;
		case 3:
			p = Create_Node();
			f = Get_Information(p);
			if (f)
			{
				Insert_One_Node(p);
				printf("Id\tName\tClass\tSex\tAge\tPhone\t\tAdress\n");
				Display_One_Node(p);
			}
			break;
		case 4:
			Information_Modify();
			break;
		case 5:
			Delete_By_Student_Id();
			break;
		case 6:
			Save_File();
			break;
		case 7:
			flag = 1;
			break;
		default:
			printf("Illegal input!\n");//弹出错误警告
			break;
		}
		if (flag == 1)
			break;
	}
}
//显示菜单

//搜索信息
void Information_Search()
{
	int ch=0, flag=1;
	printf("\n1 According to the name check\n2 According to the student id to check\n ");
	printf("\n\n Please select：");
	while (flag) 
	{
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			Dispaly_Information_By_Student_Name();
			flag = 0;
			break;
		case 2:
			Display_Information_By_Student_Id();
			flag = 0;
			break;
		default:
			printf("Illegal input!\n");
			break;
		}
	}
	return;
}
//搜索信息

//以学生姓名显示
void Dispaly_Information_By_Student_Name()
{
	STUDENT *p;
	char Name[20];
	char flag = 0;
	p = link->Next;
	printf("Please enter the student name：");
	scanf("%s", Name);
	while (p)
	{
		if (strcmp(p->Name, Name) == 0)
		{
			if(flag==0)
			      printf("Id\tName\tClass\tSex\tAge\tPhone\t\tAdress\t\n");
			Display_One_Node(p);
			flag = 1;
		}
		    p = p->Next;
	}
	if (!flag)
	{
		printf("Sorry, there is no student named %s!\n", Name);
	}
}
//以学生姓名显示

//以学生学号显示
STUDENT * Display_Information_By_Student_Id()
{
	STUDENT *p;
	char studentNum[20];
	char flag = 0;
	p = link->Next;
	printf("Please enter the student id：");
	scanf("%s", studentNum);
	while (p)
	{
		if (strcmp(p->Id, studentNum) == 0)
		{
			printf("Id\tName\tClass\tSex\tAge\tPhone\tAdress\t\n");
			Display_One_Node(p);
			flag = 1;
			break;
		}
		p = p->Next;
	}
	if (!flag)
	{
		printf("I'm sorry, there's no student with a student id of %s！\n", studentNum);
		return NULL;
	}
	return p;
}
//以学生学号显示

//获取学生信息
int Get_Information(STUDENT *t)
{
	char num[10];
	int flag = 1;
	STUDENT *p = link->Next;
	printf("Please enter the student number：");
	scanf("%s", num);
	while (p)
	{
		if (strcmp(p->Id, num) != 0)
		{
			p = p->Next;
		}
		else
		{
			break;
		}
	}
	if (p == NULL)
	{
		strcpy(t->Id, num);
		printf("Please enter the student name:");
		scanf("%s", t->Name);
		printf("Please enter the class of this student:");
		scanf("%s", t->Class);
		while (flag)
		{
			printf("Please enter the Sex of the student:(Female Or Male)");
			scanf("%s", t->Sex);
			if (strcmp(t->Sex, "Female") == 0 || strcmp(t->Sex, "female") == 0 || strcmp(t->Sex, "F") == 0 || strcmp(t->Sex, "f") == 0 || strcmp(t->Sex, "Male") == 0 || strcmp(t->Sex, "male") == 0 || strcmp(t->Sex, "M") == 0 || strcmp(t->Sex, "m") == 0)
				flag = 0;
			else
			printf("Illegal input!\n");
		}
		flag = 1;
		while (flag) 
		{
            printf("Please enter the Age of the student:");
			scanf("%u", &t->Age);
			if (t->Age>=12&&t->Age<=60) 
			{
				flag = 0;
			}
			else
			printf("Illegal input!\n");
		}
		printf("Please enter the phone of the student:");
		scanf("%s", t->Phone);
		printf("Please enter the Address of the student:");
		scanf("%s", t->Address);
		printf("Add success!\n");
		return 1;
	}
	else
	{
		printf("The student number of %s already exists!\n", num);
		return 0;
	}
}
//获取学生信息

//修改信息
void Information_Modify()
{
	STUDENT *p;
	int flag = 1;
	p = Display_Information_By_Student_Id();
	if (p)
	{
		printf("Please enter the student name:");
		scanf("%s", p->Name);
		printf("Please enter the class of this student:");
		scanf("%s", p->Class);
		while (flag)
		{
			printf("Please enter the Sex of the student:(Female Or Male)");
			scanf("%s", p->Sex);
			if (strcmp(p->Sex, "Female") == 0 || strcmp(p->Sex, "female") == 0 || strcmp(p->Sex, "F") == 0 || strcmp(p->Sex, "f") == 0 || strcmp(p->Sex, "Male") == 0 || strcmp(p->Sex, "male") == 0 || strcmp(p->Sex, "M") == 0 || strcmp(p->Sex, "m") == 0)
				flag = 0;
			else
			printf("Illegal input!\n");
		}
		flag = 1;
		while (flag)
		{
			printf("Please enter the Age of the student:");
			scanf("%u", &p->Age);
			if (p->Age >= 12 && p->Age <= 60)
			{
				flag = 0;
			}
			else
			printf("Illegal input!\n");
		}
		printf("Please enter the phone of the student:");
		scanf("%s", p->Phone);
		printf("Please enter the Address of the student:");
		scanf("%s", p->Address);
		printf("Modify the success!\n");
	}
}
//修改信息

//删除信息
void Delete_By_Student_Id()
{
	char Id[10];
	STUDENT *p, *q;
	char flag = 0;
	printf("Please enter the student id to delete：");
	scanf("%s", Id);
	p = link;
	q = link->Next;
	while (p)
	{
		if (strcmp(q->Id, Id) == 0)
		{
			p->Next = q->Next;
			free(q);
			flag = 1;
			break;
		}
		p = q;
		q = q->Next;
	}
	if (!flag)
	{
		printf("There is no student of the student number.");
		return;
	}
	printf("Delete successfully!\n");
}
//删除信息

//保存文件
void Save_File()
{
	STUDENT *p;
	FILE *fp;
	p = link->Next;
	if (p == NULL)
	{
		printf("No student information now, please input student information first!\n\n");
		return;
	}
	fp = fopen("student.dat", "w");
	if (!fp)
	{
		printf("The file does not exist!\n");
		return;
	}
	while (p)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%u\t%s\t%s\t\n", p->Id, p->Name, p->Class, p->Sex, p->Age, p->Phone, p->Address);
		p = p->Next;
	}
	fclose(fp);
	printf("File saved successfully!\n");
}
//保存文件
