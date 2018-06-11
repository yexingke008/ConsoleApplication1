// ConsoleApplication4.cpp : �������̨Ӧ�ó������ڵ㡣
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
}Lnode; //�ڵ�����

typedef struct Qu
{
	Lnode *front;
	Lnode *rear;
} Queue;//��������
		//���ļ�

void  Initiate_queue(Queue *queue)//��ʼ������`��������ͷ��㡣���ض��е�ָ�롣
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

int Queue_empty(Queue *queue)//�ж϶����Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
{
	Lnode *de_node;
	de_node = (Lnode *)malloc(sizeof(Lnode));
	//if (queue->front = queue->rear)
	if (de_node->data == 0)
		return 1;
	else
		return 0;
}

void En_queue(Queue *queue, int node)//���
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

DataType De_queue(Queue *queue)//����һ���ڵ㣬������ֵ
{
	Lnode *de_node;
	int seq;
	de_node = (Lnode *)malloc(sizeof(Lnode));
	if (Queue_empty(queue) == 1)//�ж϶����Ƿ�Ϊ��
	{
		printf("The queue is empty! Cannot dequeue");
		return -1;
	}
	else//����һ��Ԫ��
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

void displayQueue(Queue *queue)//��ʾ�Ӷ�ͷ����β��Ԫ��
{
	Lnode *m;
	m = (Lnode *)malloc(sizeof(Lnode));
	m = queue->front->next;
	while (m) {

		printf(" data=%d\n", m->data);
		m = m->next;


	}
	printf("��ʾ����\n");
	return;
}


void main()//������
{
	Queue *Q;
	int i, m;
	Q = (Queue *)malloc(sizeof(Queue));
	Initiate_queue(Q);
	printf("Please input 5 elements\n");
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &m);//�������Ԫ�س�Ϊ����
		En_queue(Q, m);
	}
	De_queue(Q);//����һ��Ԫ��
	printf("��ʾ���У�\n");
	displayQueue(Q);//��ʾ����Ԫ��

	system("pause");
	return;
}


