/*
1����Ŀ��������һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��
��ĿҪ��ʹ�þ����ܸ�Ч���㷨�������������ʱ�䡢�ռ临�Ӷȡ�
*/
#include<stdio.h>
#include<string.h>
#define M 100
main()
{
    char ch[M],*y;
    int i=0,len;
    scanf("%s",ch);
    len=strlen(ch);
    while(i<len)
    {
        if(strchr(ch,ch[i])==strrchr(ch,ch[i]))//�Ƚϸ��ַ���һ�γ��ֵĵ�ַ��ڶ����Ƿ�һ��
        {
            printf("%c\n",ch[i]);
            break;
        }
        i++;
    }
}
/*
    �㷨������ʱ�临�Ӷȣ�T(n)=O(n);
              �ռ临�Ӷȣ�S(n)=O(1)��
*/
