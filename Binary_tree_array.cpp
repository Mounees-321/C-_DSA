#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *prt;

    Node():data(0),left(nullptr),right(nullptr),prt(nullptr){}
    Node(int vl):data(vl),left(nullptr),right(nullptr){}
};
Node *root = nullptr;
void Create(int arr[],int n)
{
    Node* prt[10];
    for(int i = 0 ; i<n ;i++)
    {
        Node *temp = new Node(i);
        prt[i] = temp;
    }
    for(int i = 0 ; i<n ; i++)
    {
        if(arr[i]==-1){
            root = prt[i];
            continue;}
        
        Node* parent = prt[arr[i]],*child = prt[i];
        if(!parent->left)
            parent->left = child;
        else
            parent->right = child;
    }
}
void Traversal(Node *Root)//Preorder traversal
{
    
    if(Root){
    printf("%d ",Root->data);
    Traversal(Root->left);
    Traversal(Root->right);}
}


int main()
{
    int arr[]= {-1,0,0,1,1,3,5};
    Create(arr,7);
    Traversal(root);

}