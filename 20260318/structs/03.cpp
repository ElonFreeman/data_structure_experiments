#include<bits/stdc++.h>
using namespace std;

struct infos
{
    int stu_id;
    float score;
};

void info_sort(vector<infos> *stu_info)
{
    sort((*stu_info).begin(),(*stu_info).end(),[](const infos a,const infos b){return a.score>b.score;});
}

int main(void)
{
    int n=0;
    cin >> n;
    vector<infos> stu_infos(n);
    for(infos &traverse:stu_infos)
    {
        cin >> traverse.stu_id;
        cin >> traverse.score;
    }

    info_sort(&stu_infos);

    for(int counter=0;counter<n;counter++)
    {
        if(counter>0 && stu_infos.at(counter).score==stu_infos.at(counter-1).score)
        {
            printf("%d %d %.2f\n",counter,stu_infos.at(counter).stu_id,stu_infos.at(counter).score);
            continue;
        }
        printf("%d %d %.2f\n",counter+1,stu_infos.at(counter).stu_id,stu_infos.at(counter).score);
    }

    return 0;
}