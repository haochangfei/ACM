/*
   3、替换URL参数中的空格。
    题目描述：网络编程中，如果URL参数中含有空格等特殊字符，
    可能导致服务器无法获得正确参数值。需要将特殊符号转换成’%’后跟上
    两位十六进制的表示，比如空格被替换为’%20’，请将输入的字符串中的
    所有空格替换为’%20’。

*/

#include<stdio.h>

void replaceBlank(char *s)
{
    char *p1 = s;
    char *p2 = s;
    while('\0' != *p1)
    {
        if(*p2 != ' ')
            *p1++ = *p2++;
        else
            p2++;
    }
}

void replaceSpace(char string[],int length)
{
    int blanknumber = 0;
    int i;
    for(i = 0;string[i] !='\0';i++)
    {
        if(string[i] == ' ')
        {
            blanknumber++;
        }
    }
    int k = i + 2 * blanknumber;
    if(k > length)
    {
        return ;
    }
    string[k] = '\0';
    int point1 = i-1,point2 = k-1;
    while(point1 >= 0 && point2 > point1)
    {
        if(string[point1] == ' ')
        {
            string[point2--] = '0';
            string[point2--] = '2';
            string[point2--] = '%';
        }
        else
            string[point2--] = string[point1];
        point1 --;
    }
}

int main()
{
    char b[50];
    char *string = b;
    while(gets(string))
    {
        replaceSpace(string,50);
        puts(string);
    }
    return 0;
}
//时间复杂度：O(n)
//空间复杂度：O(1)
