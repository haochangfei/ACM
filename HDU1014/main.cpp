#include<stdio.h>

int judge(int a,int b)
{
    if(b == 0)
    {
        return a;
    }
    return judge(b,a%b);

}

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(judge(a,b) == 1)
        {
            printf("%10d%10d    Good Choice\n\n",a,b);
        }
        else
            printf("%10d%10d    Bad Choice\n\n",a,b);
    }
    return 0;
}
