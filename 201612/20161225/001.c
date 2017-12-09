/*
有两个带头结点的循环单链表ha和hb，
设计一个算法将它们首尾合并成一个带头结点的单链表hc，
要求不再开辟新的空间。请写一高效算法，并分析时间性能和空间性能。
*/
#include<stdio.h>
#include<stdlib.h>

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkList;

LinkList InitList();//初始化链表
void  CreateLinkListTail(LinkList *pHead,int k,int n);//建立链表，第一个值为k，依次加1，建立n个结点
void PrintfL(LinkList pHead);//输出链表

int main()
{
    LinkList p,ha,hb,hc;

    ha=InitList();
    hb=InitList();

    CreateLinkListTail(&ha,1,4);
    CreateLinkListTail(&hb,5,3);

    PrintfL(ha);
    PrintfL(hb);

    /* *****************************连接两个循环链表**************************************** */
    hc=ha;
    while(ha->next!=hc)
    {
        ha=ha->next;
    }
    ha->next=hb->next;
    p=hb->next;
    while(p->next!=hb)
    {
        p=p->next;
    }
    p->next=NULL;
    free(hb);
    /* ************************************************************************************ */
    PrintfL(hc);

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
    pEnd->next=*pHead;//首位相连，建立循环链表
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
//算法分析：时间复杂度O(n)，空间复杂度：O(1)；
