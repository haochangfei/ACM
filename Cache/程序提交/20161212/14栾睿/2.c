/*
2.写一个函数,它的原形是int continumax(char *outputstr, char *intputstr)
    功能：在字符串中找出连续最长的数字串，并把这个串的长度返回，并把这个最
    长数字串付给其中一个函数参数outputstr 所指内存。
    例如："abcd12345ed125ss123456789"的首地址传给intputstr 后，
    函数将返回9，outputstr 所指的值为123456789
*/

#include<stdio.h>
#include<string.h>

#define MAX 50

int continumax(char *outputstr, char *intputstr)
{
    int start = 0,end = 0,max = 0;
    int tempStart = 0,tempMax = 0;
    int length = strlen(intputstr);
    int cur = 0;

    for( ;cur < length ;cur++)
    {
        char c = intputstr[cur];
        if(c>='0' && c<='9')
        {
            if(tempMax == 0){
                tempStart = cur;
            }
            tempMax ++;
        }
        else{
            //如果出现非数字，需要比较tempMax是否比之前的大
            if(tempMax > max){
                start = tempStart;
                end = cur;
                max = tempMax;

                tempMax = 0;
            }
        }
    }

    if(tempMax > max){
                start = tempStart;
                end = cur;
                max = tempMax;

                tempMax = 0;
            }

        for(cur = 0;cur < end - start; cur++){
            outputstr[cur] = intputstr[cur + start];
        }
    return max;
}

int main()
{
    char arr[MAX] = {0};

    gets(arr);

    char out[MAX] = {0};
    int len = continumax(out, arr);

    printf("MaxLength:%d\n",len);
    printf("%s",out);
    return 0;
}
//时间复杂度：O(n)
//空间复杂度：O(1)
