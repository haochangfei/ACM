#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num[55];
    int n;
    int age;
    int sum;
    int ct = 1;
    while(cin>>n && n)
    {
        sum = 0;
        for(int i = 0;i < n;i++)
        {
            cin>>num[i];
            sum += num[i];
        }
        age = sum / n;
        sum = 0;
        for(int i = 0; i < n;i++)
        {
            if(num[i] > age)
                sum += num[i] - age;
        }
        cout<<"Set #"<<ct++<<endl;
        cout<<"The minimum number of moves is "<<sum<<"."<<endl;
        cout<<endl;
    }
    return 0;
}
