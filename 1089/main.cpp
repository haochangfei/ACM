#include <iostream>
#include <cstdio>
using namespace std;  //1094

int main()
{
    int T;
    int n;
    int a,sum;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum);
        if(T)
            printf("\n");
    }
    return 0;
}
