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

Node *Insert(Node* root , int vl)
{
    Node* newnode = new Node(vl);
    Node *temp = root;
    Node *y = NULL;
    while(temp)
    {
        y = temp;
        if(vl < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    newnode->prt = y;
    if(!y)
        return newnode;

    if(vl<y->data)
        y->left = newnode;
    else
        y->right = newnode;
}

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

Node *Transplant(Node* root,Node* u,Node* v)
{
    if(u->prt==NULL)
    {
        root = v;
    }

}

Node* Delete(Node)
/*Node* Insert(Node* root,int vl)
{
    if(!root){
        root= new Node(vl);
    }
    else if(vl<root->data)
    {
        root->left = Insert(root->left,vl);
    }
    else
    {
        root->right = Insert(root->right,vl);

    }
    return root;
}*/

void Traversal(Node *root)//Preorder traversal
{
    if(root){
    Traversal(root->left);
    printf("%d ",root->data);
    Traversal(root->right);}
}
void value(int &n)
{
    cout<<"\nenter vl:";
    cin>>n;
}
int main()
{
        Node *Root = nullptr;
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
        value(vl);
        Insert(Root,vl);
        value(vl);
        Insert(Root,vl);
        value(vl);
        Insert(Root,vl);
        cout<<"U R tree : ";
        Traversal(Root);
        cout<<"\nMin :"<<Minimum(Root)->data;
        cout<<"MAx :"<<Maximum(Root)->data;
        Delete(Root,)

        
}