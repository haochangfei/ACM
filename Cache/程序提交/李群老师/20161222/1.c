/*
��Ŀ����������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��
�������㶨�����£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

*/

#include<stdio.h>

#define MAX 50

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
//�����ʼ��
LinkedList InitList()
{
    LinkedList L = (LinkedList)malloc(sizeof(ListNode));
    L->next = NULL;
    return L;
}
//��ͷ�巨��ӽڵ�
LinkedList AddNode(LinkedList L,int data)
{
    LinkedList p = (LinkedList)malloc(sizeof(ListNode));
    p->next = L->next;
    L->next = p;
    p->data = data;
    return L;
}
//��������
void Print(LinkedList L)
{
    LinkedList p = L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

//��β��ͷ��������ӡ��ÿ������ֵ
void InverOrderPrint(LinkedList L)
{
    int a[MAX],i = 0;
    LinkedList p = L->next;
    //��������б���������������浽����a��
    while(p)
    {
        a[i]=p->data;
        p=p->next;
        i++;
    }
    i--;
    for(;i>=0;i--)//��a����Ԫ�ص������
    {
        printf("%d ",a[i]);
    }

}

int main()
{
    LinkedList L = InitList();
    L = AddNode(L,7);
    L = AddNode(L,6);
    L = AddNode(L,5);
    L = AddNode(L,4);
    L = AddNode(L,3);
    printf("�����е�Ԫ���У�\n");
    Print(L);
    printf("\n������������е�Ԫ�أ�\n");
    InverOrderPrint(L);
    return 0;
}

//ʱ�临�Ӷ�O(n)
//�ռ临�Ӷ�O(n)
