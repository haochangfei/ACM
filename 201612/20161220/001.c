/*
��Ŀ�������ж�һ�����������Ƿ��γ��˻�״�ṹ��
�������㶨�����£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�
*/
#include<stdio.h>
#include<stdlib.h>
#define M 5

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

void Initialization();
void printfL(LinkedList *L,int len);
void Judgmentring(LinkedList L);

LinkedList head;

main()
{
    Initialization();
    printfL(head,20);
    Judgmentring(head);
}

void Judgmentring(LinkedList L)//�жϵ������Ƿ��ǻ�
{
    LinkedList p;
    p=L->next;
    while(p->next!=L&&p->next!=NULL)//�����һ��ָ��ͷʱ�����һ��ָ���ʱ��������
    {
        p=p->next;
    }
    if(p->next==L)
        printf("��");
    else
        printf("���ǻ�");
}

void Initialization()//����������ֵ
{
    int i;
    LinkedList p,q;
    head=(LinkedList)malloc(sizeof(ListNode));
    head->data=1;
    head->next=NULL;
    q=head;
    for(i=1;i<M;i++)
    {
        p=(LinkedList)malloc(sizeof(ListNode));
        q->next=p;
        p->next=NULL;
        q=p;
        q->data=i+1;
    }
    p->next=head;//�γɻ���ע�͵��ɼ��鲻Ϊ��ʱ���н����
}

void printfL(LinkedList *L,int len)//������������Ϊ�����len����㣻
{                                  //�����Ϊ������len<�����ȣ����len����㣬���������β������
    int i=0;
    LinkedList p=L;
    for(i;i<len&&p!=NULL;i++)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
/*
�㷨������ʱ�临�Ӷ�T(n)=O();�ռ临�Ӷ�S(n)=O();
*/
