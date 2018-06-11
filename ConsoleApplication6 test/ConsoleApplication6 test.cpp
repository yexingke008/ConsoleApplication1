// ConsoleApplication6 test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#pragma warning(disable:4996)

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}JD;
void CreateBiTree(JD *&l)	//����  
{
	char ch;
	cin >> ch;
	if (ch == '#') l = NULL;
	else
	{
		l = (JD *)malloc(sizeof(JD));
		l->data = ch;
		CreateBiTree(l->lchild);
		CreateBiTree(l->rchild);
	}
}
void InOrderTraverse2(JD *&l)	//�������  
{
	if (l)  
	{
		InOrderTraverse2(l->lchild);
		cout << l->data;
		InOrderTraverse2(l->rchild);
	}
}
int main()
{
	JD *l;
	printf("�밴���������������Ԫ�أ�\n");
	CreateBiTree(l);
	printf("���������������ö�������Ԫ��Ϊ��\n");
	InOrderTraverse2(l); 
	printf("\n");
	system("pause");
	return 0;
}

	
