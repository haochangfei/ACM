/*
题目描述：判断一个单向链表是否形成了环状结构。
单链表结点定义如下：
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include<stdlib.h>
#define M 5

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

void Initialization();
void printfL(LinkedList *L,int len);
void Judgmentring(LinkedList L);

LinkedList head;

main()
{
    Initialization();
    printfL(head,20);
    Judgmentring(head);
}

void Judgmentring(LinkedList L)//判断单链表是否是环
{
    LinkedList p;
    p=L->next;
    while(p->next!=L&&p->next!=NULL)//当最后一个指向头时或最后一个指向空时，结束！
    {
        p=p->next;
    }
    if(p->next==L)
        printf("环");
    else
        printf("不是环");
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
    p->next=head;//形成环，注释掉可检验不为环时运行结果！
}

void printfL(LinkedList *L,int len)//输出单链表，如果为环输出len个结点；
{                                  //如果不为环，当len<链表长度，输出len个结点，否则遍历到尾结束。
    int i=0;
    LinkedList p=L;
    for(i;i<len&&p!=NULL;i++)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
/*
算法分析：时间复杂度T(n)=O();空间复杂度S(n)=O();
*/
