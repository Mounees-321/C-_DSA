#include<iostream>
#include<queue>
using namespace std;
struct  Node
{
    int data;
    Node *left;
    Node *right;
    
    Node():data(0),left(nullptr),right(nullptr){}
    Node(int vl):data(vl),left(nullptr),right(nullptr){}
};

Node* Insert(Node* root,int vl)//Level Order Insert
{
    if(!root)
    {
        root = new Node(vl);
        return root;
    }
    queue<Node*> Myqueue;
    Node *temp;
    Myqueue.push(root);
    while(!Myqueue.empty())
    {
        temp = Myqueue.front();
        Myqueue.pop();
        if(!temp->left)
        {
            temp->left = new Node(vl);
            return 0;
        }
        else
        {
            Myqueue.push(temp->left);
        }
        
        if(!temp->right)
        {
            temp->right = new Node(vl);
            return 0;
        } 
        else
        {
            Myqueue.push(temp->right);
        }

    }
}

void Traversal(Node *root)//Preorder traversal
{
    if(root){
    printf("%d ",root->data);
    Traversal(root->left);
    Traversal(root->right);}
}

int Max_tree(Node *root)
{
    if(root)
    {
        int first = root->data;
        int second = Max_tree(root->left);
        int third = Max_tree(root->right);
        int maxm = max(second,third);
        maxm = max(maxm,first);
        return maxm;
    }
    return 0;
    
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
        cout<<Max_tree(Root);

        
}