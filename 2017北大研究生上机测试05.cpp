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
    string cc="";

    scanf("%d %d",&m,&n);
    getchar();
    for(int i=0; i<m; i++)
    {
        getline(cin,sh[i]);
        //cout<<sh[i]<<endl;
    }
    sort(sh,sh+m);
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
            while(th[i].find(sh[j])!=string::npos)
            {
                for(int z=0; z<sh[j].length(); z++)
                {
                    cc+='*';
                }

                th[i].replace(th[i].find(sh[j]),sh[j].length(),cc);
                cc="";

            }
        }
        cout<<th[i]<<endl;
    }

return 0;
}
