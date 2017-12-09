#include <stdio.h>
#include<algorithm>
/////HDU 2010 Ë®ÏÉ»¨Êý

int f(int n)
{
    return n*n*n;
}

int main()
{
    int a,b;
    int m,n;
    int num;
    int k[999];
    int countn = 0;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        countn=0;
        m=a>b?b:a;
        n=a>b?a:b;
        for(int i=m;i<=n;i++)
        {
            //printf("%d,%d,%d,%d,%d\n",i,f(i/100),f(i/10%10),f(i%10),(f(i/100)+f(i/10%10)+f(i%10)));
            if((i)==(f(i/100)+f(i/10%10)+f(i%10)))
            {
                k[countn]=i;
                countn++;
            }
        }
        if(countn==0)
            printf("no");
        for(int i=0;i<countn;i++)
        {
            printf("%d",k[i]);
            if(i!=countn-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
