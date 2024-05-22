#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node():data(0),left(nullptr),right(nullptr){}
    Node(int vl):data(vl),left(nullptr),right(nullptr){}
};
 Node *Root = nullptr;

Node* Minimum(Node* root)
{
    if(!root->left)
        return root;

    return Minimum(root->left);   
}
Node* Maximum(Node* root)
{
    if(!root->right)
        return root;

    return Maximum(root->right); 
}
int height(Node *Root)
{
    if(!Root)
        return -1;
    
    else
    {
        int lh = 1+height(Root->left);
        int rh = 1+height(Root->right);
        return max(lh,rh);
    }
}
int MinDepth(Node *Root)
{
    if(!Root)
        return 0;
    
    else
    {
        int ld = 1 + MinDepth(Root->left);
        int rd = 1 + MinDepth(Root->right);
        return min(ld,rd);
    }
}
bool is_Balanced(Node *root)
{
    if(!root)
        return 1;
    
    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1&&is_Balanced(root->left)&&is_Balanced(root->right))
        return 1;

    return 0;
}
Node* Insert(Node* root,int vl)
{
    if(!root)
        root= new Node(vl);
    else if(vl<root->data)
        root->left = Insert(root->left,vl);
    else
        root->right = Insert(root->right,vl);

    return root;
}
Node* InorderSuccessor(Node* Root)
{
    if(Root->left)
    {
        return InorderSuccessor(Root->left);
    }
    return Root;
}
Node* delete_node(Node* root,int vl)
{
    if(!root)
        return root;
    
    if(vl<root->data)
    {   
        root->left = delete_node(root->left,vl);
        return root;
    }
    else if(vl > root->data)
    {
        root->right = delete_node(root->right,vl);
        return root;
    }

    if(root->left==NULL)
    {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    if(root->right==NULL)
    {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    Node* successor = root->right;
    Node* successor_prt = root;
    while(successor->left!=NULL)
    {
        successor_prt= successor;
        successor = successor->left;
    }
    root->data = successor->data;
    
    if(successor_prt->left==successor)
        successor_prt->left = nullptr;
    else if(successor_prt->right==successor)
        successor_prt->right = nullptr;
    
    delete successor;
    return root;
}
Node* Search(int data,Node* root)
{
    if(!root){
        return NULL;
    }
    if(root->data==data)
        return root;
    else if(root->data<data)
        return Search(data,root->right);
    else 
        return Search(data,root->left);
}
void Traversal(Node *root)//inorder traversal
{
    if(root!=NULL){
    Traversal(root->left);
    printf("%d ",root->data);
    Traversal(root->right);}
    return;
}
void value(int &n)
{
    cout<<"\nenter vl:";
    cin>>n;
}
int main()
{
        int vl;
        value(vl);
        Root = Insert(Root,vl);
        value(vl);
        Insert(Root,vl);
        value(vl);
        Insert(Root,vl);
        value(vl);
        Insert(Root,vl);
        value(vl);
        Insert(Root,vl);
       
        cout<<"U R tree : ";
        Traversal(Root);
       cout<<"\nMin :"<<Minimum(Root)->data;
        cout<<"\nMAx :"<<Maximum(Root)->data;
        cout<<"\nHEIGHT IS "<<height(Root);
        cout<<"\nMin Depth : "<<MinDepth(Root);
        cout<<"\nIs Balanced : "<<is_Balanced(Root);
        value(vl);
        Root = delete_node(Root,vl);
        cout<<"U R tree : ";
        Traversal(Root);


        
}