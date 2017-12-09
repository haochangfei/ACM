#include <cstdio>
#define maxn 10005

using namespace std;

int dp[maxn];
int a[maxn];

int main()
{
    int n;
    int maxsum,first,last,start;
    int temp;
    while(1)
    {
        scanf("%d",&n);
        temp=0;
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&dp[i]);
            a[i]=dp[i];
            if(dp[i]<0)
                temp++;
        }
        first = last = start =0;
        maxsum = dp[0];
        //dp[i] = MAX(dp[i - 1] + dp[i], dp[i]);
        for(int i=1; i<n; i++)
        {
            if(dp[i-1]>=0)
            {
                dp[i]=dp[i-1]+dp[i];
            }
            else
            {
                start = i;
            }
            if(dp[i]>maxsum)
            {
                maxsum=dp[i];
                first=start;
                last=i;
            }
        }
        if(temp==n)
        {
            maxsum=0;
            first=0;
            last=n-1;
        }
        printf("%d %d %d\n",maxsum,a[first],a[last]);
    }
    return 0;
}
