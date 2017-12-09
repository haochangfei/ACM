#include<stdlib.h>
#include<stdio.h>
/*
*�Ƚ�����һ��β��ָ����һ������Ȼ���ж��������Ƿ���ڻ������ڻ�������������ָ�룬һ��λ��Ϊ2��һ��λ��Ϊ1������������ڻ��������ڻ����ཻ
*�ཻ��ֱ��������ȣ��������ֵȻ��������������������Ϊ��ֵ������������ָ����ָ��ı��ǵ�һ������
*/
typedef struct linknode
{
    int data;
    struct linknode *next;
}LinkNode;
//��ʼ������
LinkNode * initLink(LinkNode *L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    if(!L)return NULL;
    L->next = NULL;
    return L;
}
//ͷ�巨
LinkNode * insertHeadLink(LinkNode *L,int data)
{
    LinkNode *swap = (LinkNode *)malloc(sizeof(LinkNode));
    if(!swap)return NULL;
    swap->data = data;
    swap->next = L->next;
    L->next = swap;
    return L;
}
//����������
int getLength(LinkNode *L)
{
    int length = 0;
    LinkNode *swap = NULL;
    if(!L)return length;
    swap = L->next;
    while(swap)
    {
        length++;
        swap = swap->next;
    }
    return length;
}
//������������
void linkTable(LinkNode *L1,LinkNode *L2)
{
    LinkNode *swap = NULL;
    if(!L1||!L2)return;
    swap = L1;
    while(swap->next)
        swap = swap->next;
    swap->next = L2->next;
    return ;
}
//�ж������Ƿ��л�
int isExistRing(LinkNode *L)
{
    LinkNode *quick,*low;
    if(!L)return 2;
    quick = L->next;
    low = L;
    while(low)
    {
        if(!quick)return 0;
        if(low==quick)return 1;
        low = low->next;
        quick = quick->next;
        if(low==quick)return 1;
        quick = quick->next;
    }
    return 0;
}
main()
{
    LinkNode *L1 = NULL,*L2 = NULL;
    LinkNode *swap = NULL;
    LinkNode *ln1 = NULL,*ln2 = NULL;
    int length1 , length2;
    int dif = 0;
    int i = 0;
    L1 = initLink(L1);
    L2 = initLink(L2);
    for(i = 0;i<12;i++)
    {
        if(i<4)
            L1 = insertHeadLink(L1,i);
        else
            L2 = insertHeadLink(L2,i);
    }
    //ʹ�����ཻ
    swap = L1;
    while(swap->next)swap = swap->next;
    swap->next = L2->next->next->next;
    //��ȡ����������
    length1 = getLength(L1);
    length2 = getLength(L2);
    if(length1>length2)dif = length1-length2;
    else dif = length2-length1;
    //���컷
    linkTable(L1,L2);
    if(!isExistRing(L1))
    {
        printf("���������ཻ\n");
        return ;
    }
    ln1 = L1->next;
    ln2 = L2->next;
    i = 0;
    if(length1>length2)
    {
        while(i<dif)
        {
            ln1 = ln1->next;
            i++;
        }
        while(ln1!=ln2)
        {
            ln1 = ln1->next;
            ln2 = ln2->next;
        }
    }
    else
    {
        while(i<dif)
        {
            ln2 = ln2->next;
            i++;
        }
        while(ln1!=ln2)
        {
            ln1 = ln1->next;
            ln2 = ln2->next;
        }
    }
    printf("�����ڵ��������ֵ:%d\n",l1->data);
}
//ʱ�临�Ӷ�
//O(n+m)
//�ռ临�Ӷ�
//O(1)
