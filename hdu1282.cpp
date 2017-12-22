#include <bits/stdc++.h>

using namespace std;

string f(int n)
{
    stringstream ss;
    ss<<n;
    string s = ss.str();
    string s2(s.rbegin(),s.rend());
    return s2;
}

int ff(int n)
{
    stringstream ss;
    ss<<n;
    string s = ss.str();
    string s2(s.rbegin(),s.rend());
    if(s == s2)
        return 1;
    else
        return 0;
}

int main()
{
    int num[35];
    int len=0;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        len = 0;
        while(1)
        {
            if(ff(n))
            {
                num[len]=n;
                break;
            }
            else
            {
                num[len++] = n;
                int temp = atoi(f(n).c_str());
                n = n + temp;
            }
        }
        printf("%d\n",len);
        for(int i=0;i<=len;i++)
        {
            if(i==0)
                printf("%d",num[i]);
            else
            {
                printf("--->%d",num[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
