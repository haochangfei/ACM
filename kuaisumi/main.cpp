#include <cstdio>

using namespace std;

int pow(int a,int b)//快速幂
{
    int ans=1;
    while(b!=0)
    {
        if(b&1!=0)
            ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

int powmod(int a,int b,int mod)//快速幂取模
{
    int ans=1;
    a=a%mod;
    while(b!=0)
    {
        if(b&1!=0)
            ans=a*ans%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

int main()
{
    int a,b;
    while(1)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",pow(a,b));
    }
    return 0;
}
