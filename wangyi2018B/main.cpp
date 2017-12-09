

/*为了得到一个数的"相反数",我们将这个数的数字顺序颠倒,然后再加上原先的数得到"相反数"。

例如,为了得到1325的"相反数",首先我们将该数的数字顺序颠倒,我们得到5231,之后再加上原先的数,

我们得到5231+1325=6556.如果颠倒之后的数字有前缀零,前缀零将会被忽略。

例如n = 100, 颠倒之后是1

输入包括一个整数n,(1 ≤ n ≤ 10^5)

输出一个整数,表示n的相反数*/
/*
1325
100000
6556
*/
#include<stdio.h>
int f(int n)
{
    int sum=1;
    while(n--)
    {
        sum*=10;
    }
    return sum;
}

int main()
{
    int num[10]={0};
    int len,i=0;
    long long n,temp;
    scanf("%lld",&n);
    //printf("%lld\n",n);
    temp = n;
    while(temp)
    {
        num[i] = temp%10;
        temp=temp/10;
        i++;
       // printf("%d",num[i-1]);
    }
    len = i-1;
    temp=n;
    for(int j=len;j>=0;j--)
    {
        temp += num[j]*f(len-j);
        //printf("%d\n",num[j]*f(len-j));
    }
    printf("%lld",temp);
    return 0;
}
