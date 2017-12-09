/*
题目描述：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
单链表结点定义如下：
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
//链表初始化
LinkedList InitList()
{
    LinkedList L = (LinkedList)malloc(sizeof(ListNode));
    L->next = NULL;
    return L;
}
//用头插法添加节点
LinkedList AddNode(LinkedList L,int data)
{
    LinkedList p = (LinkedList)malloc(sizeof(ListNode));
    p->next = L->next;
    L->next = p;
    p->data = data;
    return L;
}
//遍历链表
void Print(LinkedList L)
{
    LinkedList p = L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

//从尾到头反过来打印出每个结点的值
void InverOrderPrint(LinkedList L)
{
    int a[MAX],i = 0;
    LinkedList p = L->next;
    //对链表进行遍历，并将结果保存到数组a中
    while(p)
    {
        a[i]=p->data;
        p=p->next;
        i++;
    }
    i--;
    for(;i>=0;i--)//将a数组元素倒序输出
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
    printf("链表中的元素有：\n");
    Print(L);
    printf("\n倒序输出链表中的元素：\n");
    InverOrderPrint(L);
    return 0;
}

//时间复杂度O(n)
//空间复杂度O(n)
