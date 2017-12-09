#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    double s,p;
    double num,sum;
    double gpa;
    while(scanf("%d",&T)!=EOF)
    {
        num=0;
        sum=0;
        while(T--)
        {
            scanf("%lf%lf",&s,&p);
            if(p==-1)
                continue;
            else
            {
                num+=s;
                if(p>=90)
                {
                    sum+=4*s;
                }
                else if(p>=80)
                {
                    sum+=3*s;
                }
                else if(p>=70)
                {
                    sum+=2*s;
                }
                else if(p>=60)
                {
                    sum+=1*s;
                }
            }
        }
        if(sum==0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%.2lf\n",sum/num);
        }
    }
    return 0;
}
