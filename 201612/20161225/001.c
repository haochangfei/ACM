/*
��������ͷ����ѭ��������ha��hb��
���һ���㷨��������β�ϲ���һ����ͷ���ĵ�����hc��
Ҫ���ٿ����µĿռ䡣��дһ��Ч�㷨��������ʱ�����ܺͿռ����ܡ�
*/
#include<stdio.h>
#include<stdlib.h>

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkList;

LinkList InitList();//��ʼ������
void  CreateLinkListTail(LinkList *pHead,int k,int n);//����������һ��ֵΪk�����μ�1������n�����
void PrintfL(LinkList pHead);//�������

int main()
{
    LinkList p,ha,hb,hc;

    ha=InitList();
    hb=InitList();

    CreateLinkListTail(&ha,1,4);
    CreateLinkListTail(&hb,5,3);

    PrintfL(ha);
    PrintfL(hb);

    /* *****************************��������ѭ������**************************************** */
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
    pEnd->next=*pHead;//��λ����������ѭ������
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
//�㷨������ʱ�临�Ӷ�O(n)���ռ临�Ӷȣ�O(1)��
