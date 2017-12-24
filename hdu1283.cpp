#include <bits/stdc++.h>
#define maxn 205
using namespace std;

int main()
{
    int r1,r2,r3;
    int m1,m2;
    char ch[maxn];
    while(scanf("%d%d",&m1,&m2)!=EOF)
    {
        scanf("%s",ch);
        r1=r2=r3=0;
        for(int i=0;i<strlen(ch);i++)
        {
            switch(ch[i])
            {
                case 'A':
                    r1=m1;
                    break;
                case 'B':
                    r2=m2;
                    break;
                case 'C':
                    m1=r3;
                    break;
                case 'D':
                    m2=r3;
                    break;
                case 'E':
                    r3=r1+r2;
                    break;
                case 'F':
                    r3=r1-r2;
                    break;
            }
        }
        printf("%d,%d\n",m1,m2);
    }

    return 0;
}
