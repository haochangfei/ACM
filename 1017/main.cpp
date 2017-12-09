#include<stdio.h>

int pairs(int n,int m)
{
    int num = 0;
    for(int i=1;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((i*i+j*j+m)%(i*j) == 0)
                num++;
        }
    }
    return num;
}

int main()
{
    int T;
    int n,m;
    int num=1;
    scanf("%d",&T);
    while(T--)
    {
        num=1;
        while(scanf("%d%d",&n,&m)!=EOF)
        {
            if(n==m && n==0)
            {
                break;
            }
            else
            {
               printf("Case %d: %d\n",num++,pairs(n,m));
            }
        }
        if(T!=0)
            printf("\n");
    }
    return 0;
}
