#include<bits/stdc++.h>
using namespace std;

int josephus_iterate(int total,int k)  //zero-based
{
    int survivor=0;
    for(int i=2;i<=total;i++)
    {
        survivor=(survivor+k)%i;
    }

    return survivor;
}

int josephus_recursive(int total,int k)
{
    if(total==0)
    {
        return 1;
    }
    else
    {
        return ((josephus_recursive(total-1,k)+k)%total);
    }
}

int main(void)
{
    int total,k; cin >> total >> k;
    int jo_ite=josephus_iterate(total,k),jo_rec=josephus_recursive(total,k);
    cout << jo_ite  << ' ' << jo_rec << endl;

    return 0;
}