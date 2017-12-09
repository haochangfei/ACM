/*
��Ŀ�������ϲ������ǽ��������絥�����1->2->3�͵�����2->3->5�ϲ�Ϊ1->2->3->5��
�������㶨�����£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�
*/
#include<stdio.h>
#include<stdlib.h>

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

LinkedList InitList();//��ʼ������
void ListInsert(LinkedList L, int i);//����i������

main()
{
    LinkedList phead1,phead2,phead3;
    LinkedList p,q,pt;

    phead1=InitList();
    phead2=InitList();
    phead3=InitList();

    ListInsert(phead1,3);
    ListInsert(phead1,2);
    ListInsert(phead1,1);
    ListInsert(phead2,5);
    ListInsert(phead2,3);
    ListInsert(phead2,2);

    p=phead1->next;
    q=phead2->next;
    pt=phead3;

    while(p!=NULL&&q!=NULL)
    {
        if(p->data > q->data)//˭С��˭���ӵ�pt��
        {
            pt->next=q;
            q=q->next;
            pt=pt->next;

        }
        else if(p->data < q->data)
        {
            pt->next=p;
            p=p->next;
            pt=pt->next;

        }
        else//��ȵ���һ����ָ��ͬʱ����
        {
            pt->next=p;
            q=q->next;
            p=p->next;
            pt=pt->next;

        }
    }
    if(p==NULL)//˭���գ���˭���ӵ�pt��
        pt->next=q;
    else
        pt->next=p;

    pt=phead3->next;
    while(pt)
    {
        printf("%d ",pt->data);
        pt=pt->next;
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
/*
�㷨������ʱ�临�Ӷ�T(n)=O(n);�ռ临�Ӷ�S(n)=O(1);
*/
