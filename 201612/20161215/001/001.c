/*
��Ŀ��������������������ͷָ��ֱ�ΪpHeader1��pHeader2�����ж������������Ƿ��й�����㡣
����У�������һ��������㡣�����ܸı���������ݣ�����ʹ�ö���Ŀռ䣬ʱ�临�ӶȾ���С��
�����㶨�����£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�
�磺p��ָ��Ϊ��һ���������
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
    if(lenp>=lenq)//ʹ���ǳ�����ͬ,Ҳ���ǳ����������ǰһ��
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
void Initialization()//����������ֵ
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

