//2．已知非空线性链表由list指出，链结点的构造为（data,next），请写一算法，将链表中数据域值最小的那个结点移到链表的最前面。要求：不得额外申请新的结点。
//

#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
	int data;
	struct node * next;
}LNode, *LinkList;

LinkList Creat_LinkList(void)
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (H)
		H->next = NULL;
	return H;
}



void Destroy_LinkList(LinkList *H)
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
int main()
{
	LinkList H = Creat_LinkList();
	int n = 0,m=0,i;
	LinkList p, q;
	q = H;
	scanf_s("%d", &n);
	for (i=0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);
		q->next = p;
		q = q->next;	p->next = NULL;
	}	
	Find_Min(H);
	p = H->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	Destroy_LinkList(&H);
	return 0;
}

