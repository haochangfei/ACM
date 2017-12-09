#include<stdio.h>
#include<math.h>

int num[21];

int pow(int n)
{
    int ans=2;
    for(int i=1;i<n;i++)
        ans*=2;
    return ans;
}

int main()
{
    int t=0;
    int n;
    num[1]=1;
    num[2]=3;
    for(int i=3;i<21;i++)
    {
        num[i]=num[i-1]*2 + pow(i-2);
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",num[n]);
    }
    return 0;
}
