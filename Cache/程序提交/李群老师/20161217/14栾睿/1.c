/*
    题目描述：编程实现单链表的反转。要求输出反转前与反转后的单链表。
        链表结点定义如下：
        typedef  struct  ListNode
        {
           int  data;
           struct ListNode  *next;
        }ListNode, *LinkedList;
    如：
        反转前：1->2->3->4->5
        反转后：5->4->3->2->1

*/

#include<stdio.h>

typedef  struct  ListNode
{
    int  data;
    struct ListNode  *next;

}ListNode, *LinkedList;

//头插法
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

//打印链表
void Print(LinkedList L)
{
    LinkedList p = L->next;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}
//链表逆置
LinkedList Reserve(LinkedList L)
{
    LinkedList p,q;
    p = L->next;
    L->next = NULL;
    while(p)
    {//再进行一次头插法
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
    printf("逆置前：\n");
    Print(L);
    printf("\n");
    printf("逆置后：\n");
    L = Reserve(L);
    Print(L);
    return 0;
}
//时间复杂度O(n)
//空间复杂度O(1)
