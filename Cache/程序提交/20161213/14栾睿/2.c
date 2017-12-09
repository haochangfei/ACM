/*
   2����תһ��Ӣ�ľ����е��ʵ�˳��
    ��Ŀ������ ����һ��Ӣ�ľ��ӣ������е����Կո��������
    ��ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣���б�����ĸ��ͬ������
    �磺���� I am a student.    ��� student.  a  am  I

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
    partReverse(start,end);//�ȷ�ת��������

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
//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(1)
