/*
���дһ��Ч�㷨��ʵ��������������Ҷ����ӡ����������ʱ�临�ӶȺͿռ临�Ӷȣ�������������1->2->3->4->5��6->7->8�Ĵ�ӡЧ����:
1 2 3 4 5-
   6 7 8
�������㶨�����£�
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

LinkList InitList();//��ʼ������;
void  CreateLinkListTail(LinkList *pHead,int k,int n);
void PrintfL(LinkList pHead);

int main()
{
    LinkList ha=NULL,hb=NULL;
    LinkList p=NULL,p1=NULL,p2=NULL;
    LinkList pl=NULL,ps=NULL;//pl��¼��������ps��¼������

    ha=InitList();
    hb=InitList();

    CreateLinkListTail(&ha,1,5);
    CreateLinkListTail(&hb,6,3);

    /* ****************************�Ҷ����ӡ����************************************ */
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
LinkList InitList()//��ʼ������
{
    LinkList L = (LinkList)malloc(sizeof(ListNode));
    L->data=0;
    L->next = NULL;
    return L;
}
/*β�巨����������*/
void  CreateLinkListTail(LinkList *pHead,int k,int n)//pHead������ΪLinkList *��Ŀ����Ϊ�˴���������Ϣ���൱�����ô���
{
    LinkList pNew;//�����½���ָ��
    LinkList pEnd;//��������βָ��
	int i,j ;
    pEnd = *pHead;//��ʼʱ��βָ��Ϊ��
    for( j=1,i = k; j<=n;i++, j++)//ѭ������������
    {
        pNew= (LinkList)malloc(sizeof(ListNode));//��̬�����½��
        pNew->data=i;//�½���������
        pNew->next = NULL;//�½��Ϊβ��㣬�����ΪNULL
        if(*pHead==NULL)//������
        {
            *pHead =pNew;//�½��Ϊ��һ�����
            pEnd = pNew;

        }else{
            pEnd->next=pNew;//�½�����������ĩβ
            pEnd=pNew;//�½���Ϊβ���
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
ʱ�临�Ӷȣ�O(n)
�ռ临�Ӷȣ�O(1)
*/
