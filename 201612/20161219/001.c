/*
题目描述：求单链表的中间结点。如果单链表中结点总数为奇数，返回中间结点；如果结点总数是偶数，返回中间两个结点的任意一个。
单链表结点定义如下：
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include<stdlib.h>
#define M 10

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

void Initialization();
void printfL(LinkedList *L);
int Length(LinkedList L);

LinkedList head;

main()
{
    int mid=0,i=0;
    Initialization();
    printfL(head);
    LinkedList p=head;
    int len=Length(head);
    mid=len/2;
    for(i=i;i<mid;i++)
    {
        p=p->next;
    }
    printf("%d",p->data);
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
void printfL(LinkedList *L)
{
    int i=0;
    LinkedList p=L;
    for(i;i<M;i++)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
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
