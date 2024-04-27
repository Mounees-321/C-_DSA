#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node() : data(0),next(nullptr){};
};

class List
{
    Node *Head;
    Node *Tail;

public:
    List(): Head(nullptr),Tail(nullptr){};

    void push_back(int value)
    {
        Node* new_node = new Node;
        new_node -> data = value;
        if(Head==NULL)
        {
            Head = new_node;
            Tail = new_node;
            Tail->next = Head;
            return;
        }
            new_node -> next =Head;
            Tail ->next  = new_node;
            Tail = new_node;   
    }

    void push_front(int value)
    {
        Node* new_node = new Node;
        new_node -> data = value;

        if(Head == NULL)
        {
            new_node -> next = new_node;
            Head = new_node;
            Tail = new_node;
            return;
        }
        new_node -> next = Head;
        Head = new_node;
        Tail -> next = Head;

    }

    void insert(int pos,int value)
    {
        if(pos==1){
            push_front(value);
            return;}
        else if(pos==length()+1)
            push_back(value);
        else
        {
            Node* new_node = new Node;
            new_node -> data = value;

            Node *temp = Head;
            int position = pos;
            pos--;
            while(pos!=1)
            {
                temp = temp->next ;
                pos--;
            }
            Node *temp2 = temp->next;
            new_node->next = temp2;
            temp->next = new_node;
            if(position==length())
            {
                Tail = temp2;
            }
        }
    }

    void show()
    {
        if(Head==NULL)
        {
            cout<<"Empty List"<<endl;
            return;
        }
        Node *temp = Head;
        cout<<"\n";
            do
            {
                cout<<temp->data<<" ";
                temp = temp->next;

                /*if(temp->next == Head)
                {
                    cout<<temp->data;
                    return;
                }  */
            }
            while(temp!=Head);      
            
    }

    int length()
    {
        if(Head==nullptr){
            return 0;
        }

        else{
            int ct=1;
            Node *temp = Head;

            while(temp->next!=Head)
            {
                 temp = temp ->next;
                 ct++;
            }
             return ct;
        }
    }

    int search(int value)
    {
    int pos=1;
    Node *temp = Head;
    while(temp->data!=value)
    {
        temp = temp->next;
        pos++;
        if(temp->next ==Head)
        {

            return temp->data==value?pos:0;
        }
    }
    return pos;
    }

    void Delete(int pos)
    {
        if(Head == nullptr)
         {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = Head;
        if(pos==1)
        {
            if(Head==Tail)
            {
                delete Head;
                Head = Tail = nullptr;
                return;
            }
            Head = Head->next;
            Tail->next = Head;
            
            delete temp;
            return;

        }

        int position = pos;
        pos--;
        while(pos!=1)
        {
            temp = temp->next;
            pos--;
        }

        Node *temp2 = temp->next;
        temp->next = temp2->next;

        if(position==length())
        {
            Tail = temp;
        }
        delete temp2;

    }
};
int value()
{
    int value;
    cout <<endl<< "Enter value to be insert : ";
    cin >> value;
    return value;

}

int main()
{
    List circluar_list;
    int val,input,pos;
    label:
    cout<<"What do you want to do with list: "<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Push_front"<<endl;
    cout<<"3.Push_back"<<endl;
    cout<<"4.Search"<<endl;
    cout<<"5.length"<<endl;
    cout<<"6.Show"<<endl;
    cout<<"7.Delete"<<endl;
    cin >> input;
    
    switch(input){
    case 1:
    {
        cout<<endl<<"Enter pos : ";
        cin >> pos;
        val = value();
        circluar_list.insert(pos,val);
        break;   
    }

    case 2:
    {
        val = value();
        circluar_list.push_front(val);
        
        break;
    }

    case 3:
    {
        val = value();
        circluar_list.push_back(val);
        break;
    }

    case 4:
    {
        cout<<"Enter value to be search : ";
        cin >> val;
        int k= circluar_list.search(val);
        k?(cout<<"\nElement found at : "<<k):cout<<"\nnot found";
        break;
    }

    case 5:
    {
        cout<<"\nNo. of items in list is : "<<circluar_list.length()<<endl;
        break;
    }

    case 6:
    {
        cout<<"\nElements in the List : ";
        circluar_list.show();
        break;
    }
    
    case 7:
    {
        cout<<"Enter position to be delete : ";
        cin >> pos;
        circluar_list.Delete(pos);
        break;

    }
    }
    char ch;
    cout<<"\nDo you want to continue : (y/n):";
    cin >> ch;
    if(ch=='y')
        goto label;
    else
        cout<<endl<<":)";

}
