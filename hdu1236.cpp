#include <bits/stdc++.h>



using namespace std;

struct Stu{
    string name;
    int m;
    int sum=0;
}stu[1005];

bool cmp(Stu s1,Stu s2)
{
    if(s1.sum>s2.sum)
    {
        return true;
    }
    else if(s1.sum==s2.sum)
    {
        if(s1.name<s2.name)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int n,m,g;
    int a;
    int pro[15];
    while(scanf("%d",&n)!=EOF && n)
    {

        scanf("%d%d",&m,&g);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&pro[i]);
        }
        for(int i=0;i<n;i++)
        {
            stu[i].sum=0;
            cin>>stu[i].name;
            scanf("%d",&stu[i].m);
            for(int j=0;j<stu[i].m;j++)
            {
                scanf("%d",&a);
                stu[i].sum+=pro[a];
            }
        }
        sort(stu,stu+n,cmp);
        int num=0;
        for(int i=0;i<n;i++)
        {
            //cout<<stu[i].name<<" "<<stu[i].m<<" "<<stu[i].sum<<endl;
            if(stu[i].sum>=g)
            {
                num++;
            }
        }
        cout<<num<<endl;
        for(int i=0;i<num;i++)
        {
            cout<<stu[i].name<<" "<<stu[i].sum<<endl;
        }
    }
    return 0;
}
