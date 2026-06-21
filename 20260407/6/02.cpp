#include <bits/stdc++.h>
using namespace std;

typedef struct node {  

    int data;  

    struct node *next;  

}Node;  



// 请在此添加你的代码

/********** Begin *********/  
Node* CreatList()
{
    Node *head = new node;  // 创建头节点（不存储数据）
    head->next = nullptr;
    Node *current = head;    // current指向当前最后一个节点
    
    int leng; 
    cin >> leng;
    
    for(int i = 0; i < leng; i++)
    {
        Node *newnode = new node;
        int val;
        cin >> val;          // 直接读入，不需要先存数组
        newnode->data = val;
        newnode->next = nullptr;
        
        current->next = newnode;
        current = newnode;
    }
    
    return head;
}

/*Node* converse(Node *phead)
{
    node *prev=nullptr,*current=phead,*tmp=nullptr;

    while(current->next!=nullptr)
    {
        tmp=current->next;
        current->next=prev;
        prev=current;
        current=tmp;
    }
    return prev;
}*/
/*Node* converse(Node *phead)
{
    Node *prev = nullptr;
    Node *current = phead;
    Node *tmp = nullptr;
    
    while(current != nullptr)  // 修正1：遍历到current为null才停止
    {
        tmp = current->next;   // 保存下一个节点
        current->next = prev;  // 反转指向
        prev = current;        // 移动prev
        current = tmp;         // 移动current
    }
    return prev;  // 修正2：此时prev指向原尾节点（新头节点）
}*/

Node* converse(Node *phead)
{
    node *head1=phead->next,*newhead=nullptr;
    node *current1=head1,*newcurrent=nullptr;
    int flag=0;
    while(current1->next!=nullptr)
    {
        node *newnode=new node;
        newcurrent->next=newnode;
        newnode->data=current1->data;
        newnode->next=nullptr;
        if(flag==0)
        {
            newhead=newnode;
            flag=1;
        }
        newcurrent=newnode;
    }
    return newhead;
}

/**********  End  **********/  



//输出链表  

void ShowList(Node *phead)  

{  

    Node *p;  

   

    p = phead->next;  

    while(p)  

    {  

        printf("%d ", p->data);  

        p = p->next;  

    }  

    printf("\n");  

}      




int main(void)  

{  

    Node *phead;  

  

    phead = CreatList();  

    converse(phead);  

    printf("链表逆置后的数据:\n");  

    ShowList(phead);

    return 0;  

}   

