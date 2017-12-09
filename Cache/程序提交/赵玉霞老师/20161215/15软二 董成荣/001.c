/*
解题思路:额外定义两个变量，挨个比较
时间复杂度:O(n^2)
空间复杂度:o(n);
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct ListNode
{
    int data;
    struct ListNode *next;
}ListNode,*LinkedList;
int main()
{
	LinkedList pHeader1,pHeader2;
	LinkedList p,q;
	int i;
	pHeader1=(LinkedList)malloc(sizeof(ListNode));
	pHeader2=(LinkedList)malloc(sizeof(ListNode));
	pHeader1->next=NULL;
	pHeader2->next=NULL;
	for(i=0;i<10;i++)
    {
        p=(LinkedList)malloc(sizeof(ListNode));
        scanf("%d",&p->data);
        p->next=pHeader1->next;
        pHeader1->next=p;
    }
    for(i=0;i<10;i++)
    {
        q=(LinkedList)malloc(sizeof(ListNode));
        scanf("%d",&q->data);
        q->next=pHeader2->next;
        pHeader2->next=q;
    }
    for(p=pHeader1->next;p!=NULL;p=p->next)
    {
        for(q=pHeader2->next;q!=NULL;q=q->next)
            if(p->data==q->data)
            {
                 printf("%d",q->data);
                 return 0;
            }
    }
    if(p==NULL)
        printf("无公共节点");
	return 0;
}
