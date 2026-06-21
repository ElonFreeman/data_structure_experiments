#include <stdio.h>  
#include <stdlib.h> 

typedef struct node {  
    int data;  
    struct node *next;  
}Node;  

// 创建链表函数（根据题目隐含要求，需要补充）
Node* CreatList()
{
    int n, data;
    Node *phead = (Node*)malloc(sizeof(Node));
    phead->next = NULL;
    Node *ptail = phead;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        Node *pnew = (Node*)malloc(sizeof(Node));
        pnew->data = data;
        pnew->next = NULL;
        ptail->next = pnew;
        ptail = pnew;
    }
    return phead;
}

// 单链表逆置函数
/********** Begin *********/  
void converse(Node *phead)
{
    if(phead == NULL || phead->next == NULL)
        return;
    
    Node *current = phead->next;  // 当前要处理的节点（从首元结点开始）
    Node *nextTemp = NULL;         // 保存下一个节点的临时指针
    
    phead->next = NULL;            // 头结点指针域置空，作为新链表的头
    
    while(current != NULL)
    {
        nextTemp = current->next;  // 保存原链表的下一个节点
        current->next = phead->next;  // 将当前节点插入到头结点之后
        phead->next = current;     // 头结点指向当前节点（完成插入）
        current = nextTemp;        // 移动到下一个待处理节点
    }
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