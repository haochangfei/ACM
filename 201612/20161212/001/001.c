/*
1、题目描述：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。
题目要求：使用尽可能高效的算法，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include<string.h>
#define M 100
main()
{
    char ch[M],*y;
    int i=0,len;
    scanf("%s",ch);
    len=strlen(ch);
    while(i<len)
    {
        if(strchr(ch,ch[i])==strrchr(ch,ch[i]))//比较该字符第一次出现的地址与第二次是否一致
        {
            printf("%c\n",ch[i]);
            break;
        }
        i++;
    }
}
/*
    算法分析：时间复杂度：T(n)=O(n);
              空间复杂度：S(n)=O(1)；
*/
