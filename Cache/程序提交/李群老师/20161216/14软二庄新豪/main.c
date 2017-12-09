//
//  main.c
//  2016-12-16
//
//  Created by gno on 16/12/16.
//  Copyright © 2016年 gno. All rights reserved.
//
/*
 *20161216题目
 *题目描述：输出一个单链表中倒数第k个结点。规定：链表的尾结点是倒数第1个结点。
 *链表结点定义如下：
 *typedef  struct  ListNode
 *{    int  data;
 *struct ListNode  *next;
 *}ListNode, *LinkedList;
 *题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
    int m_nKey;
    struct ListNode* m_pNext;
}ListNode;
void appendNode(ListNode **L,int m_nKey)
{
    ListNode * swapNode = (ListNode *)malloc(sizeof(ListNode));
    if(!swapNode)exit(-1);
    swapNode = *L;
    while(swapNode->m_pNext)swapNode  = swapNode->m_pNext;
    ListNode * newNode = (ListNode *)malloc(sizeof(ListNode));
    if(!newNode)exit(-1);
    newNode->m_nKey = m_nKey;
    newNode->m_pNext = NULL;
    swapNode->m_pNext = newNode;
    return ;
}
int getLength(ListNode *L)
{
    int length = 0;
    ListNode * swapNode = (ListNode *)malloc(sizeof(ListNode));
    if(!swapNode)exit(-1);
    swapNode = L->m_pNext;
    while(swapNode)
    {
        swapNode=swapNode->m_pNext;
        length++;
    }
    return length;
}
void printNode(ListNode *L,int index)
{
    int timer = 1;
    ListNode * swapNode = (ListNode *)malloc(sizeof(ListNode));
    if(!swapNode)exit(-1);
    swapNode = L->m_pNext;
    while(swapNode)
    {
        if(timer == index)
        {
            printf("%d\n",swapNode->m_nKey);
            return ;
        }
        timer++;
        swapNode=swapNode->m_pNext;
    }
}
int main(int argc, const char * argv[]) {
    ListNode *L = (ListNode*)malloc(sizeof(ListNode));
    L->m_pNext = NULL;
    appendNode(&L, 1);
    appendNode(&L, 4);
    appendNode(&L, 5);
    appendNode(&L, 6);
    appendNode(&L, 7);
    //1.获取当前链表的总长度
    int length  = getLength(L);
    //2.获取倒数第2个 即是正数第四个 总长度＋1-k
    printNode(L, length+1-2);
    return 0;
}
//时间复杂度
//O(n+m)
//空间复杂度
//O(1)
