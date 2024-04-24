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
    Node *newnode = new Node;
    newnode->data = value;
    if(pos==1)
    {
         newnode->next = *head_ptr;
        *head_ptr   = newnode;
         return;
    }
    newnode->next = *head_ptr;

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
        cout<<"Empty List";
        return;
    }
    cout<<"\nElements in the List : ";
    while(itr!=NULL)
    {
        cout<<itr->data<<"\t";
        itr = itr->next;
    }
}

void length(Node *head_ptr)
{
    int ct=1;
    while(head_ptr->next!=NULL){
        ct++;
        head_ptr = head_ptr->next;
    }
    cout<<"\nNo. of items in list is : "<<ct<<endl;
}

int search(Node *head,int value)
{
    int pos=1;
    while(head->data!=value)
    {
        head = head->next;
        pos++;
        if(head->next ==nullptr)
        {

            return head->data==value?pos:0;
        }
    }
    return pos;
}

int value()
{
    int value;
    cout <<endl<< "Enter value to be insert : ";
    cin >> value;
    return value;

}

/*void Delete(Node** head_ptr,int pos)
{
    if(*head_ptr==NULL)
        cout<<"List is empty"<<endl;
    
    if(pos==1)
    {
        Node *temp=head_ptr;
        *temp = (*head_ptr)->next;
        delete *head_ptr;
        return;
    }

    Node *temp=*head;
    while(pos!=1)
    {
        temp = temp->next;
        pos--;
    }
    Node *temp1 = *temp;
    *temp = *(*temp->next)->next;

    delete *temp1;


}*/
void Delete(Node** head_ptr, int pos)
{
    if (*head_ptr == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (pos == 1)
    {
        Node* temp = *head_ptr;
        *head_ptr = (*head_ptr)->next;
        delete temp;
        return;
    }

    Node* current = *head_ptr;
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
        push_front(&head,val);
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
        length(head);
        break;
    }

    case 6:
    {
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

    
    }
    char ch;
    cout<<"\nDo you want to continue : (y/n):";
    cin >> ch;
    if(ch=='y')
        goto label;
    else
        cout<<endl<<":)";

}