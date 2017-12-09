#include <stdio.h>
#include <stdlib.h>
#define temp 1000000007

int main()
{
    int m,n;
    int i,j;
    long long sum;
    long long s=0;
    while(scanf("%d%d",&n,&m)!=EOF){

        s=0;
        for(i=1;i<=n;i++){
            sum=1;
            for(j=0;j<m;j++){
                sum=sum*(i%temp);
            }
            sum=sum%temp;
            s=s+(sum%temp);
        }
        s=s%temp;
        printf("%lld\n",s);
    }
    return 0;
}
