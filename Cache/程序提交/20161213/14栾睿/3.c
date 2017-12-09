/*
   3���滻URL�����еĿո�
    ��Ŀ�������������У����URL�����к��пո�������ַ���
    ���ܵ��·������޷������ȷ����ֵ����Ҫ���������ת���ɡ�%�������
    ��λʮ�����Ƶı�ʾ������ո��滻Ϊ��%20�����뽫������ַ����е�
    ���пո��滻Ϊ��%20����

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
//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(1)
