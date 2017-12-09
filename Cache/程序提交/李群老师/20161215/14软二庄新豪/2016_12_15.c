#include<stdlib.h>
#include<stdio.h>
/*
*先将链表一的尾部指向另一个链表，然后判断链表中是否存在环，存在环可以设置两个指针，一个位移为2另一个位移为1，若相遇则存在环，若存在环则相交
*相交后分别求链表长度，并求出差值然后遍历长的链表遍历长度为差值，遍历结束后指针所指向的便是第一个交点
*/
typedef struct linknode
{
    int data;
    struct linknode *next;
}LinkNode;
//初始化链表
LinkNode * initLink(LinkNode *L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    if(!L)return NULL;
    L->next = NULL;
    return L;
}
//头插法
LinkNode * insertHeadLink(LinkNode *L,int data)
{
    LinkNode *swap = (LinkNode *)malloc(sizeof(LinkNode));
    if(!swap)return NULL;
    swap->data = data;
    swap->next = L->next;
    L->next = swap;
    return L;
}
//计算链表长度
int getLength(LinkNode *L)
{
    int length = 0;
    LinkNode *swap = NULL;
    if(!L)return length;
    swap = L->next;
    while(swap)
    {
        length++;
        swap = swap->next;
    }
    return length;
}
//连接两个链表
void linkTable(LinkNode *L1,LinkNode *L2)
{
    LinkNode *swap = NULL;
    if(!L1||!L2)return;
    swap = L1;
    while(swap->next)
        swap = swap->next;
    swap->next = L2->next;
    return ;
}
//判断链表是否有环
int isExistRing(LinkNode *L)
{
    LinkNode *quick,*low;
    if(!L)return 2;
    quick = L->next;
    low = L;
    while(low)
    {
        if(!quick)return 0;
        if(low==quick)return 1;
        low = low->next;
        quick = quick->next;
        if(low==quick)return 1;
        quick = quick->next;
    }
    return 0;
}
main()
{
    LinkNode *L1 = NULL,*L2 = NULL;
    LinkNode *swap = NULL;
    LinkNode *ln1 = NULL,*ln2 = NULL;
    int length1 , length2;
    int dif = 0;
    int i = 0;
    L1 = initLink(L1);
    L2 = initLink(L2);
    for(i = 0;i<12;i++)
    {
        if(i<4)
            L1 = insertHeadLink(L1,i);
        else
            L2 = insertHeadLink(L2,i);
    }
    //使链表相交
    swap = L1;
    while(swap->next)swap = swap->next;
    swap->next = L2->next->next->next;
    //获取两个链表长度
    length1 = getLength(L1);
    length2 = getLength(L2);
    if(length1>length2)dif = length1-length2;
    else dif = length2-length1;
    //构造环
    linkTable(L1,L2);
    if(!isExistRing(L1))
    {
        printf("两个链表不相交\n");
        return ;
    }
    ln1 = L1->next;
    ln2 = L2->next;
    i = 0;
    if(length1>length2)
    {
        while(i<dif)
        {
            ln1 = ln1->next;
            i++;
        }
        while(ln1!=ln2)
        {
            ln1 = ln1->next;
            ln2 = ln2->next;
        }
    }
    else
    {
        while(i<dif)
        {
            ln2 = ln2->next;
            i++;
        }
        while(ln1!=ln2)
        {
            ln1 = ln1->next;
            ln2 = ln2->next;
        }
    }
    printf("相遇节点数据域的值:%d\n",l1->data);
}
//时间复杂度
//O(n+m)
//空间复杂度
//O(1)
