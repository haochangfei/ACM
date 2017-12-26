#include <bits/stdc++.h>
#define maxn 60050
using namespace std;

int f(int n)
{
    int sum = 1;
    for(int i = 2;i <= sqrt(n) ;i++)
    {
        if(n%i == 0)
        {
            sum += i;
            sum += (n/i);
            //cout<<i<<" "<<n/i<<endl;
        }
    }
    return sum;
}


int main()
{
    ///  ==n  PERFECT
    ///  <n  DEFICIENT
    ///  >n ABUNDANT
    int num[101];
    int len = 0;
    int ans;
    while(true)
    {
        scanf("%d",&num[len]);
        if(num[len] == 0)
        {
            break;
        }
        len++;
    }
    cout<<"PERFECTION OUTPUT"<<endl;
    for(int i = 0;i < len;i++)
    {
        ans = f(num[i]);
        cout<<setw(5)<<num[i];
        if(ans==num[i])
        {
            cout<<"  "<<"PERFECT"<<endl;
        }
        else if(ans > num[i])
        {
            cout<<"  "<<"ABUNDANT"<<endl;
        }
        else
        {
            cout<<"  "<<"DEFICIENT"<<endl;
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
