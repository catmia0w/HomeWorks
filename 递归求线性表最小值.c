/*线性表中元素存放在向量A[n]中，元素是整型数。试写出递归算法求出A中的最大和最小元素。*/

#include "stdio.h"
#include "stdlib.h"
int max = 0;
int min = 0;
int run(int *p,int m,int i)
{
	int n;
	n = *p;
	if (n>max) 
	{
		max = n;
	}
	if (n < min)
	{
		min = n;
	}
	i++;
	if (i==m) 
	{
		return 0;
	}
	run((p + 1),m,i);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int *p = (int *)calloc(n, sizeof(int));//申请了一个长度为n的数组，用p指向首地址
	for (i = 0; i<n; i++)//位数组元素赋值
	{
		scanf("%d", p + i);
	}
	max = *p;
	min = max;
	i = 0;
	run(p,n,i);
	printf(" Max=%d,Min=%d",max,min);
	free(p);//释放申请的内存空间
	return 0;
}
