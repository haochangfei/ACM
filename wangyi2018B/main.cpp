

/*Ϊ�˵õ�һ������"�෴��",���ǽ������������˳��ߵ�,Ȼ���ټ���ԭ�ȵ����õ�"�෴��"��

����,Ϊ�˵õ�1325��"�෴��",�������ǽ�����������˳��ߵ�,���ǵõ�5231,֮���ټ���ԭ�ȵ���,

���ǵõ�5231+1325=6556.����ߵ�֮���������ǰ׺��,ǰ׺�㽫�ᱻ���ԡ�

����n = 100, �ߵ�֮����1

�������һ������n,(1 �� n �� 10^5)

���һ������,��ʾn���෴��*/
/*
1325
100000
6556
*/
#include<stdio.h>
int f(int n)
{
    int sum=1;
    while(n--)
    {
        sum*=10;
    }
    return sum;
}

int main()
{
    int num[10]={0};
    int len,i=0;
    long long n,temp;
    scanf("%lld",&n);
    //printf("%lld\n",n);
    temp = n;
    while(temp)
    {
        num[i] = temp%10;
        temp=temp/10;
        i++;
       // printf("%d",num[i-1]);
    }
    len = i-1;
    temp=n;
    for(int j=len;j>=0;j--)
    {
        temp += num[j]*f(len-j);
        //printf("%d\n",num[j]*f(len-j));
    }
    printf("%lld",temp);
    return 0;
}
