/*
20161223��Ŀ
���Ϊ1��2��3��4...��n��n���˰�˳ʱ�뷽��Χ��һ��ԲȦ����Ϸ���ӱ��Ϊ1���˿�ʼ˳ʱ����1��ʼ˳������ÿ�α���mֹͣ������Ȼ��m���˴����ԲȦ����С�������������˳ʱ�뷽���ϵ���һ���˿�ʼ���´�1�����������ȥ��������ԲȦ��ʣ�µ����һ���˵ı�š�
���磺n=10  ��m=2
��������Ϊ��2   4   6  8  10  3  7  1  9  5
���һ���˱��Ϊ5
���磺n=20 ��m=5
��������Ϊ��5   10   15   20   6   12   18  4   13  1   9   19  11   3   17   16   2   8   14   7
���һ���˱��Ϊ7
��ĿҪ�󣺾���ʹ�ø�Ч�㷨�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�
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
    CreateLinkListTail(&head,n);//��ʼ��������Ϊ0,1,2,3,4,5,6��n-1
	PrintDeteList(&head,m);//�����ɾ����m�����
	printf("\n20 5\n");
    n=20;
    m=5;
    CreateLinkListTail(&head,n);//��ʼ��������Ϊ0,1,2,3,4,5,6��n-1
	PrintDeteList(&head,m);//�����ɾ����m�����
}
/*β�巨����������*/
void  CreateLinkListTail(LinkList *pHead,int n)//pHead������ΪLinkList *��Ŀ����Ϊ�˴���������Ϣ���൱�����ô���
{
    LinkList pNew;//�����½���ָ��
    LinkList pEnd;//��������βָ��
	int i ;
    pEnd = *pHead;//��ʼʱ��βָ��Ϊ��
    for( i = 0; i<n; i++)//ѭ������������
    {
        pNew= (LinkList)malloc(sizeof(LNode));//��̬�����½��
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
    pEnd->next=*pHead;
}
void  PrintDeteList(LinkList *pHead,int k)//�����ɾ��ÿһ�ε�k�����
{
    int t=k;
    LinkList p;
    LinkList q;
    p = *pHead;//������ʼ
    while(p->next!=p)//ֻʣһ����ʱ���˳�ѭ��
    {
        t=k-1;
        while(t--)//Ѱ�ҵ�k������ǰһ�����
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        printf("%d ",q->data);//ɾ���������t�����
        free(q);
    }
    printf("%d ",p->data);//������һ�����
}
/*
�㷨������ʱ�临�Ӷ�T(n)=O();�ռ临�Ӷ�S(n)=O(1);
*/
