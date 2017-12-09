/*
2，翻转一个英文句子中单词的顺序。
题目描述： 输入一个英文句子，句子中单词以空格符隔开。翻转句子中单词的顺序，但单词内字符的顺序不变。其中标点和字母做同样处理。
如：输入 I am a student.    输出 student.  a  am  I
题目要求: 描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include<string.h>
#define M 100
main()
{
    char *a[M];
    int i=0,j=0,len;
    char *ch="I am a students.";
    char *p=ch;
    //printf("%s",p);
    //printf("%c",ch[5]);
    i=len=strlen(ch);
    //printf("%d",i);
    while(i-->0)
    {
        //printf("%c\n",ch[i]);
        if(ch[i]==' ')
        {
            printf("%s",p+i+1);
        }
    }
    printf("%s",p);
}
/*
题目未达成要求 ！修改中。。。。。
算法分析：时间复杂度T(n)=O();空间复杂度S(n)=O();
*/
