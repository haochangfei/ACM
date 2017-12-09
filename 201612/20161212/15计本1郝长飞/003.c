/*
3、调整数组顺序使奇数位于偶数前面。
题目描述：输入一个整数数组，调整数组中数字的顺序，使得所有奇数均排在所有偶数的前面。要求时间复杂度为O(n)。
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
算法分析：时间复杂度O(n),空间复杂度O(1);
*/
