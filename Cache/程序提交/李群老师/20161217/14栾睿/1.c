/*
    ��Ŀ���������ʵ�ֵ�����ķ�ת��Ҫ�������תǰ�뷴ת��ĵ�����
        �����㶨�����£�
        typedef  struct  ListNode
        {
           int  data;
           struct ListNode  *next;
        }ListNode, *LinkedList;
    �磺
        ��תǰ��1->2->3->4->5
        ��ת��5->4->3->2->1

*/

#include<stdio.h>

typedef  struct  ListNode
{
    int  data;
    struct ListNode  *next;

}ListNode, *LinkedList;

//ͷ�巨
LinkedList CreatLinkedList(LinkedList L,int n)
{
    int i;
    LinkedList p;
    L = (LinkedList)malloc(sizeof(ListNode));
    L->next = NULL;
    for(i = n;i > 0;i--)
    {
      p = (LinkedList)malloc(sizeof(ListNode));
      p->data = i;
      p->next = L->next;
      L -> next= p;
    }

    return L;
}

//��ӡ����
void Print(LinkedList L)
{
    LinkedList p = L->next;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}
//��������
LinkedList Reserve(LinkedList L)
{
    LinkedList p,q;
    p = L->next;
    L->next = NULL;
    while(p)
    {//�ٽ���һ��ͷ�巨
        q = p;
        p = p->next;

        q->next = L->next;
        L->next = q;
    }
    return L;
}

int main()
{
    LinkedList L;
    L = CreatLinkedList(L,5);
    printf("����ǰ��\n");
    Print(L);
    printf("\n");
    printf("���ú�\n");
    L = Reserve(L);
    Print(L);
    return 0;
}
//ʱ�临�Ӷ�O(n)
//�ռ临�Ӷ�O(1)
