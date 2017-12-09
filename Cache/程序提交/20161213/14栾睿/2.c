/*
   2、翻转一个英文句子中单词的顺序。
    题目描述： 输入一个英文句子，句子中单词以空格符隔开。
    翻转句子中单词的顺序，但单词内字符的顺序不变。其中标点和字母做同样处理。
    如：输入 I am a student.    输出 student.  a  am  I

*/

#include<stdio.h>

void partReverse(char *start,char *end)
{
    char temp;
    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start ++;
        end--;
    }
}

char * allReverse(char *sen)
{
    char *start = sen,*end = sen + strlen(sen)-1;
    partReverse(start,end);//先反转整个句子

    int loc ;
    for(start = sen,end = start;(*end) != '\0';start += loc)
    {
        loc = 0;
        while((*end) != ' ' && (*end)!='\0')
        {
            end ++;
            loc++;
        }
        end --;
        partReverse(start,end);
        end += 2;
        loc ++;
    }

    end = start;
    while(*start!='\0')
    {
        if(*end == ' ' || *end == '\0')
        {
            partReverse(start,--end);
            if(*end == '\0')
                break;
            end += 2;
            *start += end;
        }
        else
            ++end;
    }
    return sen;
}

int main()
{
    char sen[] = "I am a student. ";
    char *result = allReverse(sen) ;
    printf("%s",result);
    return 0;
}
//时间复杂度：O(n)
//空间复杂度：O(1)
