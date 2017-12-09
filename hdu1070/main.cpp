#include <cstdio>

using namespace std;

struct Milk
{
    char name[105];
    int p;
    int v;
}milk[105];

int main()
{
    int T,n;
    double m=0.0;
    int cn=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cn=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s%d%d",milk[i].name,milk[i].p,milk[i].v);
            cn=0;
            if(milk[i].v<200)
            {
                continue;
            }
        }
    }
    return 0;
}
