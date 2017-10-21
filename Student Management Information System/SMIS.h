/*student management information system*/
/*******************************************************************************
学生信息管理系统函数库
void Initialize_SMIS() 初始化学生信息管理系统
void Welcome_SMIS() 欢迎界面
*******************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

void hello()
{
	printf("Hello World!");
	printf("\n");
}

typedef struct node   //定义单链表数据结构
{
	int data;
	struct node * next;
}LNode, *LinkList;

LinkList Creat_LinkList(void)   //创建单链表
{
	LinkList M;
	M = (LinkList)malloc(sizeof(LNode));
	if (M)
		M->next = NULL;
	return M;
}

void Destroy_LinkList(LinkList *H)   //销毁单链表
{
	LinkList p, q;
	p = *H;
	while (p) 
	{
		q = p;
		p = p->next;
		free(q);
	}
	*H = NULL;
}

void Find_Min(LinkList A)
{
	int x;
	LinkList pa, first, min;
	first = A->next;
	min = A->next;
	pa = min->next;
	while (pa != NULL)
	{
		if (pa->data < min->data)
			min = pa;
		pa = pa->next;
	}
	x = first->data;
	first->data = min->data;
	min->data = x;

}


void Initialize_SMIS()//初始化学生信息管理系统
{
    printf("初始化中.......");
	printf("\n");
    extern LinkList H = Creat_LinkList();//初始化全局变量 单链表
}

void Welcome_SMIS()//欢迎界面
{
	printf("***********************************************************");
	printf("\n");
    printf("Welcome to use SMIS(Student Management Information System)");
	printf("\n");
	printf("The Software maked by Steven Wang from AHUT.");
	printf("\n");
	printf("***********************************************************");
	printf("\n");
}
void L()
{
int n = 0,m=0,i;
	LinkList p, q;
	q = H;
	scanf("%d", &n);
	for (i=0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		q->next = p;
		q = q->next;
		p->next = NULL;
	}	
	Find_Min(H);
	p = H->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void Exit_SMIS()// 退出程序，保存文件
{
	printf("The program is exiting.Please wait for the program to save.");
	printf("\n");
	Destroy_LinkList(&H);
	exit(0);
}


