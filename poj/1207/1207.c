#include<stdio.h>
int Search_c(int a);
int Search_max(int a,int b);
int main()
{
    int i=0;
    int a,b,s;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        s = Search_max(a,b);
        printf("%d %d %d\n",a,b,s);
    }
    return 0;
}
int Search_c(int a)
{
    int n = 1;
    int t = a;
    while(t!=1)
    {
        if(t%2)
            t=3*t+1;
        else
            t/=2;
        n++;
    }
    return n;
}
int Search_max(int a,int b)
{
    int i=0;
    int max = 0;
    int t = 0;
    if(a<b)
    {
        for(i=a;i<=b;i++)
        {
            t=Search_c(i);
            if(max<t)
            {
                max=t;
            }
        }
    }
    else
    {
        for(i=b;i<=a;i++)
        {
            t=Search_c(i);
            if(max<t)
            {
                max=t;
            }
        }
    }

    return max;
}

