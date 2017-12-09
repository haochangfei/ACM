/*
��Ŀ�������ϲ������ǽ��������絥�����1->2->3�͵�����2->3->5�ϲ�Ϊ1->2->3->5��
        �������㶨�����£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

*/
#include<stdio.h>

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

//��ʼ��
LinkedList InitList()
{
    LinkedList L = (LinkedList)malloc(sizeof(ListNode));
    L->next = NULL;
    return L;
}

//ͷ�巨
LinkedList CreateList(LinkedList L,int data)
{
    LinkedList p = (LinkedList)malloc(sizeof(ListNode));
    p->next = L->next;
    L->next = p;
    p->data = data;
    return L;
}
//��������
void PrintList(LinkedList L)
{
    LinkedList p = L->next;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

//�ϲ������ǽ�������
LinkedList MergeList(LinkedList L1,LinkedList L2)
{
    LinkedList L3 = (LinkedList)malloc(sizeof(ListNode));
    LinkedList p1 = L1->next,p2 = L2->next,p3 = L3;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data > p2->data)
        {
            p3->next = p2;
            p2= p2->next;
            p3= p3->next;
        }
        else if(p1->data < p2->data)
        {
            p3->next = p1;
            p1= p1->next;
            p3= p3->next;
        }
        else
        {
            p3->next = p1;
            p1= p1->next;
            p2= p2->next;
            p3= p3->next;
        }
    }
    if(p1==NULL)//��p1�ȱ����꣬��ֱ�ӽ�p2�ӵ�p3��
    {
       p3->next = p2;
    }
    else//��p2�ȱ����꣬��ֱ�ӽ�p1�ӵ�p3��
    {
       p3->next = p1;
    }
    return L3;
}
int main()
{
    LinkedList L1 = InitList(),L2 = InitList(),L3;
    L1=CreateList(L1,3);
    L1=CreateList(L1,2);
    L1=CreateList(L1,1);
    printf("L1�����е�Ԫ�أ�");
    PrintList(L1);

    L2=CreateList(L2,5);
    L2=CreateList(L2,3);
    L2=CreateList(L2,2);
    printf("\nL2�����е�Ԫ�أ�");
    PrintList(L2);

    L3=MergeList(L1,L2);
    printf("\n�ϲ�L1,L2��L3�����е�Ԫ�أ�");
    PrintList(L3);
    return 0;
}
//ʱ�临�Ӷ�O(n+m)
//�ռ临�Ӷ�O(1)
