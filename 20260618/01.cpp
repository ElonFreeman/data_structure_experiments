#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int num_data; cin >> num_data;
    vector<int> dataset;
    for(int i=0;i<num_data;i++){int value; cin >> value; dataset.push_back(value);}
    sort(dataset.begin(),dataset.end(),[](int a,int b){return a<b;});

    int low=0,high=size(dataset)-1,mid=(low+high)/2,search,flag=0; cin >> search;
    while(low<=high)
    {   mid=(low+high)/2;
        if(search==dataset[mid]){cout << "got it! at:" << mid << endl; flag=1; break;}
        else if(search>dataset[mid]){low=mid+1;}
        else if(search<dataset[mid]){high=mid-1;}
    }
    if(flag==0){cout << "not found!" << endl;}
    
    return 0;
}