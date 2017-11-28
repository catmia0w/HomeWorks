// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include "iostream"
#include "time.h"  
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

void Solve_NQueen_math()
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

/* 
** 目前最快的N皇后递归解决方法 
** N Queens Problem 
** 试探-回溯算法，递归实现 
*/  

  
// sum用来记录皇后放置成功的不同布局数；upperlim用来标记所有列都已经放置好了皇后。  
long sum = 0, upperlim = 1;       
  
// 试探算法从最右边的列开始。  
void test(long row, long ld, long rd)  
{  
    if (row != upperlim)  
    {  
        // row，ld，rd进行“或”运算，求得所有可以放置皇后的列,对应位为0，  
        // 然后再取反后“与”上全1的数，来求得当前所有可以放置皇后的位置，对应列改为1  
        // 也就是求取当前哪些列可以放置皇后  
        long pos = upperlim & ~(row | ld | rd);   
        while (pos)    // 0 -- 皇后没有地方可放，回溯  
        {  
            // 拷贝pos最右边为1的bit，其余bit置0  
            // 也就是取得可以放皇后的最右边的列  
            long p = pos & -pos;                                                
  
            // 将pos最右边为1的bit清零  
            // 也就是为获取下一次的最右可用列使用做准备，  
            // 程序将来会回溯到这个位置继续试探  
            pos -= p;                             
  
            // row + p，将当前列置1，表示记录这次皇后放置的列。  
            // (ld + p) << 1，标记当前皇后左边相邻的列不允许下一个皇后放置。  
            // (ld + p) >> 1，标记当前皇后右边相邻的列不允许下一个皇后放置。  
            // 此处的移位操作实际上是记录对角线上的限制，只是因为问题都化归  
            // 到一行网格上来解决，所以表示为列的限制就可以了。显然，随着移位  
            // 在每次选择列之前进行，原来N×N网格中某个已放置的皇后针对其对角线  
            // 上产生的限制都被记录下来了  
            test(row + p, (ld + p) << 1, (rd + p) >> 1);                                
        }  
    }  
    else     
    {  
        // row的所有位都为1，即找到了一个成功的布局，回溯  
        sum++;  
    }  
}  
  
void Solve_NQueen_bit()  
{  
     
    int n = 16;  
  
    if (argc != 1)  
        n = atoi(argv[1]);  
    tm = time(0);  
  
    // 因为整型数的限制，最大只能32位，  
    // 如果想处理N大于32的皇后问题，需要  
    // 用bitset数据结构进行存储  
    if ((n < 1) || (n > 32))                   
    {  
        printf(" 只能计算1-32之间\n");  
        exit(-1);  
    }  
    printf("%d 皇后\n", n);  
  
    // N个皇后只需N位存储，N列中某列有皇后则对应bit置1。  
    upperlim = (upperlim << n) - 1;           
  
    test(0, 0, 0);  
    printf("共有%ld种排列, 计算时间%d秒 \n", sum, (int) (time(0) - tm));  
    system("pause");  
    return 0;  
}  
int main(int argc, char *argv[])
{
	int i,flag=1;
	time_t tm; 
	printf("---------------------Welcome to Eight queen problems demo.-----------------------\n");
	printf("请选择解决问题的方式：\n");
	printf("1.数学解决\n");
	printf("2.位运算解决\n");
	cin>>i;
	while (flag)
	{
		switch (i)
		{
		case 1:
			Solve_NQueen_math();
			flag = 0;
			break;
		case 2:
			Solve_NQueen_bit();
			flag=0;
			break;	
		default:
			break;
		}
	}
    return 0;
}
