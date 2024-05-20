#include<iostream>
#include<vector>
using namespace std;
struct  Node
{
    int data;
    Node *left;
    Node *right;
    
    Node():data(0),left(nullptr),right(nullptr){}
    Node(int vl):data(vl),left(nullptr),right(nullptr){}
};

class Tree
{
    Node *Root = nullptr;
    vector<Node*> Created;
    int n;
public:
    Tree(int n)
    {
        this->n = n;
        for(int i = 0; i<n; i++)
            Created.push_back(NULL);
    }

    void createNode(int arr[],int i)
    {
        if(Created[i]!=NULL)
            return;
            Node* newNode = newNode(i);
        if(arr[i]==-1)
            
        }
    }

`   void CreateTree(int arr[])
    {
        for(int i = 0; i<n ; i++)
        {
            if(arr[i]==-1)
            {
                Root = new Node(i);
            }
            int j = 0;
            Node *prt = new Node;
            for(int i = 0 ; i<n || j!=2;i++)
            {
                if(arr[i]==i)
                {
                    Node* newNode = new Node(i);
                    if(prt->left==NULL)
                        prt->left = newnode;
                    else
                        prt->right = newnode;
                    j++;
                }
            }
        }
    }
};

int main()
{
    int arr= {1,5,5,2,2,-1,3};


}