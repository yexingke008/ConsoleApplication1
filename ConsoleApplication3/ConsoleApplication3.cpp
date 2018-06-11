/*实验2
3. 试写出两个一元多项式相加的算法。
用链表来存储一元多项式，并且要在程序中验证其功能实现。
此题的源程序保存为2_e1.cpp
*/
#include "stdafx.h"
#include<iostream>  
using namespace std;

typedef struct node
{
	int coef;    //系数  
	int exp;   //指数  
	struct node * next;
}JD;

//=====(老师讲的方法)
void  add_poly(JD *pa, JD *pb)
{
	JD *p, *q, *u, *pre;
	int x;
	p = pa->next;
	q = pb->next;
	pre = pa;
	while ((p != NULL) && (q != NULL))
	{
		if (p->exp < q->exp)
		{
			pre = p;  p = p->next;
		}
		else if (p->exp == q->exp)
		{
			x = p->coef + q->coef;
			if (x != 0)
			{
				p->coef = x;
				pre = p;
			}
			else
			{
				pre->next = p->next;
				//free(p);
			}
			p = pre->next;
			u = q;
			q = q->next;
			//free(u);
		}
		else
		{
			u = q->next; q->next = p; pre->next = q;
			pre = q;  q = u;
		}
	}
	if (q != NULL) pre->next = q;
	//free(pb);
}

JD* Creat()
{//尾插法建表，有头结点  
	JD* head;
	JD* s, *p;
	int c, e;
	head = new JD;      //生成头结点  
	head->next = NULL;
	cout << "请分别输入新的一项的系数、指数(以输入000作为结束):" << endl;
	cin >> c >> e;
	while (c != 000 && e != 000) //输入并检测结束  
	{
		s = new JD;         //生成新结点  
		s->coef = c;           //装入数据  
		s->exp = e;
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;  //插到最后一个结点后  
		s->next = NULL;
		cout << "请分别输入新的一项的系数、指数(以输入000作为结束):" << endl;
		cin >> c >> e;
	}
	return  head;
}

void Display(JD * head)
{
	if (head == NULL)
	{
		cout << "多项式不存在！" << endl;
		return;
	}
	JD* p;
	p = head->next;
	while (p != NULL)
	{
		if (p->coef > 0)
			cout << p->coef << "x^" << p->exp;
		else
			cout << "(" << p->coef << ")" << "x^" << p->exp;
		if (p->next != NULL)
			cout << "+";
		p = p->next;
	}
	cout << endl << endl;

}

JD* Add(JD * A, JD * B)
{
	JD * C = new JD;
	C->next = NULL;
	JD * p1 = A->next;
	JD * p2 = B->next;
	JD * p3;
	JD * rearC = C;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->exp < p2->exp)
		{
			p3 = new JD;
			p3->coef = p1->coef;
			p3->exp = p1->exp;
			p3->next = NULL;
			rearC->next = p3;
			rearC = p3;
			p1 = p1->next;
		}
		else if (p1->exp > p2->exp)
		{
			p3 = new JD;
			p3->coef = p2->coef;
			p3->exp = p2->exp;
			p3->next = NULL;
			rearC->next = p3;
			rearC = p3;
			p2 = p2->next;
		}
		else //p1->exp == p2->exp  
		{
			if ((p1->coef + p2->coef) != 0)
			{
				p3 = new JD;
				p3->coef = p1->coef + p2->coef;
				p3->exp = p1->exp;
				p3->next = NULL;
				rearC->next = p3;
				rearC = p3;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if (p1 == NULL)
	{
		while (p2 != NULL)
		{
			p3 = new JD;
			p3->coef = p2->coef;
			p3->exp = p2->exp;
			p3->next = NULL;
			rearC->next = p3;
			rearC = p3;
			p2 = p2->next;
		}
	}
	else //p2==NULL  
	{
		while (p1 != NULL)
		{
			p3 = new JD;
			p3->coef = p1->coef;
			p3->exp = p1->exp;
			p3->next = NULL;
			rearC->next = p3;
			rearC = p3;
			p1 = p1->next;
		}
	}
	return C;
}

int main()
{
	cout << "多项式A：" << endl;
	JD * PL1;
	PL1 = Creat();
	cout << "多项式A=";
	Display(PL1);

	cout << "多项式B：" << endl;
	JD * PL2;
	PL2 = Creat();
	cout << "多项式A=";
	Display(PL2);

	cout << "多项式A+B=";
	JD * PL3;
	PL3 = Add(PL1, PL2);
	Display(PL3);

	cout << "====(老师讲的方法)多项式A+B=";
	add_poly(PL1, PL2);
	Display(PL1);

	free(PL1);
	free(PL2);

	system("pause");
	return 0;
}