/*
��֪���Ա��е�Ԫ����ֵ�����������У����Ե��������洢�ṹ����дһ��Ч���㷨��
ɾ����������ֵ����x��С��y��Ԫ�أ������д���������Ԫ�أ���ͬʱ�ͷű�ɾ���Ľ��ռ䣬
�������㷨��ʱ�临�ӶȺͿռ临�Ӷȣ�ע�⣺"x�� y�Ǹ����������α��������ǵ�ֵ���Ժͱ��е�Ԫ����ͬ��Ҳ���Բ�ͬ"
�����������£�
typedef  struct  LNode
{    int  data;
     struct  LNode  *next;
}LNode, *LinkList;

�㷨������ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O��1��
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
	LinkList p1 = NULL;//��¼��һ��Ҫɾ���Ľ���ǰһ��
	LinkList p2 = NULL;//��¼���һ��Ҫɾ���Ľ���һ��
	LinkList p = NULL;

	int x=3,y=8;//ɾ������3��С��8�Ľ��

	CreateLinkListTail(&head,10);//��ʼ������1 2 3 4 5 6 7 8 9 10
	PrintList(head);//�����ʼ��������

	p=head;
	while (p)
	{
		if (p->data<=x)//Ѱ�ҵ�һ��������x�Ľ����p1��¼
		{
			p1=p;
			p=p->next;
			
		}
		else if(p->data<=y)//Ѱ�ҵ�һ����С��y�Ľ����p2��¼
		{
			p2=p;
			p=p->next;
				
		}
		else
			p=p->next;
	}
	while (p1->next!=p2)//��p1����һ����ʼɾ�� ��p2����
	{
		p=p1->next;
		p1->next=p->next;
		free(p);
	}
	
	PrintList(head);//���ɾ����ĵ�����
}

/*β�巨����������*/
void  CreateLinkListTail(LinkList *pHead,int n)//pHead������ΪLinkList *��Ŀ����Ϊ�˴���������Ϣ���൱�����ô���
{
    LinkList pNew;//�����½���ָ��
    LinkList pEnd;//��������βָ��
	int i ;
    pEnd = *pHead;//��ʼʱ��βָ��Ϊ��
    for( i = 1; i<=n; i++)//ѭ������������
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
}
/*��������������е����н�㣬�������ʽΪ1->2->3->4->5��*/
void  PrintList(LinkList pHead)
{
    LinkList p;
    p = pHead;//������ʼ
    while(p->next)//��������һ��������
    {
        printf("%d->",p->data);//�����ʽ%d->
        p = p->next;//����ָ�����
    }
    printf("%d\n",p->data);//ѭ��������pָ�����һ����㣬�����ʽ%d
}

