#include"Fifteen.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
#pragma region 12.15
	ListNode *listNode1 = NewNode(0), *listNode2 = NewNode(0);
	NewTitle(listNode1, listNode2);
	printf("%d", FindSimeNode(listNode1, listNode2)->data);
#pragma endregion



	char stop;
	scanf_s("%c", &stop, sizeof(char));
	return 0;
}
