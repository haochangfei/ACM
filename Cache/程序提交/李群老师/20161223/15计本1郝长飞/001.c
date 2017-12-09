/*
20161223题目
编号为1，2，3，4...，n的n个人按顺时针方向围成一个圆圈做游戏。从编号为1的人开始顺时针自1开始顺序报数，每次报到m停止报数，然后报m的人从这个圆圈里出列。接下来从他在顺时针方向上的下一个人开始重新从1报数，如此下去，求出这个圆圈里剩下的最后一个人的编号。
例如：n=10  ，m=2
出列序列为：2   4   6  8  10  3  7  1  9  5
最后一个人编号为5
再如：n=20 ，m=5
出列序列为：5   10   15   20   6   12   18  4   13  1   9   19  11   3   17   16   2   8   14   7
最后一个人编号为7
题目要求：尽量使用高效算法，描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include <stdlib.h>

typedef  struct  LNode
{    int  data;
     struct  LNode  *next;
}LNode, *LinkList;

void  CreateLinkListTail(LinkList *pHead,int n);
void  PrintDeteList(LinkList *pHead,int k);

main()
{
    int n=0,m=0;
    LinkList head = NULL;
    printf("10 2\n");
    n=10;
    m=2;
    CreateLinkListTail(&head,n);//初始化链表长度为0,1,2,3,4,5,6，n-1
	PrintDeteList(&head,m);//输出并删除第m个结点
	printf("\n20 5\n");
    n=20;
    m=5;
    CreateLinkListTail(&head,n);//初始化链表长度为0,1,2,3,4,5,6，n-1
	PrintDeteList(&head,m);//输出并删除第m个结点
}
/*尾插法建立单链表*/
void  CreateLinkListTail(LinkList *pHead,int n)//pHead的类型为LinkList *，目的是为了带回链表信息，相当于引用传递
{
    LinkList pNew;//定义新结点的指针
    LinkList pEnd;//定义链表尾指针
	int i ;
    pEnd = *pHead;//初始时，尾指针为空
    for( i = 0; i<n; i++)//循环构建链表结点
    {
        pNew= (LinkList)malloc(sizeof(LNode));//动态生成新结点
        pNew->data=i;//新结点的数据域
        pNew->next = NULL;//新结点为尾结点，后继域为NULL
        if(*pHead==NULL)//空链表
        {
            *pHead =pNew;//新结点为第一个结点
            pEnd = pNew;

        }else{
            pEnd->next=pNew;//新结点插入在链表末尾
            pEnd=pNew;//新结点成为尾结点
        }
    }
    pEnd->next=*pHead;
}
void  PrintDeteList(LinkList *pHead,int k)//输出并删除每一次第k个结点
{
    int t=k;
    LinkList p;
    LinkList q;
    p = *pHead;//从链表开始
    while(p->next!=p)//只剩一个的时候退出循环
    {
        t=k-1;
        while(t--)//寻找第k个结点的前一个结点
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        printf("%d ",q->data);//删除并输出第t个结点
        free(q);
    }
    printf("%d ",p->data);//输出最后一个结点
}
/*
算法分析：时间复杂度T(n)=O();空间复杂度S(n)=O(1);
*/
