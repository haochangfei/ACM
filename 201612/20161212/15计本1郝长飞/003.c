/*
3����������˳��ʹ����λ��ż��ǰ�档
��Ŀ����������һ���������飬�������������ֵ�˳��ʹ��������������������ż����ǰ�档Ҫ��ʱ�临�Ӷ�ΪO(n)��
*/
#include<stdio.h>
#include<string.h>
#define M 100
main()
{
    int a[M],i=0,len=0;
    int min,max,t;
    do
    {
        scanf("%d",&a[i++]);
    }
    while(getchar()!='\n');
    len=i;
    min=0;max=len-1;
    while(min<max)
    {
        if(a[min]%2==0&&a[max]%2==1)
        {
            t=a[min];
            a[min]=a[max];
            a[max]=t;
            min++;
            max--;
        }
        if(a[min]%2==1)
            min++;
        if(a[max]%2==0)
            max--;
    }
    for(i=0;i<len;i++)
        printf("%d ",a[i]);
}
/*
�㷨������ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1);
*/
