#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x=0,m,n,i,s=0,a,c;
    while(scanf("%d%d",&m,&n)==2&&m>99&&n>99)
    {
       for(i=m;i<=n;i++)
       {
           c=i;
           while(c>0)
           {
               a=c%10;
               s=s+a*a*a;
               c=c/10;
           }
           if(i==s)
           {
               x=1;
               printf("%-4d",i);
           }
           s=0;
       }
       if(x==0) printf("no");
       printf("\n");
    }

}
