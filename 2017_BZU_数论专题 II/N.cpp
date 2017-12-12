#include <bits/stdc++.h>
#define NN 1000000000


long long f(long long n)
{
    long long ans=0;
    while(n)
    {
        ans+=n/5;
        n/=5;
    }
    return ans;
}

int main()
{
    int T,co=1;
    long long n,minn,mid,maxn,ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        minn=1;
        maxn=NN;
        while(maxn>=minn)
        {
            mid=(maxn+minn)/2;
            if(f(mid)>=n)
            {
                ans=mid;
                maxn=mid-1;
            }
            else
            {
                minn=mid+1;
            }
        }
        if(f(ans)==n)
        {
            printf("Case %d: %lld\n",co++,ans);
        }
        else
        {
            printf("Case %d: impossible\n",co++);
        }
    }
    return 0;
}
