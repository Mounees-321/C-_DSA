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
/*Node *Insert(Node* root , int vl)
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
    return 0;
}*/

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
Node* InorderSuccessor(Node* Root)
{
    if(Root->left)
    {
        return InorderSuccessor(Root->left);
    }
    return Root;
}
/*void Delete(int data)
{
    Node* MyNode = Search(data, Root);
    if (!MyNode)
    {
        cout << "Element not found";
        return;
    }
    Node* Parent = MyNode->prt;

    if (!MyNode->left && !MyNode->right)
    {
        if(!Parent){
            Root = nullptr;
            return;
        }
        (Parent->left == MyNode) ? (Parent->left = nullptr) : (Parent->right = nullptr);
        delete MyNode;
    }
    else if (MyNode->left == nullptr && MyNode->right != nullptr)
    {
        if(!Parent)
        {
            Root = MyNode->right;
        }
        (Parent->left == MyNode) ? (Parent->left = MyNode->right) : (Parent->right = MyNode->right);
        delete MyNode;
    }
    else if (MyNode->right == nullptr && MyNode->left != nullptr)
    {
        if(!Parent)
        {
            Root = MyNode->right;
        }
        (Parent->left == MyNode) ? (Parent->left = MyNode->left) : (Parent->right = MyNode->left);
        delete MyNode;
    }
    else
    {
        Node* successor = InorderSuccessor(MyNode->right);
        MyNode->data = successor->data;
        Node* successorPrt = successor->prt;
        (successorPrt->left == successor) ? (successorPrt->left = successor->right) : (successorPrt->right = successor->right);
        delete successor;
    }
}*/



void Traversal(Node *root)//inorder traversal
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
       /* cout<<"\nMin :"<<Minimum(Root)->data;
        cout<<"\nMAx :"<<Maximum(Root)->data;
        cout<<"hEIGHT IS "<<height(Root);
        cout<<"Min Depth : "<<MinDepth(Root);
        cout<<"Is Balanced : "<<is_Balanced(Root);
        value(vl);
        Delete(vl);
        cout<<"U R tree : ";
        Traversal(Root);*/


        
}