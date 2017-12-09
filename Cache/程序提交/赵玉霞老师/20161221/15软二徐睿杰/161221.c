#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
    int data;
    struct ListNode * next;

}ListNode, * LinkedList;
LinkedList head = NULL, pr = NULL;
void creat()
{
    int i, n, value;
    printf("please enter need node:\t");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("please enter integer:\t");
        scanf("%d", &value);
        add(value);
    }
}
void add(int value)
{
    LinkedList p = (LinkedList)malloc(sizeof(ListNode));
    if(!p) exit(0);
    p->data = value;
    if(head == NULL)
    {
        head = p;
        pr = p;
    }
    else
    {
        pr->next = p;
        pr = p;
    }
    pr->next = NULL;
}
void printList()
{
    LinkedList p = head;
    printf("[\t");
    while(p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("]\n");

}
LinkedList merge(LinkedList a, LinkedList b)
{
    LinkedList result = NULL;
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    if(a->data < b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else if(a->data > b->data)
    {
        result = b;
        result->next = merge(a, b->next);
    }
    else
    {
        result = a;
        result->next = merge(a->next, b->next);
    }
    return result;
}
int main()
{
    LinkedList head1 = NULL, head2 = NULL;
    creat();
    head1 = head;
    printList();
    head = head2;
    creat();
    head2 = head;
    printList();

    LinkedList a = head1;
    LinkedList b = head2;

    head = merge(a, b);

    printList();

    return 0;
}
