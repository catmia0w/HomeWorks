
#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#define	MAXSIZE 100


typedef struct node
{
	int data[MAXSIZE];
	int length;
}SeqList, *PSeqList;

PSeqList Init_SeqList(void)
{
	PSeqList PL;
	PL = (PSeqList)malloc(sizeof(SeqList));
	if (PL)
		PL->length = 0;
	return (PL);
}

void divide(PSeqList PL)
{
	int low=0, high=0, tmp = 0;
	high = PL->length - 1;
	while (low < high)
	{
		while (low < high && PL->data[high] >= 0) high--;
		while (low < high && PL->data[low] < 0) low++;
		if (low < high)
		{
			tmp = PL->data[low];
			PL->data[low] = PL->data[high];
			PL->data[high] = tmp;
		}
	}
}
int main()
{
	PSeqList PL= Init_SeqList();
	scanf_s("%d", &PL->length);
		for (int i = 0; i < PL->length; i++)
		{
			scanf_s("%d", &PL->data[i]);
		}
	
	divide(PL);
	for (int i = 0; i < PL->length; i++)
	{
		printf("%d ", PL->data[i]);
	}

	return 0;
}

