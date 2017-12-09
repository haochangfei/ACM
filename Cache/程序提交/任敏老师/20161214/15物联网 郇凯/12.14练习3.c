/*3、题目描述： 删除字符串中的数字。如字符串”abc123de4fg56”处理后变为”abcdefg”。
题目要求：描述所用算法，提交可执行的标准C代码，要求时间复杂度为O(n)、空间复杂度为O(1)。*/
#include<stdio.h>
#include<string.h>
main()
{
    char a[100],b[100];
    printf("Please import original string:\n");
    gets(a);
    int i,t=0;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]<'0' || a[i]>'9')
            b[t++]=a[i];
    }
    b[t]='\0';
    printf("After change string is:\n");
    puts(b);
}
