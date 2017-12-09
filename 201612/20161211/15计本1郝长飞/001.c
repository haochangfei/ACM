/*
1、题目描述：输入一个按元素值升序排列的数组和一个数字，在数组中查找两个元素，使得它们之和等于输入的那个数字。如果有多对数字之和等于那个数字，输出任意一对即可。
比如:输入 数组 2  5  7    10  13  20 和数字20
输出  7  13
题目要求：使用尽可能高效的算法，并分析程序的时间、空间复杂度
*/
#include<stdio.h>
#define N 6
int BiSearch(int data[],  int x, int beg, int last);
main()
{
    int i;
    int a[N];
    int num;
    int t1,t2;
    printf("数组");
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("数字");
    scanf("%d",&num);

    i=N;
    while(i>=0)
    {
        if(a[i]>num)
            i--;
        else
        {
            t1=num-a[i];
            i--;
            if((t2=BiSearch(a,t1,0,i))!=-1)
            {
                printf("%d\t%d",t1,a[i+1]);
                break;
            }
        }
    }
}
int BiSearch(int data[],  int x, int beg, int last)//折半查找
{
    int mid;
    if (beg > last)
    {
        return -1;
    }


    while(beg <= last)
    {
        mid = (beg + last) / 2;
        if (x == data[mid] )
        {
            return mid;
        }
        else if (data[mid] < x)
        {
            beg = mid + 1;
        }
        else if (data[mid] > x)
        {
            last = mid - 1;
        }
    }
    return -1;
}
/*
算法分析：时间复杂度T(n)=O(n(logn+1));
          空间复杂度：S(n)=O(1);
*/
