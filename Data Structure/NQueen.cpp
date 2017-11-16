// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>

using namespace std;
int Number = 0;
//
//void Print()
//{
//	int* p = new int[Number*Number];
//	int i, j;
//	for (i = 0; i < Number; i++) 
//	{
//		for (j = 0, j < Number; j++) 
//		{
//            printf("%d ", p[i+j]);
//		}
//		printf("\n");
//	}
//	delete []p;
//	return;
//}
inline void Printf(int n)
{
	Number++;
	printf("(%d,%d)  ",Number,n);
	return;
}

void Solve_NQueen()
{
	printf("开始运算：\n");
	int n ;
	int k;
	printf("请输入你想要完成的N*N盘N皇后问题：");
	cin >> n ;
	if (n < 3)
	{
		printf("N太小无法完成\n");
		return;
	}
	cout << endl;
	if (n % 6 != 2 && n % 6 != 3)
	{
		for (int i = 2; i <= n; i += 2)
			Printf(i);
		for (int i = 1; i <= n; i += 2)
			Printf(i);
	}
	else
	{
		k = n / 2;
		if (k % 2 == 0) 
		{
			for (int i = k; i <= n; i += 2)
				Printf(i);
			for (int i = 2; i <= k - 2; i += 2)
				Printf(i);
			for (int i = k + 3; i <= n - 1; i += 2)
				Printf(i);
			for (int i = 1; i <= k + 1; i += 2)
				Printf(i);
			if (n % 2 == 1)
				Printf(n);
		}
			else
			{
				for (int i = k; i <= n - 1; i += 2)
					Printf(i);
				for (int i = 1; i <= k - 2; i += 2)
					Printf(i);
				for (int i = k + 3; i <= n; i += 2)
					Printf(i);
				for (int i = 2; i <= k + 1; i += 2)
					Printf(i);
				if (n % 2 == 1)
					Printf(n);
			}
		}
	printf("\n");
	//Print();
	return;
}


int main()
{
	int i,flag=1;
	printf("---------------------Welcome to Eight queen problems demo.-----------------------\n");
	printf("请选择解决问题的方式：\n");
	printf("1.数学解决\n");
	cin>>i;
	while (flag)
	{
		switch (i)
		{
		case 1:
			Solve_NQueen();
			flag = 0;
			break;
		default:
			break;
		}
	}
    return 0;
}
