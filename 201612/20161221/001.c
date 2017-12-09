/*
题目描述：合并两个非降序单链表。如单链表表1->2->3和单链表2->3->5合并为1->2->3->5。
单链表结点定义如下：
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include<stdlib.h>

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

LinkedList InitList();//初始化链表
void ListInsert(LinkedList L, int i);//插入i到链表

main()
{
    LinkedList phead1,phead2,phead3;
    LinkedList p,q,pt;

    phead1=InitList();
    phead2=InitList();
    phead3=InitList();

    ListInsert(phead1,3);
    ListInsert(phead1,2);
    ListInsert(phead1,1);
    ListInsert(phead2,5);
    ListInsert(phead2,3);
    ListInsert(phead2,2);

    p=phead1->next;
    q=phead2->next;
    pt=phead3;

    while(p!=NULL&&q!=NULL)
    {
        if(p->data > q->data)//谁小将谁链接到pt上
        {
            pt->next=q;
            q=q->next;
            pt=pt->next;

        }
        else if(p->data < q->data)
        {
            pt->next=p;
            p=p->next;
            pt=pt->next;

        }
        else//相等的连一个，指针同时后移
        {
            pt->next=p;
            q=q->next;
            p=p->next;
            pt=pt->next;

        }
    }
    if(p==NULL)//谁不空，将谁链接到pt上
        pt->next=q;
    else
        pt->next=p;

    pt=phead3->next;
    while(pt)
    {
        printf("%d ",pt->data);
        pt=pt->next;
    }
}

LinkedList InitList()
{
    LinkedList L = (LinkedList)malloc(sizeof(ListNode));
    L->data=0;
    L->next = NULL;
    return L;
}
void ListInsert(LinkedList L, int i)
{
    LinkedList p = (LinkedList)malloc(sizeof(ListNode));
    p->next = L->next;
    p->data = i;
    L->next = p;
}
/*
算法分析：时间复杂度T(n)=O(n);空间复杂度S(n)=O(1);
*/
