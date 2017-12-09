/*
��Ŀ�������������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý�㡣
�������뺯���Ķ������£�
typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;
void DeleteNode(LinkedList   *pListHead,  LinkedList  pToBeDeleted);
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�
*/
#include<stdio.h>
#define M 5

typedef  struct  ListNode
{    int  data;
     struct ListNode  *next;
}ListNode, *LinkedList;

void Initialization();
void printfL(LinkedList *L);
void DeleteNode(LinkedList   *pListHead,  LinkedList  pToBeDeleted);

LinkedList head;
LinkedList temp;//Ҫɾ����㣡

main()
{
    int i=0;
    LinkedList p;
    Initialization();
    printfL(head);
    DeleteNode(head,temp);
    p=head;
    for(i;i<M-1;i++)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
void Initialization()//����������ֵ,������tempָ��Ҫɾ�����
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
    p=head;
    for(i=0;i<2;i++)
    {
        p=p->next;
    }
    temp=p;
}
void printfL(LinkedList *L)
{
    int i=0;
    LinkedList p=L;
    for(i;i<M;i++)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}
void DeleteNode(LinkedList   *pListHead,  LinkedList  pToBeDeleted)
{
    LinkedList p;
    p=head;
    while(p->next!=pToBeDeleted)
    {
        p=p->next;
    }
    p->next=p->next->next;
    free(pToBeDeleted);
}
/*
�㷨������ʱ�临�Ӷ�T(n)=O(n);�ռ临�Ӷ�S(n)=O(1);
*/
