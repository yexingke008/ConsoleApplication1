/*ʵ��2
3. ��д������һԪ����ʽ��ӵ��㷨��
���������洢һԪ����ʽ������Ҫ�ڳ�������֤�书��ʵ�֡�
�����Դ���򱣴�Ϊ2_e1.cpp
*/
#include "stdafx.h"
#include<iostream>  
using namespace std;

typedef struct node
{
	int coef;    //ϵ��  
	int exp;   //ָ��  
	struct node * next;
}JD;

//=====(��ʦ���ķ���)
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
{//β�巨������ͷ���  
	JD* head;
	JD* s, *p;
	int c, e;
	head = new JD;      //����ͷ���  
	head->next = NULL;
	cout << "��ֱ������µ�һ���ϵ����ָ��(������000��Ϊ����):" << endl;
	cin >> c >> e;
	while (c != 000 && e != 000) //���벢������  
	{
		s = new JD;         //�����½��  
		s->coef = c;           //װ������  
		s->exp = e;
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;  //�嵽���һ������  
		s->next = NULL;
		cout << "��ֱ������µ�һ���ϵ����ָ��(������000��Ϊ����):" << endl;
		cin >> c >> e;
	}
	return  head;
}

void Display(JD * head)
{
	if (head == NULL)
	{
		cout << "����ʽ�����ڣ�" << endl;
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
	cout << "����ʽA��" << endl;
	JD * PL1;
	PL1 = Creat();
	cout << "����ʽA=";
	Display(PL1);

	cout << "����ʽB��" << endl;
	JD * PL2;
	PL2 = Creat();
	cout << "����ʽA=";
	Display(PL2);

	cout << "����ʽA+B=";
	JD * PL3;
	PL3 = Add(PL1, PL2);
	Display(PL3);

	cout << "====(��ʦ���ķ���)����ʽA+B=";
	add_poly(PL1, PL2);
	Display(PL1);

	free(PL1);
	free(PL2);

	system("pause");
	return 0;
}