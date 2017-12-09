/*
已知线性表中的元素以值递增有序排列，并以单链表做存储结构，试写一高效的算法，
删除表中所有值大于x且小于y的元素（若表中存在这样的元素），同时释放被删除的结点空间，
并分析算法的时间复杂度和空间复杂度，注意："x和 y是给定的两个参变量，它们的值可以和表中的元素相同，也可以不同"
单链表定义如下：
typedef  struct  LNode
{    int  data;
     struct  LNode  *next;
}LNode, *LinkList;

算法分析：时间复杂度：O(n) 空间复杂度：O（1）
*/

#include<stdio.h>
#include <stdlib.h>

typedef  struct  LNode
{    int  data;
     struct  LNode  *next;
}LNode, *LinkList;

void  CreateLinkListTail(LinkList *pHead,int n);
void  PrintList(LinkList pHead);
void  DataList(LinkList *pHead,int x,int y);
main()
{
	LinkList head = NULL;
	LinkList p1 = NULL;//记录第一个要删除的结点的前一个
	LinkList p2 = NULL;//记录最后一个要删除的结点后一个
	LinkList p = NULL;

	int x=3,y=8;//删除大于3且小于8的结点

	CreateLinkListTail(&head,10);//初始化链表1 2 3 4 5 6 7 8 9 10
	PrintList(head);//输出初始化后链表

	p=head;
	while (p)
	{
		if (p->data<=x)//寻找第一个不大于x的结点用p1记录
		{
			p1=p;
			p=p->next;
			
		}
		else if(p->data<=y)//寻找第一个不小于y的结点用p2记录
		{
			p2=p;
			p=p->next;
				
		}
		else
			p=p->next;
	}
	while (p1->next!=p2)//从p1的下一个开始删除 到p2结束
	{
		p=p1->next;
		p1->next=p->next;
		free(p);
	}
	
	PrintList(head);//输出删除后的单链表
}

/*尾插法建立单链表*/
void  CreateLinkListTail(LinkList *pHead,int n)//pHead的类型为LinkList *，目的是为了带回链表信息，相当于引用传递
{
    LinkList pNew;//定义新结点的指针
    LinkList pEnd;//定义链表尾指针
	int i ;
    pEnd = *pHead;//初始时，尾指针为空
    for( i = 1; i<=n; i++)//循环构建链表结点
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
}
/*遍历输出单链表中的所有结点，如输出格式为1->2->3->4->5。*/
void  PrintList(LinkList pHead)
{
    LinkList p;
    p = pHead;//从链表开始
    while(p->next)//输出除最后一个链表结点
    {
        printf("%d->",p->data);//输出格式%d->
        p = p->next;//链表指针后移
    }
    printf("%d\n",p->data);//循环结束后p指向最后一个结点，输出格式%d
}

