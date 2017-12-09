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
    phead=Reversing(head);
    printf("\n��ת������");
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
�㷨������ʱ�临�Ӷ�T(n)=O(n);�ռ临�Ӷ�S(n)=O(1);
*/
