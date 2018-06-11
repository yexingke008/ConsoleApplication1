// ConsoleApplication5.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include<iostream>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable:4996)
using namespace std;
#define MAXSIZE 100  
typedef char TElemType;

typedef struct node {
	char data;
	struct node *lchild, *rchild;
}JD;





void CreateBiTree(JD *bt)		//先序  
{
	char ch;
	/*printf("ch=");
	scanf("%c", &ch);
	getchar();*/
	cin >> ch;
	if (ch == '#')  bt = NULL;
	else
	{
		bt = (JD *)malloc(sizeof(JD));
		bt->data = ch;
		bt->lchild = CreateBiTree(bt->lchild);
		bt->rchild = CreateBiTree(bt->rchild);
	}
}

void InOrderTraverse2(JD *bt) {			//中序遍历  
	if (bt) {
		InOrderTraverse2(bt->lchild);
		printf("%s\n", bt->data);
		InOrderTraverse2(bt->rchild);
	}
}





int main()
{
	JD *a;
	a = (JD *)malloc(sizeof(JD));
	//int height,num;  
	printf("请输入二叉树的元素！\n");
	CreateBiTree(a);
	printf("按中序遍历法输出该二叉树的元素为：\n");
	InOrderTraverse2(a);
	/*	height=Depth(a);
	num=NodeCount(a);
	cout<<"\n该二叉树高度为：";
	cout<<height<<endl;
	cout<<"该二叉树结点数为：";
	cout<<num;  */

	system("pause");
	return 0;
}


