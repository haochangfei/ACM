/*2����תһ��Ӣ�ľ����е��ʵ�˳��

��Ŀ������ ����һ��Ӣ�ľ��ӣ������е����Կո����������ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣���б�����ĸ��ͬ������
�磺���� I am a student.��� student. a am I 
��ĿҪ��:?���������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�*/
#include <stdio.h>

#define N 400
#define Q 10

void main()
{
	//�������
	int i,j,t=0,q=0;
	char s[N]; 
	char s1[N];
	int n,p;
	j=i+1;

	//��ȡ����
	printf("������һ��Ӣ�ľ��ӣ�\n");
	gets(s);

	//��ȡs�ĳ���
	p = n = strlen(s);
	//printf("%d\n",n);

	for(i = n; i > 0; i--)
	{
		if(s[i] == ' ')
		{

			for(j = i+1; j < p; j++)
			{
				printf("%c",s[j]);
			}
			printf(" ");
			p=i;
		}
	}	
	while(s[q]!= ' ')
	{
		printf("%c",s[t++]);
		q++;
	}
	
	printf("\n");


}