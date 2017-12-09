#include <iostream>
#include <cstdio>
#define m 9973
using namespace std;

int f(int n,int b)
{
    for(int i=0;i<9973;i++)
    {
        if((n%m-(b%m)*i)%m==0){
            return i;
        }
    }

}

int main()
{
    int t;
    int n,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&b);
        printf("%d\n",f(n,b));
    }
    return 0;
}
