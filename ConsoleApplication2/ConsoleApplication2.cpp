// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;


// β�巨����������(��ͷ�ڵ�)
NODE *createEnd(int arr[], int len)
{
	NODE *head = (NODE *)malloc(sizeof(NODE)); // ����ͷ�ڵ�
	head->next = NULL;
	NODE *end = head;  // βָ���ʼ��

	for (int i = 0; i < len; i++) {

		NODE *p = (NODE *)malloc(sizeof(NODE)); // Ϊÿ������Ԫ�ؽ���һ���ڵ�
		p->data = arr[i];
		end->next = p;  // ���ڵ�p���뵽�ն˽ڵ�֮��
		end = p;
	}

	end->next = NULL;  // ����������ϣ����ն˽ڵ��ָ�����ÿ�

	return head;
}


// ɾ���������е�i���ڵ�
NODE *del(NODE *head, int i)
{
	NODE *p = head;

	int j = 1;
	while (p->next && j < i) {
		p = p->next;
		++j;
	}

	if (p->next == NULL || j > i) { // ����ѭ����������pΪ�գ���iΪ0����ʱ����˵��λ�ò�����
		printf("Position Error\n");
		return 0;
	}


	NODE *temp = p->next;
	p->next = temp->next;

	//free(p);

	return head;
}
// ע: (1)�赥����ĳ���Ϊn��������ɾ����i���ڵ�ʱ�����뱣֤ 1<= i <= n�����򲻺Ϸ���
//     (2)�� i=n+1 ʱ����Ȼ��ɾ���ڵ㲻���ڣ�����ǰ���ڵ�ȴ���ڣ������ն˽ڵ㣻���ԣ���ɾ�ڵ��ֱ��ǰ��*p���ڣ�������ζ�ű�ɾ�ڵ��һ�����ڣ�����*p����(��p != NULL)��*p�����ն˽ڵ�(��p->next != NULL)ͬʱ���� j <= iʱ������ȷ����ɾ�ڵ���ڡ���ʱ���㷨��ʱ�临�Ӷ���O(n)��


// �������ӡ
void print(NODE *head)
{
	if (head == NULL) return;

	NODE *p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

}

NODE *dlbcz(NODE *h, int x)   //���ݲ��ң�xΪҪ���ҵ�Ԫ��
{

	NODE *p;
	p = h;
	while (p != NULL && p->data != x)
		p = p->next;
	return (p);
}

int getNum(NODE *h, int x)   //���ݲ��ң�xΪҪ���ҵ�Ԫ��
{

	NODE *p;
	p = h;
	int i=0;
	while (p != NULL && p->data != x) {
		i++;
		p = p->next;
	}
	return i;
}


void dlbsc(NODE *p)  //ɾ��p����Ľ��
{
	NODE *q;
	if (p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}
}
int main(void)
{
	int arr[] = { 1,2,3,4,5,6,9,7 };
	int len = sizeof(arr) / sizeof(int);
	int num = 0;
	NODE *head = createEnd(arr, len);



	// ɾ��ǰ
	print(head);
	printf("========ɾ��ǰ\n\n");

	//delete(head, 5);
	printf("������ɾ��Ԫ��:\n");
	scanf("%d", &num);
	printf("Ԫ��%dλ�ã�%d \n", num, getNum(head, num));


	//dlbsc(head);
	*del(head, getNum(head, num));

	// ɾ����
	print(head);
	printf("========ɾ����\n\n");

	free(head);
	system("pause");

	return 0;
}
