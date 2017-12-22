#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int k=0;
        while(n!=1)
        {
            if(n%2==0)
            {
                n=n/2;
            }
            else
            {
                if(k==0)
                {
                    printf("%d",n);
                    k++;
                }
                else
                {
                    printf(" %d",n);
                }
                n=3*n+1;
            }
        }
        if(k==0)
        {
            printf("No number can be output !");
        }
        printf("\n");
    }
    return 0;
}
