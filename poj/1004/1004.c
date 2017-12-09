#include<stdio.h>

int main()
{
    double num=0.0;
    double n=0.0;
    int k=12;
    while(k--)
    {
        scanf("%lf",&n);
        num+=n;
    }
    printf("$%.2lf",num/12.0);
    return 0;
}
