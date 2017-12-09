#include<stdio.h>

#define maxn 10000+10

long long gcd(long long a,long long b)//最大公约数
{
    long long temp=a;
    while(b)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
long long gcm (long long a,long long b)//最小公倍数
{
    return (a*b)/gcd(a,b);
}

int main()
{
    int T;
    int n;
    long long num1,num2,num3;
    long long ans=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            scanf("%lld",&num1);
            ans = num1;
        }
        else if(n==2)
        {
            scanf("%lld%lld",&num1,&num2);
            ans = gcm(num1,num2);
        }
        else
        {
            n=n-2;
            scanf("%lld%lld",&num1,&num2);
            ans=gcm(num1,num2);
            while(n--)
            {
                scanf("%lld",&num3);
                ans = gcm(num3,ans);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
