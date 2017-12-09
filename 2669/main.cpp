#include <iostream>
#include <cstdio>


//用扩展欧几里德算法，紫书313
using namespace std;

void gcd(int a,int b,int& d,int& x,int &y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}

int main()
{
    int a,b;
    int d,x,y;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        gcd(a,b,d,x,y);
        if(d==1)
        {
            while(x<0)
            {
                x+=b;
                y-=a;
            }
            printf("%d %d\n",x,y);
        }
        else
        {
            printf("sorry\n");
        }
    }
    return 0;
}
