#include <bits/stdc++.h>

int f(int a,int b,int mod)
{
    int ans=1;
    a=a%mod;
    while(b)
    {
        if(b&1==1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    //(sum*n^(k-1)*k)%mod
    int T;
    int n,k,mod,co=1;
    int a;
    long long sum=0;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d%d%d",&n,&k,&mod);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            sum=(sum+a%mod)%mod;
        }
        sum=(sum*f(n,k-1,mod)*k%mod)%mod;
        printf("Case %d: %lld\n",co++,sum);
    }
    return 0;
}