/*
��Ŀ����������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
�������㶨�����£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�
*/
#include<stdio.h>
#define M 100

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

LinkedList InitList();//��ʼ������
void ListInsert(LinkedList L, int i);//����i������
void Lprintf(LinkedList L);//�������
LinkedList Reversing(LinkedList L);//����ͷ�巨��ת����

main()
{
    int i=0,a[M]={0};//����˳���洢��ȡ������ֵ
    LinkedList head,phead;
    LinkedList p;
    head = InitList();
    ListInsert(head,5);
    ListInsert(head,4);
    ListInsert(head,3);
    ListInsert(head,2);
    ListInsert(head,1);
    printf("������");
    Lprintf(head);
    printf("\n���Ŵ�ӡ��");
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
�㷨������ʱ�临�Ӷ�T(n)=O(n);�ռ临�Ӷ�S(n)=O(n);���001.c δ�ı�����ṹ��
*/
