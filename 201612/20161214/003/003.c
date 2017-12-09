/*
3、题目描述： 删除字符串中的数字。如字符串”abc123de4fg56”处理后变为”abcdefg”。
题目要求：描述所用算法，提交可执行的标准C代码，要求时间复杂度为O(n)、空间复杂度为O(1)。
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define M 100
main()
{
    char ch[M]="abc123de4fg56";
    int i=0,len;
    int f=0,e=0;//f标记第一个数字，e标记f后的第一个非数字
    len=strlen(ch);
    char temp;
    while(i<len)
    {
        if(isdigit(ch[i]))
        {
            e=f=i;
            while(isdigit(ch[e]))
            {
                e++;
            }
            ch[f]=ch[e];
            ch[e]='1';
            i--;
        }
        i++;
    }
    printf("%s",ch);
}
/*
算法分析：时间复杂度T(n)=O(n^2);空间复杂度S(n)=O(1);
*/
