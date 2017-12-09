#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string str[1005];
    int maxn,sum[1005];
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>str[i];
        }
        sort(str+1,str+n+1);
        //for(int i=1;i<=n;i++){cout<<str[i]<<endl;}
        maxn=1;
        for(int i=1;i<=n;i++)
        {
            sum[i]=1;
        }
        for(int i=2;i<=n;i++)
        {
            if(str[i]==str[i-1])
                sum[i]+=sum[i-1];
            if(sum[i]>=sum[maxn])
                maxn=i;
        }
        cout<<str[maxn]<<endl;

    }
    return 0;
}
