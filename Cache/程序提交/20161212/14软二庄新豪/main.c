//
//  main.c
//  2016-12-12
//
//  Created by gno on 16/12/12.
//  Copyright © 2016年 gno. All rights reserved.
//
/*
 20161212题目
 1、题目描述：在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。
 题目要求：使用尽可能高效的算法，并分析程序的时间、空间复杂度。
 2、题目描述：写一个函数,它的原形是int continumax(char *outputstr, char *intputstr)功能：在字符串中找出连续最长的数字串，并把这个串的长度返回，并把这个最长数字串付给其中一个函数参数outputstr 所指内存。例如："abcd12345ed125ss123456789"的首地址传给intputstr 后，函数将返回9，outputstr 所指的值为123456789
 题目要求：使用尽可能高效的算法，并分析程序的时间、空间复杂度。
 3、调整数组顺序使奇数位于偶数前面。
 题目描述：输入一个整数数组，调整数组中数字的顺序，使得所有奇数均排在所有偶数的前面。要求时间复杂度为O(n)
*/
//第一题
//顺序遍历串 每次遍历查询该串在当前位置之后是否存在值相同的 不存在则终止遍历
//第二题
//顺序遍历字符串当遇到数字时开始计数 遇到下一个数字字符串时保存上一个 每遇到两个保存较长的
//第三题
//设置两个指针一个从头开始寻找奇数 一个从尾开始倒序寻找偶数 每次分别寻找到之后两个数交换
#include <stdio.h>
#include"string.h"
#define LEN 10
//第一题 算法有待优化 暂传
void printFirstDifferent(char *s)
{
    char swap[100];
    int i = 0,j = 0;
    strcpy(swap, s);
    while(s)
    {
        while(1)
        {
            
            if((swap[i] == *s)&&i!=j)
                break;
            i++;
            if(swap[i]=='\0')
            {
                printf("第一个不重复的字符为:%c\n",swap[j]);
                return;
            }
        }
        s++;
        j++;
        i = 0;
    }
    
}
//第二题
int continumax(char *outputstr, char *intputstr)
{
    int maxLen = 0;
    char s[100];
    int i = 0;
    while(intputstr)
    {
        if((48<=*intputstr)&&(*intputstr<=57))
        {
            s[i] = *intputstr;
            i++;
        }
        else
        {
            if(i>maxLen)
            {
                maxLen = i;
                i++;
                s[i] = '\0';
                strcpy(outputstr, s);
            }
            i = 0;
        }
        if(*intputstr=='\0')
            break;
        intputstr++;
    }
    return maxLen;
}
//第三题
void resArgs(int *args,int length)
{
    int head = 0,tail = length-1;
    while(head<tail)
    {
        while(args[tail]%2==0)tail--;
        while(args[head]%2!=0)head++;
        args[tail] = args[tail]+args[head];
        args[head] = args[tail]-args[head];
        args[tail] = args[tail]-args[head];
    }
}
int main(int argc, const char * argv[]) {
    //第一题
    char str[10]= "aakccdeff\0";
    printFirstDifferent(str);
    //第二题
    char s[100] = "abcd12345ed125ss123456789";
    char smax[100];
    printf("最长的数字子串长度为：%d\n",continumax(smax, s));
    printf("该数字子串为:%s\n",smax);
    //第三题
    int args[LEN] = {1,2,3,4,5,6,7,8,9,0};
    resArgs(args, LEN);
    printf("序列化后的数组:\n");
    for(int i=0;i<LEN;i++)
        printf("%d ",args[i]);
    printf("\n");
    return 0;
}
//时间复杂度
//1.O(n)
//2.O(n)
//3.O(n)
//空间复杂度
//1.O(1)
//2.O(1)
//3.O(1)
