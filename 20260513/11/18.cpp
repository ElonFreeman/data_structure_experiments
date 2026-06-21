#include<bits/stdc++.h>
using namespace std;

int main()
{

    string s[5],t;

    int j,i;

    for(i=0;i<5;i++)
    {
        cin >> s[i];
    }
        

    //---------------错误开始区域------------------

    for(i=0;i<5-1;i++)
    {
      for(j=0;j<5-1-i; j++)
      {
        if(s[j]>s[j+1])
        {
            t=s[j]; s[j]=s[j+1]; s[j+1]=t;
        }  
      }
    }

    //---------------错误结束区域------------------

    for(i=0;i<5; i++)
      cout << s[i] << endl;

    return 0;

}