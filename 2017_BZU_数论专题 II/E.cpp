#include <bits/stdc++.h>
#define ll long long
ll f(ll a,ll b,int mod)//mod=1000 得到最后三位数
{
    ll ans=1;
    a=a%mod;
    while(b)
    {
        if(b&1==1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

double fn(double n)
{
    while(n>=1000.0)
    {
        n/=10.0;
    }
    return n;
}

double ff(double a,ll b)//取前四位数 求前三位数
{
    double ans=1.0;
    a=a*1.0;
    while(b)
    {
        if(b%2)
        {
            ans = ans * a;
            ans=fn(ans);
        }
        a=a*a;
        a=fn(a);
        b=b/2;
    }
    return ans;

}

int main()
{
    int T;
    int co=1;
    ll n,k;
    int fs=0;
    int ls=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&k);
        ls=f(n,k,1000);
        fs=ff(n,k);
        printf("Case %d: %03d %03d\n",co++,(int)fs,ls);
    }
    return 0;
}
