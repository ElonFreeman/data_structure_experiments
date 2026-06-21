#include<bits/stdc++.h>
using namespace std;

string mainstr="asdfghjklpoiuyt",substr1="hjklpo",substr2="hqklbo";

int match_brute_force(string mainstr,string substr)
{
    if(size(substr)==0) return 0;

    int i=0,j=0,start=0;
    while(i<size(mainstr) && j<size(substr))
    {
        if(mainstr[i]==substr[j])
        {
            i++,j++;
        }
        else
        {
            start++;
            i=start;
            j=0;
        }
    }

    if(j>=size(substr)) return start+1; //1-based
    else return -1;
}

string dele(string mainstr,int posi,int length)
{
    cout << mainstr <<endl;
    int lenmain=size(mainstr);
    for(int cur=posi-1+length;cur<lenmain;cur++)
    {
        mainstr[cur-length]=mainstr[cur];
    }

    mainstr.resize(lenmain-length);

    //cout << mainstr << endl;
    return mainstr;
}

int main(void)
{
    int startposi=match_brute_force(mainstr,substr1),strlen=size(substr1);

    cout << startposi << endl;
    cout << match_brute_force(mainstr,substr2) << endl;

    string mainstr2=dele(mainstr,startposi,size(substr1));
    mainstr=mainstr2;
    cout << mainstr << endl;

    return 0;
}