#include<bits/stdc++.h>
using namespace std;

struct scores
{
    string name;
    int advanced_lang;
    int data_stru;
    int algorithm_anali;
};

int main(void)
{
    /*input infos*/
    int n=5;
    vector<scores> score(n);
    for(scores &record:score)
    {
        cin >> record.name;
        cin >> record.advanced_lang;
        cin >> record.data_stru;
        cin >> record.algorithm_anali;
    }

    /*summary*/
    vector<int> sums(n);
    for(int iterator=0;iterator<n;iterator++)
    {
        sums.at(iterator)=score.at(iterator).advanced_lang + score.at(iterator).data_stru + score.at(iterator).algorithm_anali;
    }

    /*search maximum*/
    int max=sums.at(0),traverse=0;
    string name;
    while(traverse<n)
    {
        if(sums.at(traverse)>max)
        {
            max=sums.at(traverse);
            name=score.at(traverse).name;
        }

        traverse++;
    }

    cout << name << ' ' << max;

    return 0;
}