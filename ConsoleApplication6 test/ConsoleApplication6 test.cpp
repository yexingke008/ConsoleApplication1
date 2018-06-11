// ConsoleApplication6 test.cpp : 定义控制台应用程序的入口点。
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
void CreateBiTree(JD *&l)	//先序  
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
void InOrderTraverse2(JD *&l)	//中序遍历  
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
	printf("请按先序输入二叉树的元素！\n");
	CreateBiTree(l);
	printf("按中序遍历法输出该二叉树的元素为：\n");
	InOrderTraverse2(l); 
	printf("\n");
	system("pause");
	return 0;
}

	
