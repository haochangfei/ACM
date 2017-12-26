#include <bits/stdc++.h>
#define maxn 99999+5
using namespace std;

double num[maxn];

void init()
{
    memset(num,0.0,sizeof(num));
    for(int i = 1;i < maxn ;i++)
    {
        num[i] += num[i-1] + 1.0/(2*i);
    }
}

int main()
{
    init();
    int n;
    cout<<"# Cards  Overhang"<<endl;
    while(scanf("%d",&n) != EOF)
    {
        printf("%5d%10.3lf\n",n,num[n]);
    }
    return 0;
}
