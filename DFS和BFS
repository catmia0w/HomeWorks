#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#define MaxVertexNum 30
#define NULL 0
typedef char VertexType;
typedef int Edgetype;
typedef int InfoType ;
//邻接矩阵
typedef struct 
{
	VertexType vertexs[MaxVertexNum];
	Edgetype arcs[MaxVertexNum][MaxVertexNum];
	int vertexNum, edgeNum;
}MGraph;

void CreatGraph(MGraph *G)
{
	int i, j, k;
	scanf("%d,%d",&(G->vertexNum),&(G->edgeNum));
	getchar();
	for (i = 0; i < G->vertexNum; i++)
		scanf("%c",&(G->vertexs [i]));
	for (i = 0; i < G->vertexNum; i++)
		for (j = 0; j < G->vertexNum; j++)
			G->arcs[i][j] = 0;
	for (k = 0; k < G->edgeNum; k++)
	{
		scanf("%d,%d",&i,&j);
		G->arcs[i][j] = 1;
	}
}
//邻接表
typedef struct node 
{
	int adjvertex;
	InfoType info;
	struct node *next;
}EdgeNode;
typedef struct vnode 
{
	VertexType vertex;
	EdgeNode * firstedge;
}VertexNode;
typedef struct 
{
	VertexNode adjlist[MaxVertexNum];
	int vertexNum, edgeNum;
}ALGraph;

void CreateALGraph(ALGraph *G) 
{
	int i, j, k;
	EdgeNode *p;
	scanf("%d,%d",&(G->vertexNum),&(G->edgeNum));
	for (i = 0; i < G->vertexNum; i++) 
	{
		scanf("%c",&(G->adjlist[i].vertex));
		G->adjlist[i].firstedge = NULL;
	}
	for (k=0;k<G->edgeNum;k++)
	{
		scanf("%d,%d",&i,&j);
		p = (EdgeNode *)malloc(sizeof(EdgeNode));
		p->adjvertex = j;
		p->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = p;
	}
}

typedef enum {False,True}boolean;
boolean visited[MaxVertexNum];

int IsPath_DFS(MGraph *G,int i,int j) 
{
	int k;
	visited[i] = True;
	for (k = 0; k < G->vertexNum; k++)
		if (G->arcs[i][k] == 1 && !visited[k])
			if (k == j) return 1;
			else return IsPath_DFS(G,k,j);
			return 0;
}
int IsPath_DFS1(ALGraph *G, int i,int j) 
{
	EdgeNode *p;
	visited[i] = True;
	p = G->adjlist[i].firstedge;
	while (p) 
	{
		if (!visited[p->adjvertex]) 
		{
			if (p->adjvertex == j)
				return 1;
			else
				return IsPath_DFS1(G, p->adjvertex, j);
		}
		p=p->next;
	}
	return 0;
}
//队列
typedef struct 
{
	char data[100];
	int front, rear;
}SeqQueue,*PSeqQueue;

PSeqQueue Init_SeqQueue() 
{
	PSeqQueue Q;
	Q = (PSeqQueue)malloc(sizeof(SeqQueue));
	if (Q) 
	{
		Q->front = 0;
		Q->rear = 0;
	}
	return Q;
}
int Empty_SeqQueue(PSeqQueue Q)
{
	if (Q&&Q->front == Q->rear)
		return (1);
	else
		return (0);
}
int In_SeqQueue(PSeqQueue Q, char x) 
{
	if ((Q->rear + 1) % 100 == Q->front)
	{
		printf("队满");
		return -1;
	}
	else
	{
		Q->rear = (Q->rear + 1) % 100;
		Q->data[Q->rear] = x;
		return 1;
	}
}
int Out_SeqQueue(PSeqQueue Q,int *x)
{
	if (Empty_SeqQueue(Q))
	{
		printf("队空");
		return -1;
	}
	else 
	{
		Q->front = (Q->front + 1) % 100;
		*x = Q->data[Q->front];
		return 1;
	}
}
int IsPath_BFS(MGraph *G, int i, int j)
{
	int k;
	PSeqQueue Q;
	Q = Init_SeqQueue();
	visited[i] = True;
	In_SeqQueue(Q,1);
	while (!Empty_SeqQueue(Q)) 
	{
		Out_SeqQueue(Q, &i);
		for (k = 0; k < G->vertexNum; k++)
			if (G->arcs[i][k] == 1 && !visited[k])
			{
				if (k == j) return 1;
				visited[k] = True;
				In_SeqQueue(Q,k);
			}
	}
	return 0;
}

int IsPath_BFS1(ALGraph *G, int i, int j)
{
	EdgeNode *p;
	PSeqQueue Q;
	Q = Init_SeqQueue();
	visited[i] = True;
	In_SeqQueue(Q,j);
	while (!Empty_SeqQueue(Q))
	{
		Out_SeqQueue(Q, &i);
		p = G->adjlist[i].firstedge;
		for(;p!=NULL;p=p->next)
			if (!visited[p->adjvertex])
			{
				if (p->adjvertex == j)
					return 1;
				visited[p->adjvertex] = True;
				In_SeqQueue(Q, p->adjvertex);
			}
	}
	return 0;
}

int main()
{
	MGraph G;
	ALGraph H;
	int i,j;
	printf("请以邻接矩阵的方式输入图：\n");
	CreatGraph(&G);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>.");
	printf("请输入要查询的i，j:");
	scanf("%d,%d",&i,&j);
	getchar();
	printf("\n深度优先搜索\n");
	if (IsPath_DFS(&G, i, j))
		printf("存在路径\n");
	else printf("不存在路径\n");
	printf("\n宽度优先搜索\n");
	if (IsPath_BFS(&G, i, j))
		printf("存在路径\n");
	else printf("不存在路径\n");
	
	printf("请以邻接表的方式输入图：\n");
	CreateALGraph(&H);
	printf("请输入要查询的i，j:");
	scanf("%d,%d", &i, &j);
	printf("\n深度优先搜索\n");
	if (IsPath_DFS1(&H, i, j))
		printf("存在路径\n");
	else printf("不存在路径\n");
	printf("\n宽度优先搜索\n");
	if (IsPath_BFS1(&H, i, j))
		printf("存在路径\n");
	else printf("不存在路径\n");
	return 0;
}
