#include <cstdio>
#include <cstring>
using namespace std;

char num[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int findnum(char ch[])
{
    int i;
    for(i=0;i<10;i++)
    {
        if(!strcmp(ch,num[i]))
            break;
    }
    return i;
}

int main()
{
    char ch[10];
    int a,b;
    while(1)
    {
        a=0;
        while(scanf("%s",ch) && strcmp(ch,"+"))
        {
            a=a*10+findnum(ch);
            //printf("a=%d,find=%d\n",a,findnum(ch));
        }
        b=0;
        while(scanf("%s",ch) && strcmp(ch,"="))
        {
            b=b*10+findnum(ch);
            //printf("b=%d,find=%d\n",b,findnum(ch));
        }
        //printf("%d%d",a,b);
        if(a==0 && b==0)
            break;
        else
            printf("%d\n",a+b);


    }
    return 0;
}
