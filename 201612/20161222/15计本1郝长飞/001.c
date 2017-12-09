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
    phead=Reversing(head);
    printf("\n反转单链表：");
    Lprintf(phead);

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
LinkedList Reversing(LinkedList L)
{
    LinkedList p,q;
    p = L->next;
    L->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
    return L;
}
/*
算法分析：时间复杂度T(n)=O(n);空间复杂度S(n)=O(1);
*/
