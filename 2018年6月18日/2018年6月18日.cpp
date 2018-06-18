// 2018年6月18日.cpp: 定义控制台应用程序的入口点。
//邻接矩阵

#include "stdafx.h"
#include "stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
using namespace std;


#define MaxVex 100
typedef  int  VertexType;
typedef  int  EdgeType;
typedef  struct  graph
{
	VertexType vexs[MaxVex];
	EdgeType edges[MaxVex][MaxVex];
} Mgraph;
void creatMgraph(Mgraph *ga)
{
	int i, j, k, vertex;
	printf("请输入图的所有顶点:\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &vertex);
		ga->vexs[i] = vertex;
	}
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			ga->edges[i][j] = 0;
	for (k = 1; k < 13; k++)
	{
		printf("输入图中的边(起点 终点):");
		scanf("%d%d", &i, &j);
		ga->edges[i][j] = 1;
		ga->edges[j][i] = 1;
	}
}
void displayGraph(Mgraph *mG)
{
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
		{
			printf("%d ", mG->edges[i][j]);
			if (j == 9)
				printf("\n");
		}
}
//void main()
//{
//	Mgraph *M;
//	M = (Mgraph *)malloc(sizeof(Mgraph));
//	creatMgraph(M);
//
//	displayGraph(M);
//	printf("\n邻接矩阵生成成功\n");
//	system("pause");
//}


