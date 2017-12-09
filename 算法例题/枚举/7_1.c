#include<stdio.h>
/*
*输入正整数n，按从小到大的顺序输出所有形如abcde/fghij=n的表达式，
*其中a~j恰好为数字0-9的一个排列（可以有前导0），2<=n<=79.
*/
int searchpls(int n)
{
    int i = 0;
    int a = n%10;
    int b = n/10%10;
    int c = n/100%10;
    int d = n/1000%10;
    int e = n/10000%10;
    int m[10];
    for(i = 0;i < 10;i++)
        m[i] = 1;

    m[a] = 0;

    if(m[b])
        m[b] = 0;
    else
        return 0;

    if(m[c])
        m[c] = 0;
    else
        return 0;

    if(m[d])
        m[d] = 0;
    else
        return 0;

    if(m[e])
        m[e] = 0;
    else
        return 0;

    return 1;
}
int searchqpls(int n1,int n2)
{
    int i = 0;
    int a = n1%10;
    int b = n1/10%10;
    int c = n1/100%10;
    int d = n1/1000%10;
    int e = n1/10000%10;
    int a1 = n2%10;
    int b1 = n2/10%10;
    int c1 = n2/100%10;
    int d1 = n2/1000%10;
    int e1 = n2/10000%10;
    int m[10];
    for(i = 0;i < 10;i++)
        m[i] = 1;

    m[a] = 0;

    if(m[b])
        m[b] = 0;
    else
        return 0;

    if(m[c])
        m[c] = 0;
    else
        return 0;

    if(m[d])
        m[d] = 0;
    else
        return 0;

    if(m[e])
        m[e] = 0;
    else
        return 0;

    if(m[a1])
        m[a1] = 0;
    else
        return 0;

        if(m[b1])
        m[b1] = 0;
    else
        return 0;

        if(m[c1])
        m[c1] = 0;
    else
        return 0;

        if(m[d1])
        m[d1] = 0;
    else
        return 0;

        if(m[e1])
        m[e1] = 0;
    else
        return 0;

    return 1;
}
int main()
{
    int i = 0;
    int max = 98765;
    int a = 0;
    int n = 0;
    scanf("%d",&n);
    for(i = max;i>=1234*n;i--)
    {
        if(searchpls(i))
        {
            if(i%n==0)
            {
                a = i/n;
                if(searchpls(a))
                    if(searchqpls(i,a))
                {
                    if(a<10000)
                        printf("%d / 0%d = %d\n",i,a,n);
                    else
                        printf("%d / %d = %d\n",i,a,n);
                }
            }
        }
        else
        continue;
    }
    return 0;
}

