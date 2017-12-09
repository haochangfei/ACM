#include <cstdio>
#include<cstring>
using namespace std;

int main()
{
    int T,n;
    char ch[105],last[105];
    int p,v;
    double v1=1,ans=99999,temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s%d%d",ch,&p,&v);
            if(v<200) continue;
            if(v/200>=5) temp = p/5.0;
            else temp = p*1.0/(v/200);
            if(temp<ans)
            {
                ans=temp;
                v1=v;
                memset(last,0,sizeof(last));
                strcpy(last,ch);
            }
            else if(temp==ans)
            {
                if(v>v1)
                {
                   memset(last,0,sizeof(last));
                    strcpy(last,ch);
                }
            }
        }
        puts(last);
    }
    return 0;
}
