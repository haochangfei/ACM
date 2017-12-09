#include<stdio.h>
#define M 10
int main()
{
    int k=0,i=0;
    double num=0.0,n=0.0;
    double d[M]={0.0};
    do
    {
        scanf("%lf",&d[k]);
    }
    while(d[k]!=0.0&&++k);
    for(i=0;i<k;i++)
    {
        num=0.0;n=1.0;
        while(num<d[i])
        {
            num=num+1/(n+1);
            n=n+1.0;
        }
        printf("%.lf card(s)\n",n-1);
    }
    return 0;
}
