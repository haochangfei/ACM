/*��Ŀ�������ϲ������ǽ��������絥�����1->2->3�͵�����2->3->5�ϲ�Ϊ1->2->3->5��
�������㶨�����£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�*/


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