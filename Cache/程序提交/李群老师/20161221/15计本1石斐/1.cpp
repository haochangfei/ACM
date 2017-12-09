/*题目描述：合并两个非降序单链表。如单链表表1->2->3和单链表2->3->5合并为1->2->3->5。
单链表结点定义如下：
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。*/


#include <stdio.h>
#include<stdlib.h>

#define N 20

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;



LinkedList CreateList()
{
    LinkedList L=(LinkedList)malloc(sizeof(ListNode));
	L->next=NULL;
	return L;
}

LinkedList InsertList(LinkedList L,int b)
{
    LinkedList p = (LinkedList)malloc(sizeof(ListNode));
	p=L->next;
	p->data=b;
	p=p->next;
	return L;
}

void PrintList(LinkedList L)
{
    LinkedList p = L->next;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}


void MergeList(LinkedList L,LinkedList T,LinkedList S)
{
	LinkedList pl,pt,ps;
	pl=L->next;
	pt=T->next;
    S=(LinkedList)malloc(sizeof(ListNode));
	S=ps=L;
	while(pl&&pt)
	{
		printf("h\n");
		if(pl->data<=pt->data)
		{
			ps->next=pl;
			ps=pl;
			pl=pl->next;
		}
		else
		{
			ps->next=pt;
			ps=pt;
			pt=pt->next;
		}
	}
	ps->next=pl ? pl : pt;
	free(T);
}

int main()
{
	LinkedList L;
	LinkedList T;
	LinkedList S;
    L=CreateList();
    T=CreateList();
	S=CreateList();

	L=InsertList(L,1);
	L=InsertList(L,2);
	L=InsertList(L,3);

    InsertList(T,2);
	InsertList(T,3);
	InsertList(T,5);

	MergeList(L,T,S);

	return 0;

}