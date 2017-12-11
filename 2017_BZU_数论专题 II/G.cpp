#include<bits/stdc++.h>
int main()
{
    int T,co=1,n,t;
    long long sum;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d",&n);
        int sq=sqrt(n);
        for(int i=1;i<=sq;i++)
        {
            sum+=n/i;
            sum+=(n/i-n/(i+1))*i;
        }
        if(sq==n/sq)
        {
            sum-=sq;
        }
        printf("Case %d: %lld\n",co++,sum);
    }
    return 0;
}
