/*3����Ŀ������ ɾ���ַ����е����֡����ַ�����abc123de4fg56��������Ϊ��abcdefg����
��ĿҪ�����������㷨���ύ��ִ�еı�׼C���룬Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��*/
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
