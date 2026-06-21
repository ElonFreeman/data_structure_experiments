#include <bits/stdc++.h>
using namespace std;

struct quelist
{
    int head, tail;
    int people[10];
};

int main(void)
{
    quelist male = {0, 9, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}}, female = {0, 4, {1, 2, 3, 4, 5}};

    int i = 0;
    while (i < 20)
    {
        cout << male.people[male.head] << ' ' << female.people[female.head] << endl;
        male.head = (male.head + 10 + 1) % 10 , female.head = (female.head + 5 + 1) % 5;
        i++;
    }

    return 0;
}