/*
3、题目描述：求一个数组中的值最大元素和值最小的元素
题目要求：使用尽可能高效的算法，并分析程序的时间、空间复杂度
*/
#include<stdio.h>
main()
{
    int i;
    int a[]={1,2,3,4,5,6,7,8,9,0};
    int max,min;
    max=min=a[0];
    for(i=0;i<10;i++)
    {
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
    }
    printf("max=%d,min=%d\n",max,min);
}
