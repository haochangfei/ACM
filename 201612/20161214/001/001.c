/*
1����Ŀ���������������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
���磬���롱They are students.���͡�aeiou������ɾ��֮����ַ�����ɡ�Thy r stdnts.����
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬�����������ʱ�䡢�ռ临�Ӷȡ�
*/
#include<stdio.h>
#include<string.h>
#define M 100
main()
{
    int i=0,j=0,len;
    char ch[M]="They are students.";
    char dch[M]="aeiou";
    char ech[M];
    len=strlen(ch);
    while(i<len)//���α����ַ�����
    {
        if(ch[i]==' ')//����ǿո�ֱ�Ӹ�ֵ
            ech[j]=ch[i];
        if((strchr(dch,ch[i]))==NULL)//������ǵڶ����ַ�����һ���֣�ֱ�Ӹ�ֵ
            ech[j++]=ch[i];
            i++;
            ech[j]=ch[len+1];//�ֶ���ӽ�����
    }
    printf("%s",ech);
}
/*
�㷨������ʱ�临�Ӷ�T(n)=O(n);�ռ临�Ӷ�S(n)=O(n);
*/
