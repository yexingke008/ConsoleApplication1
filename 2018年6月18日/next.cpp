#include<stdio.h>
#include<stdafx.h>
#include<stdlib.h>
#pragma warning(disable:4996)
using namespace std;


#define MaxVex 100
typedef struct anode
{
	int adjvex;
	struct anode *next;
}Anode;
typedef struct vnode
{
	int vertex;
	Anode *first;
}Vnode;
typedef struct
{
	Vnode vex[MaxVex];
}Lgraph;
void createGraph(Vnode g[])
{
	Anode *s;
	int i, j, k, vertex;
	printf("������ͼ�����ж���:\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &vertex);
		g[i].vertex = vertex;
		g[i].first = NULL;
	}
	for (k = 1; k < 13; k++)
	{
		printf("����ͼ�еı�(��� �յ�):");
		scanf("%d%d", &i, &j);
		s = (Anode *)malloc(sizeof(Anode));
		s->adjvex = j;
		s->next = g[i].first;
		g[i].first = s;
		s = (Anode *)malloc(sizeof(Anode));
		s->adjvex = i;
		s->next = g[j].first;
		g[j].first = s;
	}
}
void dispaly(Lgraph *l)
{
	Anode *anode;
	int i;
	anode = (Anode *)malloc(sizeof(Anode));
	printf("�ڽӱ����:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d", l->vex[i].vertex);
		anode = l->vex[i].first;
		while (anode != NULL)
		{
			printf("%3d", anode->adjvex);
			anode = anode->next;
		}
		printf("\n");
	}
}
//void main()
//{
//	Lgraph *G;
//	G = (Lgraph *)malloc(sizeof(Lgraph));
//	createGraph(G->vex);
//	dispaly(G);
//	printf("�ڽӱ����ɽ���\n");
//	system("pause");
//}
