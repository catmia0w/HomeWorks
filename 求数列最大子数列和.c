// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
int MaxSubseqSum(int A[], int N)
{
	int ThisSum,MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (i=0;i<N;i++)
	{
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;

}

int main()
{
	int *array = 0, num, i;
	scanf("%d", &num);
	array = (int *)malloc(sizeof(int)*num);
    for (i = 0; i < num; i++)
	scanf("%d", &array[i]);
	num=MaxSubseqSum(array,num);

	free(array);
	printf("%d",num);
    return 0;
}

