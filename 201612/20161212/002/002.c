/*
2����Ŀ������дһ������,����ԭ����int continumax(char *outputstr, char *intputstr)
���ܣ����ַ������ҳ�����������ִ�������������ĳ��ȷ��أ������������ִ���������һ����������outputstr ��ָ�ڴ档
���磺"abcd12345ed125ss123456789"���׵�ַ����intputstr ��
����������9��outputstr ��ָ��ֵΪ123456789
��ĿҪ��ʹ�þ����ܸ�Ч���㷨�������������ʱ�䡢�ռ临�Ӷȡ�
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
        else//������ַ����֣���Ҫ�Ƚ�tempMax�Ƿ��֮ǰ�Ĵ�
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
    ��Ŀδ��ɣ��޸��У�
    �㷨������ʱ�临�Ӷȣ�T(n)=O(n);
              �ռ临�Ӷȣ�S(n)=O(1)��
*/
/*
�������磡��
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
            //������ַ����ֵģ���Ҫ�Ƚ�����ʱ���tempMax�Ƿ��֮ǰ�Ļ���
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
