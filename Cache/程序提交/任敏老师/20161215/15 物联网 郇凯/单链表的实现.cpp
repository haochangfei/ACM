#include "stdio.h"
#include "stdlib.h"
#include "单链表.h"

int main()
{
	Linklist head1,head2,p1,p2,p3;
	initlist(head1);
	initlist(head2);					//初始单链表1，2 
	int n1,n2;							//n1 表1 n2 表2
	Elemtype x1,x2,flag=0;
	n1=listlength(head1);
	n2=listlength(head2);
	printf("请输入链表1的元素以-1结束：\n");
	scanf("%d",&x1);
	while(x1!=-1)
	 {
		listinsert(head1,n1+1,x1);
		n1++;
	 scanf("%d",&x1);
	}   
	printf("请输入链表2的元素以-1结束：\n");
	scanf("%d",&x2);
	while(x2!=-1)
	 {
		listinsert(head2,n2+1,x2);
		n2++;
	 scanf("%d",&x2);
	}   
//	printf("新建的单链表1为：\n");
//	printlist(head1);
//	printf("新建的单链表2为：\n");
//	printlist(head2);
	p1=head1->next;
	p2=head2->next;
	while(p1)
	{
		p3=p2;
		while(p3)
		{
			if(p1->data==p3->data)
				flag=1;
			if(flag==1)
				break;
			p3=p3->next;
		}
		if(flag==1)
		{
			printf("第一个公共结点是%d",p1->data);
			break;
		}
		p1=p1->next;
	}
return 0;
}
