/*
3����Ŀ��������һ�������е�ֵ���Ԫ�غ�ֵ��С��Ԫ��
��ĿҪ��ʹ�þ����ܸ�Ч���㷨�������������ʱ�䡢�ռ临�Ӷ�
*/
#include<stdio.h>
main()
{
    int i;
    int a[]={1,2,3,4,5,6,7,8,9,0};
    int max,min;
    max=min=a[0];
    for(i=0;i<10;i++)
    {
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
    }
    printf("max=%d,min=%d\n",max,min);
}
