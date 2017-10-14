
/*假设称正读和反读都相同的字符序列为“回文”，例如，“abcddcba”、 “qwerewq”是回文，“ashgash”不是回文。试写一个算法判断读入的一个以‘@’为结束符的字符序列是否为回文。*/

#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 100 
typedef struct
{
	char stack[MAXSIZE];
	int  top;
}stackstru;  


typedef struct {
	char queue[MAXSIZE];
	int  front;
	int  rear;
}queuestru; 


int  main()
{
	int stinit(stackstru *s);         
	int stempty(stackstru *s);        
	int stpush(stackstru *s, char x);  
	char stpop(stackstru *s);         
	int quinit(queuestru *q);         
	int quempty(queuestru *q);        
	int enqueue(queuestru *q, char e); 
	char dequeue(queuestru *q);       

	char c;
	int flag = 0;
	stackstru *s = (stackstru *)malloc(sizeof(stackstru)); 
	queuestru *q = (queuestru *)malloc(sizeof(queuestru)); 
	stinit(s);   
	quinit(q);   
	printf("Input a string:\n");
	while ((c = getchar()) != '@')   
	{
		stpush(s, c);              
		enqueue(q, c);             
	}
	while (stempty(s))           
	{
		if (stpop(s) == dequeue(q))  
		{
			flag = 1;                 
			continue;               
		}
		else                     
		{
			flag = 0;
			break;                  
		}
	}
	if (flag == 1)
		printf("This string is palindrome!\n"); 

	else
		printf("This string isn't palindrome!\n");
	return 0;
}


int stinit(stackstru *s)
{
	s->top = 0;
	return 1;
}           

int stempty(stackstru *s)
{
	if (s->top == 0)                         
	{
		return 0;
	}
	else
	{
		return 1;
	}
}           

int stpush(stackstru *s, char x)
{
	if (s->top == m)                          
	{
		printf("The stack is overflow!\n"); 
		return 0;
	}
	else                                   
	{
		s->top = s->top + 1;                    
		s->stack[s->top] = x;                 
		return 1;
	}
}          

char stpop(stackstru *s)
{
	char y;
	if (s->top == 0)                          
	{
		printf("The stack is empty!\n");     
		return ' ';                          
	}
	else                                   
	{
		y = s->stack[s->top];                  
		s->top = s->top - 1;                     
		return y;
	}
}         





int quinit(queuestru *q)
{
	q->front = 0;
	q->rear = 0;
	return 1;
}          

int quempty(queuestru *q)
{
	if (q->front == q->rear)                 
	{
		return 0;
	}
	else
	{
		return 1;
	}
}          


int enqueue(queuestru *q, char e)
{
	if ((q->rear + 1) % m == q->front)           
	{
		printf("The queue is overflow!\n"); 
		return 0;
	}
	else
	{
		q->queue[q->rear] = e;                
		q->rear = (q->rear + 1) % MAXSIZE;              
		return 1;
	}
}         



char dequeue(queuestru *q)
{
	char f;
	if (q->front == q->rear)                  
	{
		printf("The queue is empty!\n");    
		return 0;
	}
	else
	{
		f = q->queue[q->front];               
		q->front = (q->front + 1) % MAXSIZE;            
		return f;
	}
}        
