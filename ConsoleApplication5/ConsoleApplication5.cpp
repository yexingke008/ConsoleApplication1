// ConsoleApplication5.cpp : �������̨Ӧ�ó������ڵ㡣
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





void CreateBiTree(JD *bt)		//����  
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

void InOrderTraverse2(JD *bt) {			//�������  
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
	printf("�������������Ԫ�أ�\n");
	CreateBiTree(a);
	printf("���������������ö�������Ԫ��Ϊ��\n");
	InOrderTraverse2(a);
	/*	height=Depth(a);
	num=NodeCount(a);
	cout<<"\n�ö������߶�Ϊ��";
	cout<<height<<endl;
	cout<<"�ö����������Ϊ��";
	cout<<num;  */

	system("pause");
	return 0;
}


