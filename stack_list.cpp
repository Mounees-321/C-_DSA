#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node():data(0),next(nullptr){};
    Node(int value):data(value),next(nullptr){};
};

class Stack
{
    Node *top;
    const int MAX =20;
    int size;

public:
    Stack():top(nullptr),size(0){};

    void push(int value)
    {
        if(isfull())
        {
            cout<<"Stack Overflows";
            abort();
        }
        Node *newnode = new Node(value);
        size++;
        if(top==NULL)
        {
            newnode->next = nullptr;
            top = newnode;
        }
        else{
            newnode->next = top;
            top = newnode;
        }
    }
    
    int pop()
    {
        if(isempty())
        {           
            cout<<"Stack Underflows";
            abort();
        }
        
            size--;
            Node *temp = top;
            top = top->next;
            int vl = temp->data;
            delete temp;
            return vl;
            
    }

    int up()
    {
        if(isempty())
        {
            cout<<"Empty Stack";
        }
        return top->data;
    }
    int length(){return size;}

    bool isempty(){return top==NULL;}

    bool isfull(){return MAX==size;}
};
int value()
{
    int val;
    cout<<"Enter value : ";
    cin >> val;
    return val;
}
int main()
{
    Stack mystack;
    int inp,val;

    label:
    cout<<"\nWhat do you want to do with the stack : ";
    cout<<"\n1.push"<<endl;
    cout<<"2.pop"<<endl;
    cout<<"3.top"<<endl;
    cout<<"4.isempty"<<endl;
    cout<<"5.isfull"<<endl;
    cout<<"6.size"<<endl;
    cout<<"\nEnter choice : ";
    cin >> inp;

    switch ((inp))
    {
    case 1:
        val = value();
        mystack.push(val);
        break;
    case 2:
        cout<<"\nPopped value : "<<mystack.pop();
        break;
    case 3:
        cout<<"\nTop : "<<mystack.up();
        break;
    case 4:
        mystack.isempty()?cout<<"\nYeah ! It's Empty Stack":cout<<"\nNot Empty Stack";
        break;
    case 5:
        mystack.isfull()?cout<<"\nYeah ! It's Stack Full":cout<<"\nNot  Stack Full";
        break;
    case 6:
        cout<<"Size : "<<mystack.length();
        break;
    default:
        cout<<"Wrong entry";
    }
    char ch;
    cout<<"\nDo you want to continue(y/n) : ";
    cin >> ch;
    if (ch == 'y') {
    goto label;
    } 
    else {
        cout << "\n:)";
    }
}
