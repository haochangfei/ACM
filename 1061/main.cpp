#include <cstdio>

using namespace std;


int pow(int a,int b)
{
    int ans=1;
    a%=10;
    while(b!=0)
    {
        if(b&1!=0)
            ans=ans*a%10;
        a=a*a%10;
        b>>=1;
    }
    return ans;
}

int main()
{
    int num;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&num);
        printf("%d\n",pow(num,num));
    }
    return 0;
}
