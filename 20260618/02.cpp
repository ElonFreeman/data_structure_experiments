#include<bits/stdc++.h>
using namespace std;

struct BST_node
{
    int data;
    BST_node *leftchild,*rightchild;
};

void insert_BST(BST_node **root,int value)
{
    if(*root==nullptr)
    {
        BST_node *newnode=new BST_node;
        newnode->data=value; newnode->leftchild=nullptr,newnode->rightchild=nullptr;
        *root=newnode;
    }
    else if(value > (*root)->data)
    {
        insert_BST(&((*root)->rightchild),value);
    }
    else if(value < (*root)->data)
    {
        insert_BST(&((*root)->leftchild),value);
    }
}

void inorder(BST_node *root)
{
    if(root==nullptr){return;}

    inorder(root->leftchild);
    cout << root->data << ' ';
    inorder(root->rightchild);
}

int main(void)
{
    int num_data; cin >> num_data;
    vector<int> dataset;
    for(int i=0;i<num_data;i++){int value; cin >> value; dataset.push_back(value);}

    /*generate BST*/
    BST_node *root=nullptr;
    for(int i=0;i<num_data;i++)
    {
        insert_BST(&root,dataset[i]);
    }

    /*inorder traverse*/
    inorder(root); cout << endl;

    return 0;
}