#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    char ch[35];
    cin>>t;
    while(t--)
    {
        scanf("%s",ch);
        strrev(ch);
        int len = strlen(ch);
        int k=0;
        if(ch[len-1]=='-')
        {
            for(int i=0; i<len-1; i++)
            {
                if(ch[i]=='0')
                {
                    k++;
                }
                else
                {
                    printf("-");
                    for(int j=i; j<len-1; j++)
                    {
                        printf("%c",ch[j]);
                    }
                    break;
                }
            }
            while(k--)
            {
                printf("0");
            }
            printf("\n");
        }
        else
        {
            for(int i=0; i<len; i++)
            {
                if(ch[i]=='0')
                {
                    k++;
                }
                else
                {
                    for(int j=i; j<len; j++)
                    {
                        printf("%c",ch[j]);
                    }
                    break;
                }
            }
            while(k--)
            {
                printf("0");
            }
            printf("\n");
        }
    }
    return 0;
}
