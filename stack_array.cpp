//Stack by array (static) method
#include<iostream>
#include<stack>
#include<algorithm>
#define max 20

using namespace std;
class Stack
{
    int top=-1;
    int arr[max];
    
public:

    void push(int val)
    {
        if(top==max)
        {
            cout<<endl<<"Stack Overflows";
            abort;
        }
        arr[++top] = val;
    }

    int pop()
    {
        if(top==-1)
        {
            cout<<endl<<"Stack underflows";
            abort();
        }
        cout<< top;
        return arr[top--];
    }

    int size()
    {
        return top+1;
    }

    bool isempty()
    {
        return top==-1;
    }

    int up()
    {
        return arr[top];
    }

    int isfull()
    {
        return top==max-1;
    }
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
    //push,pop,top,size,isempty,isfull
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
        cout<<"Size : "<<mystack.size();
    default:
        break;
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

