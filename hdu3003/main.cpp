#include <iostream>
#include <cstdio>
#define LL long long

using namespace std;

LL f(LL a,LL b,LL c)
{
    LL ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%c;
        b>>=1;
        a=a*a%c;
    }
    return (ans+1)%c;
}

int main()
{
    LL n;

    while(scanf("%lld",&n))
    {
        if(n==0)
            break;
        printf("%lld\n",f(2,n-1,n));
    }
    return 0;
}
