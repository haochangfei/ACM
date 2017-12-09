/*2、翻转一个英文句子中单词的顺序。

题目描述： 输入一个英文句子，句子中单词以空格符隔开。翻转句子中单词的顺序，但单词内字符的顺序不变。其中标点和字母做同样处理。
如：输入 I am a student.输出 student. a am I 
题目要求:?描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。*/
#include <stdio.h>

#define N 400
#define Q 10

void main()
{
	//定义变量
	int i,j,t=0,q=0;
	char s[N]; 
	char s1[N];
	int n,p;
	j=i+1;

	//获取句子
	printf("请输入一个英文句子：\n");
	gets(s);

	//获取s的长度
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