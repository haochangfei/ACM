/*
1����Ŀ����������һ����Ԫ��ֵ�������е������һ�����֣��������в�������Ԫ�أ�ʹ������֮�͵���������Ǹ����֡�����ж������֮�͵����Ǹ����֣��������һ�Լ��ɡ�
����:���� ���� 2  5  7    10  13  20 ������20
���  7  13
��ĿҪ��ʹ�þ����ܸ�Ч���㷨�������������ʱ�䡢�ռ临�Ӷ�
*/
#include<stdio.h>
#define N 6
int BiSearch(int data[],  int x, int beg, int last);
main()
{
    int i;
    int a[N];
    int num;
    int t1,t2;
    printf("����");
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("����");
    scanf("%d",&num);

    i=N;
    while(i>=0)
    {
        if(a[i]>num)
            i--;
        else
        {
            t1=num-a[i];
            i--;
            if((t2=BiSearch(a,t1,0,i))!=-1)
            {
                printf("%d\t%d",t1,a[i+1]);
                break;
            }
        }
    }
}
int BiSearch(int data[],  int x, int beg, int last)//�۰����
{
    int mid;
    if (beg > last)
    {
        return -1;
    }


    while(beg <= last)
    {
        mid = (beg + last) / 2;
        if (x == data[mid] )
        {
            return mid;
        }
        else if (data[mid] < x)
        {
            beg = mid + 1;
        }
        else if (data[mid] > x)
        {
            last = mid - 1;
        }
    }
    return -1;
}
/*
�㷨������ʱ�临�Ӷ�T(n)=O(n(logn+1));
          �ռ临�Ӷȣ�S(n)=O(1);
*/
