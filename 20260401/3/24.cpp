#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;int tmpn=n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin >> arr.at(i);
    }
    int m1,m2;
    cin >> m1 >> m2;
    

    
    for(int j=0;j<tmpn;j++)
    {
        for(int i=0;i<n;i++)
        {

            if(arr.at(i)==m1||arr.at(i)==m2)
            {
                for(int j=i;j<n-1;j++)
                {
                    arr.at(j)=arr.at(j+1);
                }
                n--;
            }
        }
    }

    if(n==0)
    {
        cout << "顺序表已为空";
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        cout << arr.at(i) << ' ';
    }

    return 0;
}