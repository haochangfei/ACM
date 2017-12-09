/*
��Ŀ��������������м��㡣����������н������Ϊ�����������м��㣻������������ż���������м�������������һ����
�������㶨�����£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�
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

void Initialization()//����������ֵ
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
int Length(LinkedList L)//����������
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
�㷨������ʱ�临�Ӷ�T(n)=O(n);�ռ临�Ӷ�S(n)=O(1);
*/
