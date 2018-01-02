#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
//    string s="il8n";
//    s.replace(1,2,"nternationalizatio");///从索引1开始的2个替换成后面的
//    //C_string s = internationalization;
//    if(s.find("yu")==string::npos)
//        cout<<"dsfsd"<<endl;
//    cout<<s.find("yu")<<endl;
//    cout<<s<<endl;
    int m,n,t,s;
    string sh[21];
    string cc="";//构造与字符串等长的*号字符串

    scanf("%d %d",&m,&n);
    getchar();//吞掉一个换行
    for(int i=0; i<m; i++)
    {
        getline(cin,sh[i]);
        //cout<<sh[i]<<endl;
    }
    sort(sh,sh+m);//对输入的单词排序
    string th[21];
    for(int j=0; j<n; j++)
    {
        getline(cin,th[j]);
        //cout<<th[j];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            while(th[i].find(sh[j])!=string::npos)//当找到这个字符串的时候进入
            {
                for(int z=0; z<sh[j].length(); z++)
                {
                    cc+='*';
                }

                th[i].replace(th[i].find(sh[j]),sh[j].length(),cc);//替换
                cc="";

            }
        }
        cout<<th[i]<<endl;
    }

return 0;
}
