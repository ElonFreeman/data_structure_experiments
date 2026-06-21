#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n=6;
    cin >> n;
    //forward_list<string> info={"zhangsan","lisi","wangwu","zhaoliu","xueqi","liuba"};
    forward_list<string> info(n);

    for(string &name:info)
    {
        cin >> name;
    }

    for(string name:info)
    {
        cout << name << endl;
    }
    return 0;
}