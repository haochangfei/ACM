/*
2.дһ������,����ԭ����int continumax(char *outputstr, char *intputstr)
    ���ܣ����ַ������ҳ�����������ִ�������������ĳ��ȷ��أ����������
    �����ִ���������һ����������outputstr ��ָ�ڴ档
    ���磺"abcd12345ed125ss123456789"���׵�ַ����intputstr ��
    ����������9��outputstr ��ָ��ֵΪ123456789
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
            //������ַ����֣���Ҫ�Ƚ�tempMax�Ƿ��֮ǰ�Ĵ�
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
//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(1)
