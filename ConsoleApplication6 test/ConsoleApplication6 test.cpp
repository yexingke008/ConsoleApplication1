#include "stdafx.h"  
#include<iostream>  
#include<queue>  
#pragma warning(disable:4996)

 

using namespace std;
//
//#define VERTEX_MAX 26   //ͼ����󶥵���     
//#define MAXVALUE 32767 //���ֵ(����Ϊһ���������)   
//typedef struct //�����ڽӾ���ͼ�ṹ   
//{
//	char Vertex[VERTEX_MAX]; //���涥����Ϣ(��Ż���ĸ)  
//	int Edges[VERTEX_MAX][VERTEX_MAX]; //����ߵ�Ȩ   
//	int isTrav[VERTEX_MAX]; //������־   
//	int VertexNum; //��������   
//	int EdgeNum;//������   
//	int GraphType; //ͼ������(0:����ͼ��1:����ͼ)      
//}MatrixGraph;
//
//void CreateMatrixGraph(MatrixGraph *G)//�����ڽӾ���ͼ   
//{
//	int i, j, k, weight;
//	char start, end; //�ߵ���ʼ����  
//	for (i = 0; i < G->VertexNum; i++)  //��վ���  
//	{
//		for (j = 0; j < G->VertexNum; j++)
//			G->Edges[i][j] = MAXVALUE; //���þ����и�Ԫ�ص�ֵΪ���ֵ  
//	}
//	cout << "�����������Ϣ\n";
//	for (i = 0; i<G->VertexNum; i++) //���붥��   
//	{
//		printf("��%d������:", i + 1);
//		cin >> G->Vertex[i]; //���浽����������Ԫ����  
//	}
//	printf("���빹�ɸ��ߵ��������㼰Ȩֵ:\n");
//	for (k = 0; k<G->EdgeNum; k++)  //����ߵ���Ϣ   
//	{
//		printf("��%d���ߣ�", k + 1);
//		cin >> start >> end >> weight;
//		for (i = 0; start != G->Vertex[i]; i++); //�����ж����в���ʼ��   
//		{
//			for (j = 0; end != G->Vertex[j]; j++); //�����ж����в��ҽ��յ�  
//			{
//				G->Edges[i][j] = weight; //��Ӧλ�ñ���Ȩֵ����ʾ��һ����  
//				if (G->GraphType == 0)  //��������ͼ  
//				{
//					G->Edges[j][i] = weight;//�ڶԽ�λ�ñ���Ȩֵ  
//				}
//			}
//		}
//	}
//}
//
//void OutMatrix(MatrixGraph *G)//����ڽӾ���   
//{
//	int i, j;
//	for (j = 0; j<G->VertexNum; j++)
//		printf("\t%c", G->Vertex[j]);          //�ڵ�1�����������Ϣ   
//	printf("\n");
//	for (i = 0; i<G->VertexNum; i++)
//	{
//		printf("%c", G->Vertex[i]);
//		for (j = 0; j<G->VertexNum; j++)
//		{
//			if (G->Edges[i][j] == MAXVALUE) //��ȨֵΪ���ֵ   
//				printf("\t��");          //�����������   
//			else
//				printf("\t%d", G->Edges[i][j]); //����ߵ�Ȩֵ   
//		}
//		printf("\n");
//	}
//}
//
//void BFSfunction(MatrixGraph *G, int i)//������ȱ���  
//{
//	int  j;
//	queue<int> Q;
//	G->isTrav[i] = 1;//��ʾ��������Ѿ�����������  
//	cout << "->" << G->Vertex[i];//�����һ������  
//	Q.push(i);  //�����  
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
//void BFSTraverse(MatrixGraph *G)//�������  
//{
//	int i;
//	for (i = 0; i < G->VertexNum; i++)    //��ʾ��������Ϊ������  
//		G->isTrav[i] = 0;
//	for (i = 0; i < G->VertexNum; i++)
//	{
//		if (!G->isTrav[i])   //��δ������  
//			BFSfunction(G, i);//����һ��  
//	}
//}
//void DFSfunction(MatrixGraph *G, int i)//��ȱ�������  
//{
//	int j = 0;
//	G->isTrav[i] = 1;//��Ǹö����Ѿ���������  
//	cout << "->" << G->Vertex[i];//�����һ�������Ķ�����Ϣ  
//	for (j = 0; j < G->VertexNum; j++)//ѭ��������������  
//	{
//		if (G->Edges[i][j] != MAXVALUE && !G->isTrav[i])//�ý��������������������δ��������  
//		{
//			DFSfunction(G, j);
//		}
//	}
//}
//void DFSTraverse(MatrixGraph *G)//������ȱ���  
//{
//	int i;
//	for (i = 0; i < G->VertexNum; i++)//��ʾ�����㻹û�б�����  
//	{
//		G->isTrav[i] = 0;
//	}
//	for (i = 0; i < G->VertexNum; i++)
//	{
//		if (!G->isTrav[i])//��δ������  
//			DFSfunction(G, i);//����һ��  
//	}
//	cout << '\n';
//}
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	MatrixGraph G; //���屣���ڽӾ���ṹ��ͼ   
//	int i, j;
//	cout << "��������ͼ������(0:����ͼ,1:����ͼ):\n";
//	cin >> G.GraphType;//ͼ������  
//	cout << "����ͼ�Ķ��������ͱ�����:\n";
//	cin >> G.VertexNum >> G.EdgeNum;//����ͼ�������ͱ���   
//
//	CreateMatrixGraph(&G); //�������ڽӱ����ͼ   
//	printf("�ڽӾ�����������:\n");
//	OutMatrix(&G);
//	cout << "������ȱ�����㣺";
//	DFSTraverse(&G);
//	cout << "������ȱ�����㣺";
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
	VertexType vexs[MaxVertexNum];                  //������Ϣ
	int  edges[MaxVertexNum][MaxVertexNum];    //�ڽӾ���
	int n, e;                                                          //����ͱ���
}MGraph;

void CreateMGraph(MGraph  &G);           //�����ڽӾ���洢ͼ
void Prim(MGraph *G, int closevex[]);      //Prim������С������

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
	cout<<"�����붥�����ͱ���"<<endl;
	cin>>G.n>>G.e;
	cout<<"�����붥����Ϣ"<<endl;
	for (i=0;i<G.n;i++)           cin>>G.vexs[i];
	for (i=0;i<G.n;i++)
	for (j=0;j<G.n;j++)     G.edges[i][j]=0;
	cout<<"������ÿ����(��Ӧ�Ķ������)"<<endl;
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
		//cout<<"��������:"<<k+1<<"Ȩֵ:"<<mincost<<endl;
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