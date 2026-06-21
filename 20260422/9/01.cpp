#include<bits/stdc++.h>
using namespace std;

struct sequential_stack
{
    int top=-1;
    vector<int> arr;
};

void dec2oct(int num)
{
    sequential_stack sta;
    while(num)
    {
        sta.arr.push_back(num%8);
        sta.top++;
        num/=8;
    }

    while(sta.top>=0)
    {
        cout << sta.arr.at(sta.top);
        sta.arr.pop_back();
        sta.top--;
    }
}

int main(void)
{
    int num; cin >> num;
    dec2oct(num);

    return 0;
}