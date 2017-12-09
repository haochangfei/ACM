#include <iostream>
#include <cstdio>

using namespace std;

int isleapyear(int y)
{
    if(y%4==0 && y%100!=0 ||y%400==0)
        return 1;
    return 0;
}

int main()
{
    int T;
    int y,n;
    int cn;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&y,&n);
        if(isleapyear(y))
        {
           cn=1;
        }
        else
            cn=0;
        while(cn<n)
        {
            y++;
            if(isleapyear(y))
                cn++;
        }
        printf("%d\n",y);
    }
    return 0;
}
