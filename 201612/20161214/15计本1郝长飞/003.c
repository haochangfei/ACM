/*
3����Ŀ������ ɾ���ַ����е����֡����ַ�����abc123de4fg56��������Ϊ��abcdefg����
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define M 100
main()
{
    char ch[M]="abc123de4fg56";
    int i=0,len;
    int f=0,e=0;//f��ǵ�һ�����֣�e���f��ĵ�һ��������
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
�㷨������ʱ�临�Ӷ�T(n)=O(n^2);�ռ临�Ӷ�S(n)=O(1);
*/
