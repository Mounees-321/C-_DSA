#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node():data(0),next(nullptr){}
};

void push_front(Node** head_ptr,int value)
{
    Node *newnode = new Node;
    newnode->data = value;
    newnode->next = *head_ptr;
    *head_ptr   = newnode;
}

void insert(Node** head_ptr,int value,int pos)
{
    if(*head_ptr==NULL && pos>1)
    {
        cout<<"wrong entry ";
        return;
    }
   
    else if(pos==1)
    {
        push_front(head_ptr,value);
    }
    Node *newnode = new Node;
    newnode->data = value;
    Node *temp = *head_ptr;
    pos--;
    while(pos!=1)
    {
        temp = temp->next;
        pos--;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}

void push_back(Node** head_ptr,int value)
{
    Node *newnode = new Node;
    newnode->data = value;
    newnode->next = nullptr;
    if(*head_ptr==NULL)
    {
        *head_ptr = newnode;
    }
    else
    {
        Node* temp = *head_ptr;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }    
        temp->next = newnode;
    }
}
void show(Node *itr)
{
    if(itr==NULL){
        cout<<"\nOops!,It's Empty List";
    }

    else{
    while(itr!=NULL)
    {
        cout<<itr->data<<"\t";
        itr = itr->next;
    }}
}

int length(Node *head_ptr)
{
    int ct=0;
    while(head_ptr!=NULL){
        ct++;
        head_ptr = head_ptr->next;
    }
    return ct;
}

int search(Node *head,int value)
{
    int pos=0;
    while(head!=NULL&&head->data!=value)
    {
        head = head->next;
        pos++;
    }
    if(head==NULL)
        return 0;
    return pos;
}

int value()
{
    int value;
    cout <<endl<< "Enter value to be insert : ";
    cin >> value;
    return value;

}

void Delete(Node** head_ptr, int pos)
{
    if(*head_ptr == nullptr){
        cout << "List is empty" << endl;
        return;
    }

    Node* current = *head_ptr;
    if (pos == 1)
    {
        *head_ptr = (*head_ptr)->next;
        delete current;
        return;
    }

    for (int i = 1; current != nullptr && i < pos - 1; i++)
    {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr)
    {
        cout << "Position out of range" << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void reverse(Node **head)
{
  Node* temp = *head;
  Node *prev_temp = nullptr,*temp2;
  while(temp!=nullptr)
  {
    temp2 = temp->next;
    temp->next = prev_temp;
    prev_temp = temp;
    temp = temp2;
  }
  *head = prev_temp;
}

Node *pos_reverse(Node *head, int k)
    {
        int p = k;
        Node *temp = head , *new_head , *temp1,*prev_temp = nullptr;
        while(p!=0)
        {
            temp1 = temp->next;
            temp->next = prev_temp;
            prev_temp = temp;
            temp = temp1;
            p--;
        }
        temp = temp1;
        new_head = prev_temp;
        prev_temp = nullptr;
        while(temp!=NULL)
        {
            temp1 = temp->next;
            temp->next = prev_temp;
            prev_temp = temp;
            temp = temp1;
        }
        
        head->next = prev_temp;
        return new_head;
        
        }
    

int main()
{
    Node *head = nullptr;
    int val,pos,input;

    label:
    cout<<"What do you want to do with list: "<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Push_front"<<endl;
    cout<<"3.Push_back"<<endl;
    cout<<"4.Search"<<endl;
    cout<<"5.length"<<endl;
    cout<<"6.Show"<<endl;
    cout<<"7.Delete"<<endl;
    cout<<"8.Reverse"<<endl;
    cout<<"9.pos_reverse"<<endl;
    cin >> input;

    switch(input){
    case 1:
    {
        cout<<endl<<"Enter pos : ";
        cin >> pos;
        val = value();
        insert(&head,val,pos); 
        break;   
    }

    case 2:
    {
        val = value();
        push_front(&head,val);
        break;
    }

    case 3:
    {
        val = value();
        push_back(&head,val);
        break;
    }

    case 4:
    {
        cout<<"Enter value to be search : ";
        cin >> val;
        int k= search(head,val);
        k?(cout<<"\nElement found at : "<<k):cout<<"\nnot found";
        break;
    }

    case 5:
    {
        cout<<"\nNo. of items in list is : "<<length(head)<<endl;
        break;
    }

    case 6:
    {
        cout<<"\nElements in the List : ";
        show(head);
        break;
    }
    
    case 7:
    {
        cout<<"Enter position to be delete : ";
        cin >> pos;
        Delete(&head,pos);
       break;

    }
    case 8:
    {
        reverse(&head);
        break;
    }
    case 9:
    {
        int k;
        cout<<"Enter k : ";
        cin >> k;
        head = pos_reverse(head,k);
        break;
    }
    default :
        cout<<"wrong entry";
    }
    char ch;
    cout<<"\nDo you want to continue : (y/n):";
    cin >> ch;
    if(ch=='y')
        goto label;
    else
        cout<<endl<<":)";

}
