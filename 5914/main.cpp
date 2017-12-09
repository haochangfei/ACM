#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a[22];
    int n,t,co,ca=1;
    memset(a,0,sizeof(a));
    a[1]=1;
    a[2]=1;
    a[3]=1;
    a[5]=1;
    a[8]=1;
    a[13]=1;
    a[21]=1;
    scanf("%d",&t);
    while(t--)
    {
        co=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
                co++;
        }
        printf("Case #%d: %d\n",ca++,co);
    }
    return 0;
}
