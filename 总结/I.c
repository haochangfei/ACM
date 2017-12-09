#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    int temp;
    char n[1002];
    int z[1002];
    while(scanf("%s",n)!=EOF){
        for(i=0;n[i]!='\0';i++){
            z[i]=n[i];
        }
        for(i=0;i<strlen(n);i++){
            temp=z[i]%3;
            if(temp!=0)
                z[i+1]=temp*10+z[i+1];
        }
        if(temp==0)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
