/*
解题思路:
    问题:合并链表（升序）
    分析:特点是升序，以第一个为主体将第二个添加到第一个里面，添加元素小于1中元素加在1前面2后移，大于1后移，等于1、2都后移
时间复杂度:O(N)
空间复杂度:o(1);
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ListNode
{
    int data;
    struct ListNode *next;
}ListNode,*LinkedList;
int main()
{
    int i,n;
	LinkedList header1,header2;
	LinkedList q,p,temp;
	header1=(LinkedList)malloc(sizeof(ListNode));
	header1->next=NULL;
	header2=(LinkedList)malloc(sizeof(ListNode));
	header2->next=NULL;
	q=header1;
	for(i=0;i<3;i++)
    {
        p=(LinkedList)malloc(sizeof(ListNode));
        scanf("%d",&p->data);
        p->next=q->next;
        q->next=p;
        q=q->next;
    }
    q=header2;
	for(i=0;i<3;i++)
    {
        p=(LinkedList)malloc(sizeof(ListNode));
        scanf("%d",&p->data);
        p->next=q->next;
        q->next=p;
        q=q->next;
    }
    q=header1;
    p=header2->next;
    while(p!=NULL && q->next!=NULL)
    {
        if(q->next->data<p->data)
        {
            q=q->next;
        }
        else if(q->next->data>p->data)
        {
            temp=p;
            p=p->next;
            temp->next=q->next;
            q->next=temp;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
    if(q->next==NULL && p!=NULL)
    {
        q->next=p;
    }
    p=header1->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
	return 0;
}
