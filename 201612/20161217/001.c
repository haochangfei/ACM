/*
��Ŀ���������ʵ�ֵ�����ķ�ת��Ҫ�������תǰ�뷴ת��ĵ�����
�����㶨�����£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
�磺��תǰ��1->2->3->4->5
    ��ת��5->4->3->2->1
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�
*/
#include<stdio.h>
#include<stdlib.h>
#define M 5

typedef  struct  ListNode
{
	int  data;
    struct ListNode  *next;
}ListNode, *LinkedList;

void Initialization();

LinkedList head;

main()
{
	int i=0;
	LinkedList p,q,phead;
	Initialization();
	p=head;
	phead=NULL;
	for(i;i<M;i++)
    {
		q=p->next;
		p->next=phead;
		phead=p;
		p=q;
    }
	p=phead;
	for(i;i<M;i++)//���������
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void Initialization()//����������ֵ
{
    int i;
    LinkedList p,q;
    head=(LinkedList)malloc(sizeof(ListNode));
    head->data=1;
    head->next=NULL;
    q=head;
    for(i=1;i<M;i++)
    {
        p=(LinkedList)malloc(sizeof(ListNode));
        q->next=p;
        p->next=NULL;
        q=p;
        q->data=i+1;
    }
}
/*
�㷨����������ͷ�巨���������� ��Ϊ��ת����
        ʱ�临�Ӷ�T(n)=O();�ռ临�Ӷ�S(n)=O();
*/
