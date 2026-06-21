#include<bits/stdc++.h>
using namespace std;

struct info
{
    string identi;
    string name;
    string grade;
    string classes;

    info *next;
};

void initialization(info **head)
{
    *head=new info;
    (*head)->next=nullptr;
}

void add(info *head)
{
    info *current=new info;
    current=head;

    /*move to tail*/
    while(current->next!=nullptr)
    {
        current=current->next;
    }

    /*set up a new node*/
    info *node=new info;
    node->next=nullptr;

    /*input date domain*/
    cout << "Input ID number:"; cin >> node->identi;
    cout << "Input Name:"; cin >> node->name;
    cout << "Input grade:"; cin >> node->grade;
    cout << "Input classes:"; cin >> node->classes;

    /*link the new node onto tail,pointer domain*/
    current->next=node;
}

void dele(info *head)
{
    /*check empty*/
    if(head==nullptr)
    {
        cout << "Error!" << endl;
        return;
    }

   /*Input the target to delete*/
    string name;
    cout << "Which student do you want to delete:(Input name)";
    cin >> name; 

    info *current=head;

    while(current->next!=nullptr)
    {
        /*check info*/
        if(current->next->name==name)
        {
            info *target=current->next;
            current->next=current->next->next;
            delete target;
            return;
        }
        /*move*/
        current=current->next;
    }

    cout << "Not found!" << endl;
}

void search(info *head)
{
    /*Input the target to search*/
    string name;
    cout << "Which student do you want to search:(Input name)";
    cin >> name;

    /*tranverse and search*/
    info *current=head;
    while(current->next!=nullptr)
    {
        current=current->next;
        if(current->name==name)
        {
            cout << "Got it!" << endl;
            cout << current->identi << ' ' << current->name << ' ' << current->grade << ' ' << current->classes << endl;
            return;
        }
    }
    /*incommon process*/
    cout << "No such person found!";
    return;
}

void print(info *head)
{
    info *current=head;
    while(current->next!=nullptr)
    {
        current=current->next;
        cout << current->identi << ' ' << current->name << ' ' << current->grade << ' ' << current->classes << endl;
    }
}

void insert(info *head)
{
    int position=0;
    cout << "Which position do you want to insert:(input a number)";
    cin >> position;

    info *current=head;

    int i=1;
    while(current->next!=nullptr && i<position)
    {
        current=current->next;
        i++;
    }
    if(i<position)
    {
        cout << "Illeagal input!";
        return;
    }

    
    info *node=new info;

    /*inert link*/
    node->next = current->next;
    current->next = node;

    /*input infomations*/
    cout << "Input ID number:"; cin >> node->identi;
    cout << "Input Name:"; cin >> node->name;
    cout << "Input grade:"; cin >> node->grade;
    cout << "Input classes:"; cin >> node->classes;
}

int main(void)
{
    info *head=nullptr;
    initialization(&head);  //set up a empty linked list
    int whattodo=0;
    
    do
    {
        cout << "What do you want to do?" << endl;
        cout << "(1.add,2.delete,3.search,4.print,5.insert,6.exit)" << endl;
        cin >> whattodo;
        if(whattodo==6)
            break;

        switch(whattodo)
        {
            case 1:add(head); break;
            case 2:dele(head); break;
            case 3:search(head); break;
            case 4:print(head); break;
            case 5:insert(head); break;
            default : cout << "Illeagal input!";
        }

    }while(1);
    
    return 0;
}