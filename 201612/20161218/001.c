/*
题目描述：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。
链表结点与函数的定义如下：
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
void DeleteNode(LinkedList   *pListHead,  LinkedList  pToBeDeleted);
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#define M 5

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

void Initialization();
void printfL(LinkedList *L);
void DeleteNode(LinkedList   *pListHead,  LinkedList  pToBeDeleted);

LinkedList head;
LinkedList temp;//要删除结点！

main()
{
    int i=0;
    LinkedList p;
    Initialization();
    printfL(head);
    DeleteNode(head,temp);
    p=head;
    for(i;i<M-1;i++)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
void Initialization()//建立链表并赋值,并设立temp指向要删除结点
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
    p=head;
    for(i=0;i<2;i++)
    {
        p=p->next;
    }
    temp=p;
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
void DeleteNode(LinkedList   *pListHead,  LinkedList  pToBeDeleted)
{
    LinkedList p;
    p=head;
    while(p->next!=pToBeDeleted)
    {
        p=p->next;
    }
    p->next=p->next->next;
    free(pToBeDeleted);
}
/*
算法分析：时间复杂度T(n)=O(n);空间复杂度S(n)=O(1);
*/
