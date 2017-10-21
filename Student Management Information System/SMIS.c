/*student management information system*/
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
#include "SMIS.h"    //学生信息管理系统函数库文件

int main()           //主函数入口
{ 
    Student_Link Student = Creat_LinkList();    //初始化全局变量 单链表
	Initialize_SMIS();                          //初始化学生信息管理系统
	Welcome_SMIS();                             //欢迎界面
	DisplayMenu_SMIS();
	/*
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
	printf("\n");*/
	hello();
	Exit_SMIS(Student);// 退出程序，保存文件
	return 0;
}
