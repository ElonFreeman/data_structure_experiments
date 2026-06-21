#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int flag1=0,flag2=0,flag3=0;
    string current_name;  /*candidate:name1,name2,name3.input "exit" to break cycle*/
    while(1)
    {
        cin >> current_name;

        if(current_name=="name1")
        {
            flag1++;
        }
        else if(current_name=="name2")
        {
            flag2++;
        }
        else if(current_name=="name3")
        {
            flag3++;
        }
        else if(current_name=="exit")
        {
            break;
        }
        else
        {
            cout << "Illeagal input!";
        }
    }

    cout << "name1:" << flag1 << endl 
    << "name2:" << flag2 << endl 
    << "name3:" << flag3 << endl;

    return 0;
}