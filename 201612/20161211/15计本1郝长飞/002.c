/*
2����Ŀ������һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
��ĿҪ��ʹ�þ����ܸ�Ч���㷨�������������ʱ�䡢�ռ临�Ӷ�
*/
#include<stdio.h>
#define N 10
main()
{
    int a[N]={1,1,2,2,3,3,4,4,5,6};
    int i=0,j,k;
    for(i=0;i<N;i++)//�ֱ��ȡ���������
    {
        k=0;
        for(j=0;j<N;j++)//Ѱ���������Ƿ��г��䱾����������ͬ������
        {
            if(i!=j&&a[i]==a[j])//����� �ͽ�k�ı�
                k=1;
        }
         if(k==0)//���kδ����˵��û���ҵ���
                printf("%d\t",a[i]);
    }
}
/*
�㷨������
          ʱ�临�Ӷȣ�T(n)=O(n^2);
          �ռ临�Ӷȣ�S(n)=O(1);
*/

/*
void FindTwoNotRepeatNumberInArray(int *a, int n, int *pN1, int *pN2)
{
    int i, j, temp;

    //�������������������
    temp = 0;
    for (i = 0; i < n; i++)
        temp ^= a[i];

    // �ҵ�һ��Ϊ1��λ
    for (j = 0; j < sizeof(int) * 8; j++)
        if (((temp >> j) & 1) == 1)
            break;

    // ��jλΪ1,˵�������������ڵ�jλ���ǲ���ͬ��
    // �ɴ˷��鼴��
    *pN1 = 0, *pN2 = 0;
    for (i = 0; i < n; i++)
        if (((a[i] >> j) & 1) == 0)
            *pN1 ^= a[i];
        else
            *pN2 ^= a[i];
}
void PrintfArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
}
int main()
{
    printf("    �׻������㷨ϵ��֮ʮ�������в��ظ��ĸ�����(�ٶ�������) \n");
    printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

    const int MAXN = 10;
    //int a[MAXN] = {1, 2, 7, 5, 100,  100, 6, 1, 2, 5};
    int a[MAXN] = {1, 2, 3, 4, 1,  2, 3, 4, 0, 5};

    printf("����Ϊ: \n");
    PrintfArray(a, MAXN);

    int nNotRepeatNumber1, nNotRepeatNumber2;
    FindTwoNotRepeatNumberInArray(a, MAXN, &nNotRepeatNumber1, &nNotRepeatNumber2);
    printf("�������ظ������ֱַ�Ϊ: %d %d\n", nNotRepeatNumber1, nNotRepeatNumber2);
    return 0;
}
*/
