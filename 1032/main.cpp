#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int f(int n)
{
    int len=1;
    while(n!=1)
    {
        len++;
        if(n%2!=0)
            n=3*n+1;
        else
            n=n/2;
    }
    return len;
}

int main()
{
    int a,b;
    int maxn=0,temp;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d %d",a,b);
        maxn=0;
        if(a>b)
            swap(a,b);
        for(int i=a;i<=b;i++)
        {
            temp = f(i);
            if(maxn<temp)
                maxn=temp;
        }
        printf(" %d\n",maxn);

    }
    return 0;
}
