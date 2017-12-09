/*
请编写一高效算法，实现两个单链表的右对齐打印，并分析其时间复杂度和空间复杂度，比如两个链表1->2->3->4->5和6->7->8的打印效果是:
1 2 3 4 5-
   6 7 8
单链表结点定义如下：
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkList;
*/
#include<stdio.h>
#include<stdlib.h>

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkList;

LinkList InitList();//初始化链表;
void  CreateLinkListTail(LinkList *pHead,int k,int n);
void PrintfL(LinkList pHead);

int main()
{
    LinkList ha=NULL,hb=NULL;
    LinkList p=NULL,p1=NULL,p2=NULL;
    LinkList pl=NULL,ps=NULL;//pl记录长的链表，ps记录短链表

    ha=InitList();
    hb=InitList();

    CreateLinkListTail(&ha,1,5);
    CreateLinkListTail(&hb,6,3);

    /* ****************************右对齐打印链表************************************ */
    p1=ha->next;
    p2=hb->next;
    while(p1&&p2)
    {
        p1=p1->next;
        p2=p2->next;
    }
    if(p1!=NULL)
    {
        pl=ha;
        ps=hb;
        p=p2;
    }
    else
    {
        pl=hb;
        ps=ha;
        p=p1;
    }

    PrintfL(pl);
    p=p1;
    while(p)
    {
        printf("  ");
        p=p->next;
    }
    PrintfL(ps);
    /* ****************************************************************************** */
    return 0;
}
LinkList InitList()//初始化链表
{
    LinkList L = (LinkList)malloc(sizeof(ListNode));
    L->data=0;
    L->next = NULL;
    return L;
}
/*尾插法建立单链表*/
void  CreateLinkListTail(LinkList *pHead,int k,int n)//pHead的类型为LinkList *，目的是为了带回链表信息，相当于引用传递
{
    LinkList pNew;//定义新结点的指针
    LinkList pEnd;//定义链表尾指针
	int i,j ;
    pEnd = *pHead;//初始时，尾指针为空
    for( j=1,i = k; j<=n;i++, j++)//循环构建链表结点
    {
        pNew= (LinkList)malloc(sizeof(ListNode));//动态生成新结点
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
}
void PrintfL(LinkList pHead)
{
    LinkList p=pHead->next;
    while(p!=pHead&&p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
/*
时间复杂度：O(n)
空间复杂度：O(1)
*/
