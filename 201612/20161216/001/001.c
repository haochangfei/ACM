/*
��Ŀ���������һ���������е�����k����㡣�涨�������β����ǵ�����1����㡣
�����㶨�����£�
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
    printf("������");
    for(i;i<M;i++)//���������
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
        printf("�������kֵ���ڵ������ȣ������벻����%d������",M);
    }

}

void Initialization()//����������ֵ
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
