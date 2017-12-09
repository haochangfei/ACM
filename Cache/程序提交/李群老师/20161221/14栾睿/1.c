/*
题目描述：合并两个非降序单链表。如单链表表1->2->3和单链表2->3->5合并为1->2->3->5。
        单链表结点定义如下：
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

//初始化
LinkedList InitList()
{
    LinkedList L = (LinkedList)malloc(sizeof(ListNode));
    L->next = NULL;
    return L;
}

//头插法
LinkedList CreateList(LinkedList L,int data)
{
    LinkedList p = (LinkedList)malloc(sizeof(ListNode));
    p->next = L->next;
    L->next = p;
    p->data = data;
    return L;
}
//遍历链表
void PrintList(LinkedList L)
{
    LinkedList p = L->next;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

//合并两个非降序单链表
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
    if(p1==NULL)//若p1先遍历完，则直接将p2接到p3上
    {
       p3->next = p2;
    }
    else//若p2先遍历完，则直接将p1接到p3上
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
    printf("L1链表中的元素：");
    PrintList(L1);

    L2=CreateList(L2,5);
    L2=CreateList(L2,3);
    L2=CreateList(L2,2);
    printf("\nL2链表中的元素：");
    PrintList(L2);

    L3=MergeList(L1,L2);
    printf("\n合并L1,L2后L3链表中的元素：");
    PrintList(L3);
    return 0;
}
//时间复杂度O(n+m)
//空间复杂度O(1)
