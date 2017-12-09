#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int T,n,nmax,num;
    long long sum;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        nmax=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            sum+=num;
            if(num>nmax)
                nmax=num;
        }
        sum-=nmax;
        if(nmax<=sum+1)
            printf("Yes\n");
        else
            printf("No\n");


    }
    return 0;
}
