#include "stdafx.h"  
#include<iostream>  
#include<queue>  
#pragma warning(disable:4996)

 

using namespace std;
//
//#define VERTEX_MAX 26   //图的最大顶点数     
//#define MAXVALUE 32767 //最大值(可设为一个最大整数)   
//typedef struct //定义邻接矩阵图结构   
//{
//	char Vertex[VERTEX_MAX]; //保存顶点信息(序号或字母)  
//	int Edges[VERTEX_MAX][VERTEX_MAX]; //保存边的权   
//	int isTrav[VERTEX_MAX]; //遍历标志   
//	int VertexNum; //顶点数量   
//	int EdgeNum;//边数量   
//	int GraphType; //图的类型(0:无向图，1:有向图)      
//}MatrixGraph;
//
//void CreateMatrixGraph(MatrixGraph *G)//创建邻接矩阵图   
//{
//	int i, j, k, weight;
//	char start, end; //边的起始顶点  
//	for (i = 0; i < G->VertexNum; i++)  //清空矩阵  
//	{
//		for (j = 0; j < G->VertexNum; j++)
//			G->Edges[i][j] = MAXVALUE; //设置矩阵中各元素的值为最大值  
//	}
//	cout << "输入各顶点信息\n";
//	for (i = 0; i<G->VertexNum; i++) //输入顶点   
//	{
//		printf("第%d个顶点:", i + 1);
//		cin >> G->Vertex[i]; //保存到各顶点数组元素中  
//	}
//	printf("输入构成各边的两个顶点及权值:\n");
//	for (k = 0; k<G->EdgeNum; k++)  //输入边的信息   
//	{
//		printf("第%d条边：", k + 1);
//		cin >> start >> end >> weight;
//		for (i = 0; start != G->Vertex[i]; i++); //在已有顶点中查找始点   
//		{
//			for (j = 0; end != G->Vertex[j]; j++); //在已有顶点中查找结终点  
//			{
//				G->Edges[i][j] = weight; //对应位置保存权值，表示有一条边  
//				if (G->GraphType == 0)  //若是无向图  
//				{
//					G->Edges[j][i] = weight;//在对角位置保存权值  
//				}
//			}
//		}
//	}
//}
//
//void OutMatrix(MatrixGraph *G)//输出邻接矩阵   
//{
//	int i, j;
//	for (j = 0; j<G->VertexNum; j++)
//		printf("\t%c", G->Vertex[j]);          //在第1行输出顶点信息   
//	printf("\n");
//	for (i = 0; i<G->VertexNum; i++)
//	{
//		printf("%c", G->Vertex[i]);
//		for (j = 0; j<G->VertexNum; j++)
//		{
//			if (G->Edges[i][j] == MAXVALUE) //若权值为最大值   
//				printf("\t∞");          //输出无穷大符号   
//			else
//				printf("\t%d", G->Edges[i][j]); //输出边的权值   
//		}
//		printf("\n");
//	}
//}
//
//void BFSfunction(MatrixGraph *G, int i)//广度优先遍历  
//{
//	int  j;
//	queue<int> Q;
//	G->isTrav[i] = 1;//表示这个顶点已经被遍历过了  
//	cout << "->" << G->Vertex[i];//输出第一个顶点  
//	Q.push(i);  //入队列  
//	while (!Q.empty())
//	{
//		Q.pop();
//		for (j = 0; j < G->VertexNum; j++)
//		{
//			if (G->Edges[i][j] != MAXVALUE && !G->isTrav[j])
//			{
//				cout << "->" << G->Vertex[j];
//				G->isTrav[j] = 1;
//				Q.push(j);
//			}
//		}
//	}
//}
//void BFSTraverse(MatrixGraph *G)//广度优先  
//{
//	int i;
//	for (i = 0; i < G->VertexNum; i++)    //表示其它顶点为被遍历  
//		G->isTrav[i] = 0;
//	for (i = 0; i < G->VertexNum; i++)
//	{
//		if (!G->isTrav[i])   //若未被遍历  
//			BFSfunction(G, i);//遍历一下  
//	}
//}
//void DFSfunction(MatrixGraph *G, int i)//深度遍历函数  
//{
//	int j = 0;
//	G->isTrav[i] = 1;//标记该顶点已经被遍历过  
//	cout << "->" << G->Vertex[i];//输出第一个遍历的顶点信息  
//	for (j = 0; j < G->VertexNum; j++)//循环遍历其它顶点  
//	{
//		if (G->Edges[i][j] != MAXVALUE && !G->isTrav[i])//该结点有相连的其它顶点且未被遍历且  
//		{
//			DFSfunction(G, j);
//		}
//	}
//}
//void DFSTraverse(MatrixGraph *G)//深度优先遍历  
//{
//	int i;
//	for (i = 0; i < G->VertexNum; i++)//表示各顶点还没有被遍历  
//	{
//		G->isTrav[i] = 0;
//	}
//	for (i = 0; i < G->VertexNum; i++)
//	{
//		if (!G->isTrav[i])//若未被遍历  
//			DFSfunction(G, i);//遍历一下  
//	}
//	cout << '\n';
//}
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	MatrixGraph G; //定义保存邻接矩阵结构的图   
//	int i, j;
//	cout << "输入生成图的类型(0:无向图,1:有向图):\n";
//	cin >> G.GraphType;//图的种类  
//	cout << "输入图的顶点数量和边数量:\n";
//	cin >> G.VertexNum >> G.EdgeNum;//输入图顶点数和边数   
//
//	CreateMatrixGraph(&G); //创建用邻接表保存的图   
//	printf("邻接矩阵数据如下:\n");
//	OutMatrix(&G);
//	cout << "深度优先遍历结点：";
//	DFSTraverse(&G);
//	cout << "广度优先遍历结点：";
//	BFSTraverse(&G);
//	cout << endl;
//	system("pause");
//	return 0;
//}

#define MaxVertexNum  10
#define MAXCOST  1000
typedef  char  VertexType;
typedef  struct
{
	VertexType vexs[MaxVertexNum];                  //顶点信息
	int  edges[MaxVertexNum][MaxVertexNum];    //邻接矩阵
	int n, e;                                                          //顶点和边数
}MGraph;

void CreateMGraph(MGraph  &G);           //创建邻接矩阵存储图
void Prim(MGraph *G, int closevex[]);      //Prim计算最小生成树

void main()
{
	MGraph G;
	int closevex[MaxVertexNum];

	CreateMGraph(G);
	Prim(&G, closevex);
	system("pause");

}
void CreateMGraph(MGraph  &G)
{
	int  i, j, k;
	cout<<"请输入顶点数和边数"<<endl;
	cin>>G.n>>G.e;
	cout<<"请输入顶点信息"<<endl;
	for (i=0;i<G.n;i++)           cin>>G.vexs[i];
	for (i=0;i<G.n;i++)
	for (j=0;j<G.n;j++)     G.edges[i][j]=0;
	cout<<"请输入每条边(对应的顶点序号)"<<endl;
	for (k=0;k<G.e;k++)
	{     cin>>i>>j;
	G.edges[i][j]=1; G.edges[j][i]=1;}
	//int i, j;
	//G.n = 7;          G.e = 10;
	//for (i = 0; i<G.n; i++)
	//	G.vexs[i] = 'A' + i;
	//for (i = 0; i<G.n; i++)
	//{
	//	for (j = 0; j<G.n; j++)
	//		G.edges[i][j] = 0;
	//}
	////0   1  2  3   4   5   6   7
	////A  B C  D  E   F  G  H
	//G.edges[0][1] = 50; G.edges[1][0] = 50;    //(A,B)50
	//G.edges[0][2] = 60; G.edges[2][0] = 60;    //(A,C)60
	//G.edges[1][3] = 65; G.edges[3][1] = 65;    //(B,D)65
	//G.edges[1][4] = 40; G.edges[4][1] = 40;    //(B,E)40
	//G.edges[2][3] = 52; G.edges[3][2] = 52;    //(C,D)52
	//G.edges[2][6] = 45; G.edges[6][2] = 45;    //(C,G)45
	//G.edges[3][5] = 30; G.edges[5][3] = 30;    //(D,F)30
	//G.edges[4][5] = 70; G.edges[5][4] = 70;    //(E,F)70
	//G.edges[3][6] = 42; G.edges[6][3] = 42;    //(D,G)42
	G.edges[3][4] = 50; G.edges[4][3] = 50;    //(D,E)50
}
void Prim(MGraph *G, int closevex[])
{
	int  lowcost[MaxVertexNum], mincost;
	int i, j, k;

	for (i = 1; i<G->n; i++)
	{
		lowcost[i] = G->edges[0][i];
		closevex[i] = 0;
	}
	lowcost[0] = 0;
	closevex[0] = 0;
	for (i = 1; i<G->n; i++)
	{
		mincost = MAXCOST;
		j = 1; k = 1;
		while (j<G->n)
		{
			if (lowcost[j]<mincost && lowcost[j]>0)
			{
				mincost = lowcost[j];
				k = j;
			}
			j++;
		}
		//cout<<"顶点的序号:"<<k+1<<"权值:"<<mincost<<endl;
		cout << "(" << G->vexs[closevex[k]] << "," << G->vexs[k] << "):" << mincost << endl;
		lowcost[k] = -lowcost[k];

		for (j = 1; j<G->n; j++)
		{
			if (G->edges[k][j]>0)
			{
				if (lowcost[j]>0 && G->edges[k][j]<lowcost[j] || lowcost[j] == 0)
				{
					lowcost[j] = G->edges[k][j];
					closevex[j] = k;
				}
			}
		}
	}
}