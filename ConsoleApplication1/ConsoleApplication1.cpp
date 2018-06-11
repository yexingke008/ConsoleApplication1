// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "malloc.h"
#include "stdlib.h"
#include "stdafx.h"
#include <iostream>


using namespace std;
class LinkNodeOfInt {
public:
	int data;
	LinkNodeOfInt *link;
	LinkNodeOfInt(const int &a, LinkNodeOfInt *ptr)
	{
		data = a;
		link = ptr;
	}
	LinkNodeOfInt()
	{


	}
};
class ListOfint {
public:
	LinkNodeOfInt *head;
	LinkNodeOfInt *tail;
	ListOfint()
	{
		head = new LinkNodeOfInt(0, NULL);
		tail = head;




	}
	ListOfint(const ListOfint &list)
	{
		head = new LinkNodeOfInt(0, NULL);
		LinkNodeOfInt *cur = head->link;
		LinkNodeOfInt *othercur = list.head->link;
		int i = 0;
		while (othercur != NULL)
		{
			LinkNodeOfInt *s = new LinkNodeOfInt(othercur->data, NULL);
			if (i == 0)
			{
				head->link = s;
				cur = head->link;
			}
			else
			{
				cur->link = s;
				cur = cur->link;
				i++;
			}
			othercur = othercur->link;


		}
	}
	void insertTotail(int value)
	{
		LinkNodeOfInt *p = tail;
		p->link = new LinkNodeOfInt(value, NULL);
		tail = p->link;
	}
	void inserttoHead(int value)
	{
		LinkNodeOfInt *p = head->link;
		LinkNodeOfInt *s = new LinkNodeOfInt(value, p);
		head->link = s;
	}


	void prt_list()
	{
		LinkNodeOfInt *p = head->link;
		while (p)
		{
			cout << p->data << endl;
			p = p->link;
		}
	}
	void merge_List(LinkNodeOfInt *pb)
	{
		LinkNodeOfInt *pa = head->link;
		LinkNodeOfInt *pc = head;
		while (pa&&pb)
		{
			if (pa->data <= pb->data)
			{
				pc->link = pa;
				pc = pa;
				pa = pa->link;
			}
			else
			{
				pc->link = pb;
				pc = pb;
				pb = pb->link;
			}


		}
		pc->link = pa ? pa : pb;


	}


};


int main()
{
	ListOfint a;
	a.insertTotail(1);
	a.insertTotail(2);
	a.insertTotail(3);
	printf("========链表a========\n");
	a.prt_list();

	ListOfint b;
	b.insertTotail(4);
	b.insertTotail(5);
	printf("========链表b========\n");
	b.prt_list();

	a.merge_List(b.head->link);
	printf("========链表b加入a后========\n");
	a.prt_list();

	system("pause");
	return 0;
}