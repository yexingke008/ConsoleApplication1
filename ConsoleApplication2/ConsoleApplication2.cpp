// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;


// 尾插法创建单链表(带头节点)
NODE *createEnd(int arr[], int len)
{
	NODE *head = (NODE *)malloc(sizeof(NODE)); // 生成头节点
	head->next = NULL;
	NODE *end = head;  // 尾指针初始化

	for (int i = 0; i < len; i++) {

		NODE *p = (NODE *)malloc(sizeof(NODE)); // 为每个数组元素建立一个节点
		p->data = arr[i];
		end->next = p;  // 将节点p插入到终端节点之后
		end = p;
	}

	end->next = NULL;  // 单链表建立完毕，将终端节点的指针域置空

	return head;
}


// 删除单链表中第i个节点
NODE *del(NODE *head, int i)
{
	NODE *p = head;

	int j = 1;
	while (p->next && j < i) {
		p = p->next;
		++j;
	}

	if (p->next == NULL || j > i) { // 经过循环，若最终p为空，或i为0或负数时，都说明位置不合理；
		printf("Position Error\n");
		return 0;
	}


	NODE *temp = p->next;
	p->next = temp->next;

	//free(p);

	return head;
}
// 注: (1)设单链表的长度为n，则单链表删除第i个节点时，必须保证 1<= i <= n，否则不合法；
//     (2)当 i=n+1 时，虽然被删除节点不存在，但其前趋节点却存在，它是终端节点；所以，被删节点的直接前趋*p存在，并不意味着被删节点就一定存在，仅当*p存在(即p != NULL)且*p不是终端节点(即p->next != NULL)同时满足 j <= i时，才能确定被删节点存在。此时，算法的时间复杂度是O(n)。


// 单链表打印
void print(NODE *head)
{
	if (head == NULL) return;

	NODE *p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

}

NODE *dlbcz(NODE *h, int x)   //数据查找，x为要查找的元素
{

	NODE *p;
	p = h;
	while (p != NULL && p->data != x)
		p = p->next;
	return (p);
}

int getNum(NODE *h, int x)   //数据查找，x为要查找的元素
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


void dlbsc(NODE *p)  //删除p后面的结点
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



	// 删除前
	print(head);
	printf("========删除前\n\n");

	//delete(head, 5);
	printf("请输入删除元素:\n");
	scanf("%d", &num);
	printf("元素%d位置：%d \n", num, getNum(head, num));


	//dlbsc(head);
	*del(head, getNum(head, num));

	// 删除后
	print(head);
	printf("========删除后\n\n");

	free(head);
	system("pause");

	return 0;
}
