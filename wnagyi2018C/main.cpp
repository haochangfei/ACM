/*
һ����Сд��ĸ��ɵ��ַ������Կ���һЩͬһ��ĸ�������Ƭ��ɵġ�
����,"aaabbaaac"����������Ƭ��ɵ�:'aaa','bb','c'��
ţţ���ڸ���һ���ַ���,���������������ַ�����������Ƭ��ƽ�������Ƕ��١�
�������һ���ַ���s,�ַ���s�ĳ���length(1 �� length �� 50),sֻ��Сд��ĸ('a'-'z')
���һ������,��ʾ������Ƭ��ƽ������,�������뱣����λС����
��������ʾ: s = "aaabbaaac"
������Ƭ��ƽ������ = (3 + 2 + 3 + 1) / 4 = 2.25
aaabbaaac  2.25
*/
#include<stdio.h>
#include<string.h>
#define maxn 55
char ch[maxn];
int main()
{
    int type=1;
    int len=0;
    double n=0;
    gets(ch);
    len=strlen(ch);
    for(int i=1;i<len;i++)
    {
        if(ch[i]!=ch[i-1])
            type++;
    }
    n=(double)len/type;
    printf("%.2lf\n",n);
    return 0;
}
