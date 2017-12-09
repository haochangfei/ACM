//
//  main.c
//  2016-12-21
//
//  Created by gno on 16/12/21.
//  Copyright © 2016年 gno. All rights reserved.
//
/*
 20161221题目
 题目描述：合并两个非降序单链表。如单链表表1->2->3和单链表2->3->5合并为1->2->3->5。
 单链表结点定义如下：
 typedef  struct  ListNode
 {    int  data;
 struct ListNode  *next;
 }ListNode, *LinkedList;
 题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度
 */
#include <stdio.h>
typedef struct listNode
{
    int data;
    struct listNode * next;
}ListNode;
//init list
void init_list(ListNode **L)
{
    *L = (ListNode *)malloc(sizeof(ListNode));
    if(!*L)
    {
        printf("Error\n");
        return;
    }
    (*L)->next = NULL;
    return;
}
//insert node to head
void add_node_head(ListNode**L,int data)
{
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if(!newNode)return;
    newNode->data = data;
    newNode->next = (*L)->next;
    (*L)->next = newNode;
    return;
}
//print union set
void merge_list(ListNode *L1, ListNode * L2)
{
    ListNode * swap_1 = L1->next;
    ListNode * swap_2 = L2->next;
    while(swap_1!= NULL && swap_2 != NULL)
    {
        int save;
        if(swap_1->data > swap_2->data)
        {
            save = swap_2->data;
            printf("%d ",swap_2->data);
            while(swap_2 != NULL && swap_2->data == save)
                swap_2 = swap_2->next;
        }
        else if(swap_1->data < swap_2->data)
        {
            save = swap_1->data;
            printf("%d ",swap_1->data);
            while(swap_1 != NULL && swap_1->data == save)
                swap_1 = swap_1->next;
        }
        else
        {
            save = swap_1->data;
            printf("%d ",swap_1->data);
            while(swap_1 != NULL && swap_1->data == save)
                swap_1 = swap_1->next;
            while(swap_2 != NULL && swap_2->data == save)
                swap_2 = swap_2->next;
        }
        
        if(swap_1 == NULL && swap_2 == NULL)
            break;
    }
    while(swap_1 != NULL)
    {
        int save = swap_1->data;
        printf("%d ",swap_1->data);
        while(swap_1 != NULL && swap_1->data == save)
            swap_1 = swap_1->next;
        if(swap_1 == NULL)
            break;
    }
    while(swap_2 != NULL)
    {
        int save = swap_2->data;
        printf("%d ",swap_2->data);
        while(swap_2 != NULL && swap_2->data == save)
            swap_2 = swap_2->next;
        if(swap_2 == NULL)
            break;
    }
}
int main(int argc, const char * argv[]) {
    ListNode *L1,*L2;
    int args_1[] = {3,2,1};
    int args_2[] = {5,3,2};
    init_list(&L1);
    init_list(&L2);
    for(int i = 0;i<3;i++)
    {
        add_node_head(&L1, args_1[i]);
        add_node_head(&L2, args_2[i]);
    }
    merge_list(L1, L2);
    printf("\n");
    return 0;
}
//时间复杂度
//O(m+n)
//空间复杂度
//O(1)
