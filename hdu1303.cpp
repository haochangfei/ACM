#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num[100];
    int n[20];
    int a;

    while(scanf("%d",&n[0]) && n[0]!=-1)
    {
        memset(num,0,sizeof(num));
        num[n[0]]=1;
        int i=1;
        while(scanf("%d",&a) && a)
        {
            n[i] = a;
            num[a]++;
            i++;
        }
        sort(n,n+i);
        int len=0;
        for(int j = 0; j < i; j++)
        {
            int k = num[2*n[j]];
            if(k)
                len+=k;
        }
        cout<<len<<endl;
    }
    return 0;
}
