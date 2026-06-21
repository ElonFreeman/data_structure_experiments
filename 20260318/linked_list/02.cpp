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

void add(node *head, int data)
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

void insert_node(node *head, int position, int data)
{
    // 注意：这里 head 是头结点，position 从 1 开始表示第一个数据结点
    // 需要移动到要插入位置的前一个结点
    for(int i = 0; i < position - 1; i++)
    {
        if(head->pd_next == nullptr && i < position - 2)
        {
            cout << "Position out of range!" << endl;
            return;
        }
        head = head->pd_next;
    }

    /*creat new node*/
    node *nextnode = new node;
    nextnode->datadomain = data;
    nextnode->pd_next = head->pd_next;

    head->pd_next = nextnode;
}

int search(node *head, int value)
{
    int i = 1;
    // 跳过头结点，从第一个数据结点开始
    head = head->pd_next;
    
    while(head != nullptr)
    {
        if(head->datadomain == value)
        {
            cout << "index:" << i << endl;
            return 0;
        }
        head = head->pd_next;
        i++;
    }
    cout << "Not Found!" << endl;
    return 0;
}

void delete_node(node *head, int position)
{
    // 检查链表是否为空
    if(head == nullptr || head->pd_next == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    
    // 检查位置是否有效（position 从 1 开始）
    if(position < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    
    // 移动到要删除结点的前一个结点
    node *prev = head;
    for(int i = 0; i < position - 1; i++)
    {
        if(prev->pd_next == nullptr)
        {
            cout << "Position out of range!" << endl;
            return;
        }
        prev = prev->pd_next;
    }
    
    // 检查要删除的结点是否存在
    if(prev->pd_next == nullptr)
    {
        cout << "Position out of range!" << endl;
        return;
    }
    
    // 保存要删除的结点
    node *temp = prev->pd_next;
    
    // 将前一个结点的指针指向要删除结点的下一个结点
    prev->pd_next = temp->pd_next;
    
    // 释放要删除结点的内存
    delete temp;
    
    cout << "Node at position " << position << " deleted successfully!" << endl;
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
                    add(head, data);
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
                        add(head, data);
                    }
                }
                break;
            }

            case 'P': 
                tranverse_output(head);
                break;

            case 'N':
                int position=0,data=0;
                cin >> position;cin >> data;
                insert_node(head,position,data);
                break;

            case 'F':
                int value=0;
                cin >> value;
                search(head,value);
                break;
            
            case 'D':
                int position=0;
                cin >> position;
                delete_node(head,position);
                break;
        }
    }

    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;

struct node
{
    int datadomain;
    node *pd_next;
};

void init(node** head)
{
    /*creat a head node
    *head = new node;
    (*head)->datadomain = 0;
    (*head)->pd_next = nullptr;
}

void add(node *head, int data)
{
    /*move to the tail
    while(head->pd_next != nullptr)
    {
        head = head->pd_next;
    }

    /*creat new node
    node *nextnode = new node;
    nextnode->datadomain = data;
    nextnode->pd_next = nullptr;
    /*tail link to new node
    head->pd_next = nextnode;
}

void tranverse_output(node *head)
{
    /*check if the list created
    if(head == nullptr)
    {
        cout << "List not defined!" << endl;
        return;
    }
    /*check if the list is empty
    if(head->pd_next == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    /*tranverse output - skip head node
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

void List_Insert(node *head, int n, int d)
{
    // 检查链表是否已创建
    if(head == nullptr)
    {
        cout << "List not defined!" << endl;
        return;
    }
    
    // 检查位置是否有效（位置从1开始）
    if(n < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    
    // 移动到要插入位置的前一个结点
    node *current = head;
    for(int i = 0; i < n - 1; i++)
    {
        if(current->pd_next == nullptr)
        {
            cout << "Position out of range!" << endl;
            return;
        }
        current = current->pd_next;
    }

    /*creat new node
    node *nextnode = new node;
    nextnode->datadomain = d;
    nextnode->pd_next = current->pd_next;

    current->pd_next = nextnode;
}

int List_Find(node *head, int d)
{
    // 检查链表是否已创建
    if(head == nullptr)
    {
        cout << "List not defined!" << endl;
        return -1;
    }
    
    int index = 1;
    // 跳过头结点，从第一个数据结点开始
    node *current = head->pd_next;
    
    while(current != nullptr)
    {
        if(current->datadomain == d)
        {
            cout << "index:" << index << endl;
            return index;
        }
        current = current->pd_next;
        index++;
    }
    cout << "Not Found!" << endl;
    return -1;
}

void List_Delete(node *head, int n)
{
    // 检查链表是否已创建
    if(head == nullptr)
    {
        cout << "List not defined!" << endl;
        return;
    }
    
    // 检查链表是否为空
    if(head->pd_next == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    
    // 检查位置是否有效（位置从1开始）
    if(n < 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    
    // 移动到要删除结点的前一个结点
    node *prev = head;
    for(int i = 0; i < n - 1; i++)
    {
        if(prev->pd_next == nullptr)
        {
            cout << "Position out of range!" << endl;
            return;
        }
        prev = prev->pd_next;
    }
    
    // 检查要删除的结点是否存在
    if(prev->pd_next == nullptr)
    {
        cout << "Position out of range!" << endl;
        return;
    }
    
    // 保存要删除的结点
    node *temp = prev->pd_next;
    
    // 将前一个结点的指针指向要删除结点的下一个结点
    prev->pd_next = temp->pd_next;
    
    // 释放要删除结点的内存
    delete temp;
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
                if(head != nullptr)
                {
                    add(head, data);
                }
                else
                {
                    cout << "List not defined!" << endl;
                }
                break;
            }

            case 'C':
            {
                int n;
                cin >> n;
                if(head != nullptr)
                {
                    for(int i = 0; i < n; i++)
                    {
                        int data;
                        cin >> data;
                        add(head, data);
                    }
                }
                else
                {
                    cout << "List not defined!" << endl;
                }
                break;
            }

            case 'P': 
                tranverse_output(head);
                break;

            case 'N':
            {
                int n, d;
                cin >> n >> d;
                List_Insert(head, n, d);
                break;
            }

            case 'F':
            {
                int d;
                cin >> d;
                List_Find(head, d);
                break;
            }
            
            case 'D':
            {
                int n;
                cin >> n;
                List_Delete(head, n);
                break;
            }
            
            default:
                break;
        }
    }

    return 0;
}*/