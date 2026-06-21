#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

void add(node *head,int data)
{
    node *current=head;
    while(current->next!=nullptr)
    {
        current=current->next;
    }

    node *newnode=new node;
    newnode->data=data;
    newnode->next=nullptr;

    current->next=newnode;
}

void insert(node *head,int data)
{
    node *current=head;
    while(current->next!=nullptr)
    {
        current=current->next;
        if(current->data==data)
        {
            return;
        }
    }
    /*if(current->data==data)
    {
        return;
    }*/

    current=head;
    while(current->next->data<data)
    {
        current=current->next;
    }

    node *newnode=new node;
    newnode->data=data;
    newnode->next=current->next;
    current->next=newnode;
}

void print(node *head)
{
    node *current=head;
    while(current->next!=nullptr)
    {
        current=current->next;
        cout << current->data << ' ';
    }

    return;
}

int main(void)
{
    /*init*/
    node *head=nullptr;
    node *headnode=new node;
    headnode->next=nullptr;
    head=headnode;

    /*input*/
    int length;
    cin >> length;
    for(int i=0;i<length;i++)
    {
        int data;
        cin >> data;
        add(head,data);
    }
    int insertdata;
    cin >> insertdata;
    insert(head,insertdata);


    print(head);
    return 0;
}