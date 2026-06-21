#include<bits/stdc++.h>
using namespace std;

struct infos
{
    string name;
    int stu_id;
    float score;
};

int main(void)
{
    int n=0;
    cin >> n;
    vector<infos> stu_info(n);
    for(infos &traverse:stu_info)
    {
        cin >> traverse.stu_id;
        cin >> traverse.name;
        cin >> traverse.score;
    }

    float sum=0;
    for(infos score:stu_info)
    {
        sum+=score.score;
    }
    float average=sum/n;

    int unpassed=0;
    for(infos unpass:stu_info)
    {
        if(unpass.score<60)
        {
            unpassed++;
        }
    }

    printf("%.2f %.2f %d",sum,average,unpassed);

    return 0;
}