#include<stdio.h>
#define N 10
#define Pi 3.141592
int main()
{
    double a[N],b[N];
    int souse[N];
    int cot=0;
    int i=0;
    scanf("%d",&cot);
    for(i;i<cot;i++)
    {
        scanf("%lf%lf",&a[i],&b[i]);
    }
    for(i=0;i<cot;i++)
    {
        souse[i]=(a[i]*a[i]+b[i]*b[i])*Pi/100.0+1.0;
        printf("Property %d: This property will begin eroding in year %d.\n",i+1,souse[i]);
    }
    printf("END OF OUTPUT.");
    return 0;
}
