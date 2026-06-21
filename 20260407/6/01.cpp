#include <bits/stdc++.h>
using namespace std;

typedef struct node {

    int data;

    struct node *next;

}Node;



     // 请在此添加你的代码

    /********** Begin **********/
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

    ShowList(phead);

    return 0;  

}