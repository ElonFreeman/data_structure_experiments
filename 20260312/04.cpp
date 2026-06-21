#include<bits/stdc++.h>
using namespace std;

struct contacts
{
    string name;
    int age;
    string phone_number;
};

void insert(contacts *info)
{
    string name,phone_number;int age=0;
    int  flag=0;
    for(int i=0;(info+i)->age!=0;i++)
    {
        flag++;
    }
    while(1)
    {
        cout << "Please input the infomation or input 'back' to go back:" << endl;
        cout << "name:",cin >> name;
        if(name=="back")break;
        (info+flag)->name=name;
        cout << "age:",cin >> age,(info+flag)->age=age;
        cout << "phone_number:",cin >> phone_number,(info+flag)->phone_number=phone_number;
        flag++;
    }
}

int search(contacts *info,int volume)
{
    string name;
    while(name!="back")
    {
        int flag=0;
        cout << "Please input name to search or input 'back' to go back:";
        cin >> name;

        for(int i=0;i<volume;i++)
        {
            if((info+i)->name==name)
            {
                cout  << "Got it!" << endl,flag=1;
                cout << (info+i)->name << ' ' << (info+i)->age << ' ' << (info+i)->phone_number << endl;
                break;
            }
        }
        if(flag==1)
        {
            continue;
        }
        else
        {
            cout << "Failed!" << endl;
        }
    }

    return 0;
}

int main(void)
{
    struct contacts info[50]=
    {
        {"张三", 25, "13800138001"},
        {"李四", 30, "13800138002"},
        {"王五", 22, "13800138003"},
        {"赵六", 28, "13800138004"},
        {"陈七", 35, "13800138005"},
        {"刘八", 27, "13800138006"},
        {"周九", 24, "13800138007"},
        {"吴十", 32, "13800138008"},
        {"郑一一", 26, "13800138009"},
        {"王十二", 29, "13800138010"},
        {"李十三", 31, "13800138011"},
        {"张十四", 23, "13800138012"},
        {"刘十五", 33, "13800138013"},
        {"陈十六", 34, "13800138014"},
        {"周十七", 36, "13800138015"},
        {"吴十八", 21, "13800138016"},
        {"郑十九", 38, "13800138017"},
        {"王二十", 39, "13800138018"},
        {"李二一", 40, "13800138019"},
        {"张二二", 41, "13800138020"},
        {"刘二三", 42, "13800138021"},
        {"陈二四", 43, "13800138022"},
        {"周二五", 44, "13800138023"},
        {"吴二六", 45, "13800138024"},
        {"郑二七", 46, "13800138025"},
        {"王二八", 47, "13800138026"},
        {"李二九", 48, "13800138027"},
        {"张三零", 49, "13800138028"},
        {"刘三一", 50, "13800138029"},
        {"陈三二", 18, "13800138030"},
        {"周三三", 19, "13800138031"},
        {"吴三四", 20, "13800138032"},
        {"郑三五", 21, "13800138033"},
        {"陈道明", 65, "13800138046"},
        {"周星驰", 58, "13800138047"},
        {"吴孟达", 68, "13800138048"},
        {"郑伊健", 53, "13800138049"},
        {"王力宏", 47, "13800138050"}
    };

    
    string action;
    while(action!="exit")
    {
        cout << "What do you wang to do (insert,search or input 'exit' to exit):";
        cin >> action;

        if(action=="insert")
        {
            insert(info);
        }
        else if(action=="search")
        {
            search(info,size(info));
        }
        else if(action!="insert"&&action!="search"&&action!="exit")
        {
            cout << "Illeagally input!" << endl;
        }
    }

    return 0;
}