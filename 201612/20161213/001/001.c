/*
1、题目描述：实现字符串的循环左移，即把字符串前面的若干个字符移动到字符串的尾部。如把字符串abcdef左移2位得到字符串cdefab。
题目要求：对长度为n的字符串操作的时间复杂度为O(n)，空间复杂度为O(1)。
要求描述所用算法，提交可执行的标准C代码，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include<string.h>
#define M 100
main()
{
    char a[M]="abcdef";
    int i=0;
    int len=strlen(a);
    a[len]=a[0];
    a[len+1]=a[1];
    for(i;i<len;i=i+2)
    {
        a[i]=a[i+2];
        a[i+1]=a[i+3];
    }
    a[len]='\0';
    printf("%s",a);
}
/*
算法分析：时间复杂度T(n)=O(n);空间复杂度S(n)=O(1);
*/
