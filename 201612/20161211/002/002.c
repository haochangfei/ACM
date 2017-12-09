/*
2、题目描述：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
题目要求：使用尽可能高效的算法，并分析程序的时间、空间复杂度
*/
#include<stdio.h>
#define N 10
main()
{
    int a[N]={1,1,2,2,3,3,4,4,5,6};
    int i=0,j,k;
    for(i=0;i<N;i++)//分别读取数组的数字
    {
        k=0;
        for(j=0;j<N;j++)//寻找数组内是否有除其本身外与其相同的数字
        {
            if(i!=j&&a[i]==a[j])//如果有 就将k改变
                k=1;
        }
         if(k==0)//如果k未变则说明没有找到！
                printf("%d\t",a[i]);
    }
}
/*
算法分析：
          时间复杂度：T(n)=O(n^2);
          空间复杂度：S(n)=O(1);
*/

/*
void FindTwoNotRepeatNumberInArray(int *a, int n, int *pN1, int *pN2)
{
    int i, j, temp;

    //计算这两个数的异或结果
    temp = 0;
    for (i = 0; i < n; i++)
        temp ^= a[i];

    // 找第一个为1的位
    for (j = 0; j < sizeof(int) * 8; j++)
        if (((temp >> j) & 1) == 1)
            break;

    // 第j位为1,说明这两个数字在第j位上是不相同的
    // 由此分组即可
    *pN1 = 0, *pN2 = 0;
    for (i = 0; i < n; i++)
        if (((a[i] >> j) & 1) == 0)
            *pN1 ^= a[i];
        else
            *pN2 ^= a[i];
}
void PrintfArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
}
int main()
{
    printf("    白话经典算法系列之十二数组中不重复的个数字(百度面试题) \n");
    printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

    const int MAXN = 10;
    //int a[MAXN] = {1, 2, 7, 5, 100,  100, 6, 1, 2, 5};
    int a[MAXN] = {1, 2, 3, 4, 1,  2, 3, 4, 0, 5};

    printf("数组为: \n");
    PrintfArray(a, MAXN);

    int nNotRepeatNumber1, nNotRepeatNumber2;
    FindTwoNotRepeatNumberInArray(a, MAXN, &nNotRepeatNumber1, &nNotRepeatNumber2);
    printf("两个不重复的数字分别为: %d %d\n", nNotRepeatNumber1, nNotRepeatNumber2);
    return 0;
}
*/
