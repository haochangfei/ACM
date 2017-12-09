/*
题目描述：有两个单向链表，头指针分别为pHeader1，pHeader2，请判断这两个链表是否有公共结点。
如果有，给出第一个公共结点。程序不能改变链表的内容，可以使用额外的空间，时间复杂度尽量小。
链表结点定义如下：
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
如：p所指的为第一个公共结点
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

void Initialization();
int Length(LinkedList L);

LinkedList pHeader1,pHeader2;

main()
{
    int i=0;
    int lenp,lenq;
    int n=0;
    LinkedList p,q;
    Initialization();
    p=pHeader1;
    q=pHeader2;
    lenp=Length(p);
    lenq=Length(q);
    if(lenp>=lenq)//使他们长度相同,也就是长链表公共点的前一个
    {
        n=lenp-lenq;
        for(i;i<n;i++)
            p=p->next;
    }
    else
    {
        n=lenq-lenp;
        for(i;i<n;i++)
            q=q->next;
    }
    i=0;
    while(i<lenp)
    {
        if((p->next)==(q->next))
        {
            printf("%d",p->next->data);
            break;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
}
void Initialization()//建立链表并赋值
{
    int i;
    LinkedList p,q;
    pHeader1=(LinkedList)malloc(sizeof(ListNode));
    pHeader1->data=1;
    pHeader1->next=NULL;
    pHeader2=(LinkedList)malloc(sizeof(ListNode));
    pHeader2->data=4;
    pHeader2->next=NULL;
    q=pHeader1;
    for(i=0;i<3;i++)
    {
        p=(LinkedList)malloc(sizeof(ListNode));
        q->next=p;
        p->next=NULL;
        q=p;
        q->data=i+2;
    }
    pHeader2->next=pHeader1->next->next;
}
int Length(LinkedList L)//计算链表长度
{
    int i=0;
    LinkedList p=L;
    while(p!=NULL)
    {
        p=p->next;
        i++;
    }
    return i;
}
/*
算法分析：时间复杂度T(n)=O(n);空间复杂度S(n)=O(1);
*/

