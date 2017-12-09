#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool Identify(int i,int j,int &res1,int &res2)
{   int n[10],flag=1;
    n[0]=i%10,n[1]=i/10%10,n[2]=i/100%10,n[3]=i/1000%10,n[4]=i/10000%10;
    n[5]=j%10,n[6]=j/10%10,n[7]=j/100%10,n[8]=j/1000%10,n[9]=j/10000%10;
    sort(n,n+10);
    for(int i=0;i<10;i++)
        {
            if(n[i]!=i)
            {
                flag=0;
                break;
            }
        }
            if(flag==1)
                return true;
            else
                return false;
}
int main(){
    int n;
    while(scanf("%d",&n)==1)
        {
            int i,j;
        for(i=1234;i<=98765;i++)
            {
                j=i*n;
                if(j>=10234&&j<=98765)
                {
                    int res1=0,res2=1;
                    if(Identify(i,j,res1,res2)==true)
                        {
                            if(i/10000%10&&j/10000%10)
                                printf("%d/%d=%d\n",j,i,n);
                    else
                        {
                            printf("%d/0%d=%d\n",j,i,n);
                        }
                        }
                }
            }
        }
}





