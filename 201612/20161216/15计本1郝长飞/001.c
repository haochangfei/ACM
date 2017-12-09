/*
题目描述：输出一个单链表中倒数第k个结点。规定：链表的尾结点是倒数第1个结点。
链表结点定义如下：
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

LinkedList ph;

void Initialization();
int Length(LinkedList L);

main()
{
    Initialization();
    int i=0,len=0,n=0;
    int k;
    LinkedList p,q;
    p=ph;
    printf("单链表：");
    for(i;i<M;i++)//输出单链表
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    scanf("%d",&k);
    len=Length(ph);
    i=0;
    if(k<=len)
    {
        n=len-k;
        q=ph;
        for(i;i<n;i++)
        {
            q=q->next;
        }
        printf("%d",q->data);
    }
    else
    {
        printf("你输入的k值大于单链表长度，请输入不大于%d的数。",M);
    }

}

void Initialization()//建立链表并赋值
{
    int i;
    LinkedList p,q;
    ph=(LinkedList)malloc(sizeof(ListNode));
    ph->data=1;
    ph->next=NULL;
    q=ph;
    for(i=1;i<M;i++)
    {
        p=(LinkedList)malloc(sizeof(ListNode));
        q->next=p;
        p->next=NULL;
        q=p;
        q->data=i+1;
    }
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
