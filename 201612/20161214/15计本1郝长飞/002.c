/*
题目描述：设有两个仅由英文字母组成的字符串A和B，其中B的长度小于A。请查找出B里的所有字母是否都在A中。
如：A串 ABCDEFGHLMNOPQRST
      B串 DCGSRQPO
      输出为true
      A串 ABCDSOPLMNR
      B串 DCGZAS
      输出为false
题目要求: 给出尽可能高效的算法思想，描述所用算法， 提交可执行的标准C代码， 分析时间，空间复杂度。
*/
#include<stdio.h>
#include<string.h>
#define M 100
int EEE(char *a,char *b);
main()
{
    char ch1[M]="ABCDEFGHLMNOPQRST";
    char ch2[M]="DCGSRQPO";
    char ch3[M]="ABCDSOPLMNR";
    char ch4[M]="DCGZAS";
    printf("A:%s",ch1);
    printf("\nB:%s",ch2);
    if(EEE(ch1,ch2)==1)
        printf("\ntrue");
    else
        printf("\nfalse");
    printf("\nA:%s",ch3);
    printf("\nB:%s",ch4);
    if(EEE(ch3,ch4)==1)
        printf("\ntrue");
    else
        printf("\nfalse");

}
int EEE(char *a,char *b)
{
    int len=strlen(b);
    int i=0;
    while(i<len)
    {
        if((strchr(a,b[i]))==NULL)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
/*
算法分析：时间复杂度T(n)=O(n);空间复杂度S(n)=O(1);
*/
