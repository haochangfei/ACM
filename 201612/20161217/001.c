/*
题目描述：编程实现单链表的反转。要求输出反转前与反转后的单链表。
链表结点定义如下：
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
如：反转前：1->2->3->4->5
    反转后：5->4->3->2->1
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
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
	for(i;i<M;i++)//输出单链表
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void Initialization()//建立链表并赋值
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
算法分析：利用头插法建立新链表 即为反转链表。
        时间复杂度T(n)=O();空间复杂度S(n)=O();
*/
