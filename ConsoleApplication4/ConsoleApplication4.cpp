// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable:4996)
using namespace std;


typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node *next;
}Lnode; //节点类型

typedef struct Qu
{
	Lnode *front;
	Lnode *rear;
} Queue;//队列类型
		//主文件

void  Initiate_queue(Queue *queue)//初始化队列`，队列有头结点。返回队列的指针。
{
	Lnode *q;
	int i = 0;
	q = (Lnode *)malloc(sizeof(Lnode));
	q->data = i;
	q->next = NULL;
	queue->front = q;
	queue->rear = q;
	//return queue;
}

int Queue_empty(Queue *queue)//判断队列是否为空，为空返回1，否则返回0
{
	Lnode *de_node;
	de_node = (Lnode *)malloc(sizeof(Lnode));
	//if (queue->front = queue->rear)
	if (de_node->data == 0)
		return 1;
	else
		return 0;
}

void En_queue(Queue *queue, int node)//入队
{
	Lnode *q;
	q = (Lnode *)malloc(sizeof(Lnode));
	q->data = node;
	q->next = NULL;
	queue->rear->next = q;
	queue->rear = q;
	q->next = NULL;
	return;

}

DataType De_queue(Queue *queue)//出队一个节点，返回其值
{
	Lnode *de_node;
	int seq;
	de_node = (Lnode *)malloc(sizeof(Lnode));
	if (Queue_empty(queue) == 1)//判断队列是否为空
	{
		printf("The queue is empty! Cannot dequeue");
		return -1;
	}
	else//出队一个元素
	{
		de_node = queue->front->next;
		queue->front->next = de_node->next;
		if (de_node->next = NULL)
		{
			queue->rear = queue->front;
		}
		seq = de_node->data;
		free(de_node);
		return seq;
	}
}

void displayQueue(Queue *queue)//显示从队头到队尾的元素
{
	Lnode *m;
	m = (Lnode *)malloc(sizeof(Lnode));
	m = queue->front->next;
	while (m) {

		printf(" data=%d\n", m->data);
		m = m->next;


	}
	printf("显示结束\n");
	return;
}


void main()//主函数
{
	Queue *Q;
	int i, m;
	Q = (Queue *)malloc(sizeof(Queue));
	Initiate_queue(Q);
	printf("Please input 5 elements\n");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &m);//让输入的元素成为队列
		En_queue(Q, m);
	}
	De_queue(Q);//出队一个元素
	printf("显示队列：\n");
	displayQueue(Q);//显示队列元素

	system("pause");
	return;
}


