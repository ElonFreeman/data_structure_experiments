#include<bits/stdc++.h>
using namespace std;

char* match(string *str,char *ch)
{
    for(size_t i=0;i<(*str).length();i++)
    {
        if((*str)[i]==*ch)
        {
            return &(*str)[i];
        }
    }

    return nullptr;
}

int main(void)
{
    string str;
    cin >> str;
    char ch;
    cin >> ch;

    char *position=match(&str,&ch);
    if(position==nullptr)
    {
        cout << "something error!";
        return 1;
    }

    while((*position)!='\0')
    {
        cout << *(position);
        position++;
    }
    
    return 0;
}