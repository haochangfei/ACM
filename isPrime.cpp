#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;

long long num[maxn];//save Prime
bool isPrime[maxn];//mark

int main()
{
	int n;
	cin>>n;
	int cnt = 1;//count Prime
	long long sum = 0;
	memset(isPrime,1,sizeof(isPrime));//all isPrime
	isPrime[0] = isPrime[1] = 0; // o and 1 is not
	for(int i=2;i<=n;i++)
	{
		if(isPrime[i]) 
		{
			num[cnt++] = i; 
			sum+=i;
		}
		for(int j=1;j<cnt&&num[j]*i<=n;j++)
		{
			isPrime[num[j]*i] = 0;///筛掉小于等于i的素数和i的积构成的合数  
		}
	}
	cout<<sum<<endl;
	return 0;
}
