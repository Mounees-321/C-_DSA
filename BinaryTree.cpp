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

Node* Root = nullptr;

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
Node* search(int data,Node *root)//level order
{
    if(!root)
        return nullptr;
    queue<Node*> MyQueue;
    Node* temp;
    MyQueue.push(root);
    while(!MyQueue.empty())
    {
        temp = MyQueue.front();
        MyQueue.pop();
        if(temp->data==data)
            return temp;
        if(temp->left)
            MyQueue.push(temp->left);
        if(temp->right)
            MyQueue.push(temp->right);
    }
    return nullptr;
}

int minDepth(Node* Root){
     if(!Root)
        return 0;
    
    else
    {
        int ld = 1 + minDepth(Root->left);
        int rd = 1 + minDepth(Root->right);
        return min(ld,rd);
    }}
void Traversal(Node *root)//level order
{
    queue<Node*> MyQueue;
    Node* temp;
    MyQueue.push(root);
    while(!MyQueue.empty())
    {
        temp = MyQueue.front();
        MyQueue.pop();
        cout<<temp->data<<" ";
        if(temp->left)
            MyQueue.push(temp->left);
        if(temp->right)
            MyQueue.push(temp->right);
        
    }
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
        cout<<minDepth(Root);
        
}