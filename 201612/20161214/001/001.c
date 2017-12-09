/*
1、题目描述：输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如，输入”They are students.”和”aeiou”，则删除之后的字符串变成”Thy r stdnts.”。
题目要求：描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include<string.h>
#define M 100
main()
{
    int i=0,j=0,len;
    char ch[M]="They are students.";
    char dch[M]="aeiou";
    char ech[M];
    len=strlen(ch);
    while(i<len)//依次遍历字符数组
    {
        if(ch[i]==' ')//如果是空格直接赋值
            ech[j]=ch[i];
        if((strchr(dch,ch[i]))==NULL)//如果不是第二个字符串的一部分，直接赋值
            ech[j++]=ch[i];
            i++;
            ech[j]=ch[len+1];//手动添加结束符
    }
    printf("%s",ech);
}
/*
算法分析：时间复杂度T(n)=O(n);空间复杂度S(n)=O(n);
*/
