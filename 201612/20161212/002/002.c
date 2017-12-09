/*
2、题目描述：写一个函数,它的原形是int continumax(char *outputstr, char *intputstr)
功能：在字符串中找出连续最长的数字串，并把这个串的长度返回，并把这个最长数字串付给其中一个函数参数outputstr 所指内存。
例如："abcd12345ed125ss123456789"的首地址传给intputstr 后，
函数将返回9，outputstr 所指的值为123456789
题目要求：使用尽可能高效的算法，并分析程序的时间、空间复杂度。
*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define M 100
int continumax(char *outputstr, char *intputstr);
main()
{
    char arr[M],out[M];
    gets(arr);
    printf("%d %s",continumax(out, arr),out);
}
int continumax(char *outputstr, char *intputstr)
{
    int start = 0,end = 0,max = 0;
    int tempStart = 0,tempMax = 0;
    int length = strlen(intputstr);
    int cur = 0;

    for( ;cur < length ;cur++)
    {
        char c = intputstr[cur];
        if(isdigit(c))
        {
            if(tempMax == 0)
            {
                tempStart = cur;
            }
            tempMax ++;
        }
        else//如果出现非数字，需要比较tempMax是否比之前的大
        {
            if(tempMax > max)
            {
                start = tempStart;
                end = cur;
                max = tempMax;
                tempMax = 0;
            }
        }
    }

    if(tempMax > max)
        {
                start = tempStart;
                end = cur;
                max = tempMax;
                tempMax = 0;
        }

    for(cur = 0;cur < end - start; cur++)
    {
        outputstr[cur] = intputstr[cur + start];
    }
    return max;
}

/*
    题目未完成！修改中！
    算法分析：时间复杂度：T(n)=O(n);
              空间复杂度：S(n)=O(1)；
*/
/*
来自网络！！
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX 100

int continumax(char *outputstr,char *intputstr);

int main() {
    char arr[MAX];
    memset(arr,0,sizeof(arr));
//  cin>>arr;
    gets(arr);

    char out[MAX];
    memset(out,0,sizeof(out));
    int len = continumax(out, arr);
    cout<<len<<endl<<out;
    return 0;
}

int continumax(char *outputstr,char *intputstr){
    int start=0, end=0, max=0;
    int tempStart=0, tempMax=0;
    int length = strlen(intputstr);
    int cur=0;
    for(;cur<length;cur++){
        char c = intputstr[cur];
        if(c>='0' && c<='9'){
            if(tempMax == 0){
                tempStart=cur;
            }
            tempMax++;
        }else{
            //如果出现非数字的，需要比较下这时候的tempMax是否比之前的还大
            if(tempMax>max){
                start = tempStart;
                end = cur;
                max = tempMax;

                tempMax=0;
            }
        }
    }

    if(tempMax>max){
        start = tempStart;
        end = cur;
        max = tempMax;

        tempMax=0;
    }

    for(cur=0;cur<end-start;cur++)
        outputstr[cur]= intputstr[cur+start];
    return max;

}
*/
