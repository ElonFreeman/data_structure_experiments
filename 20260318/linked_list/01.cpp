#include<bits/stdc++.h>
using namespace std;

struct node
{
    int datadomain;
    node *pd_next;
};

void init(node** head)
{
    /*creat a head node*/
    *head = new node;
    (*head)->datadomain = 0;
    (*head)->pd_next = nullptr;
}

void insert(node *head, int data)
{
    /*move to the tail*/
    while(head->pd_next != nullptr)
    {
        head = head->pd_next;
    }

    /*creat new node*/
    node *nextnode = new node;
    nextnode->datadomain = data;
    nextnode->pd_next = nullptr;
    /*tail link to new node*/
    head->pd_next = nextnode;
}

void tranverse_output(node *head)
{
    /*check if the list created*/
    if(head == nullptr)
    {
        cout << "List not defined!" << endl;
        return;
    }
    /*check if the list is empty*/
    if(head->pd_next == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    /*tranverse output - skip head node*/
    node *current = head->pd_next;
    bool first = true;
    
    while(current != nullptr)
    {
        if(!first)
        {
            cout << " ";
        }
        cout << current->datadomain;
        first = false;
        current = current->pd_next;
    }
    cout << endl;
}

int main(void)
{
    node *head = nullptr;
    char command;
    
    // 持续读取命令直到文件结束
    while(cin >> command)
    {
        switch(command)
        {
            case 'I': 
                init(&head);
                break;

            case 'A': 
            {
                int data;
                cin >> data;
                if(head != nullptr)  // 确保链表已创建
                {
                    insert(head, data);
                }
                break;
            }

            case 'C':
            {
                int n;
                cin >> n;
                if(head != nullptr)  // 确保链表已创建
                {
                    for(int i = 0; i < n; i++)
                    {
                        int data;
                        cin >> data;
                        insert(head, data);
                    }
                }
                break;
            }

            case 'P': 
                tranverse_output(head);
                break;
        }
    }

    return 0;
}