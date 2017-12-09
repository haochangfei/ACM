/*
题目描述：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
单链表结点定义如下：
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#define M 100

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

LinkedList InitList();//初始化链表
void ListInsert(LinkedList L, int i);//插入i到链表
void Lprintf(LinkedList L);//输出链表
LinkedList Reversing(LinkedList L);//利用头插法反转链表

main()
{
    int i=0,a[M]={0};//利用顺序表存储读取的链表值
    LinkedList head,phead;
    LinkedList p;
    head = InitList();
    ListInsert(head,5);
    ListInsert(head,4);
    ListInsert(head,3);
    ListInsert(head,2);
    ListInsert(head,1);
    printf("单链表：");
    Lprintf(head);
    printf("\n倒着打印：");
    p=head->next;
    while(p)
    {
        a[i++]=p->data;
        p=p->next;
    }
    while(i)
    {
     printf("%d ",a[i-1]);
     i--;
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
void Lprintf(LinkedList L)
{
    LinkedList p=L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
/*
算法分析：时间复杂度T(n)=O(n);空间复杂度S(n)=O(n);相比001.c 未改变链表结构。
*/
