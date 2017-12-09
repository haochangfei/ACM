/*
3、替换URL参数中的空格。
题目描述：网络编程中，如果URL参数中含有空格等特殊字符，可能导致服务器无法获得正确参数值。
需要将特殊符号转换成’%’后跟上两位十六进制的表示，比如空格被替换为’%20’，请将输入的字符串中的所有空格替换为’%20’。
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include<string.h>
#define M 100
main()
{
    int i=0,len,j=0;
    char a[M];
    char ch[M]="I am a students.";
    len=strlen(ch);
    for(i;i<len;i++)
    {
        if(ch[i]!=' ')
        {
            a[j++]=ch[i];
        }
        else
        {
            a[j++]='%';
            a[j++]='2';
            a[j++]='0';
        }
    }
    printf("%s",a);
}
/*
算法分析：时间复杂度T(n)=O(n);空间复杂度S(n)=O(n);
*/
