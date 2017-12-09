#include <cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int dp[maxn];
int main()
{
    int T,n,countn=0;
    int first,last,maxsum,start;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&dp[i]);
        }
        start = first = last = 0;
        maxsum=dp[0];
        // dp[i]=Max(dp[i-1]+dp[i] , dp[i])
        for(int i=1;i<n;i++)
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
                first = start;
                last = i;
            }
        }
        if(countn)
        {
            printf("\n");
        }
        printf("Case %d:\n",++countn);
        printf("%d %d %d\n",maxsum,first+1,last+1);


    }
    return 0;
}
