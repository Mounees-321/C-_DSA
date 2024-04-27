#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node():data(0),prev(nullptr),next(nullptr){};
};

int length(Node *head_ptr)
{
    int ct=0;
    while(head_ptr!=NULL){
        ct++;
        head_ptr = head_ptr->next;
    }
    return ct;
}

void push_front(Node** head_ptr,Node** tail_ptr,int value)
{
    Node *newnode = new Node;
    newnode -> data = value;
    newnode -> prev =nullptr;
    newnode->next = *head_ptr;

    if(*head_ptr==NULL){
        *tail_ptr = newnode;
        *head_ptr = newnode;}
    
    else{
    (*head_ptr)->prev = newnode;
    *head_ptr = newnode;
    }
}

void push_back(Node** head_ptr, Node** tail_ptr, int value) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;
    new_node->prev = *tail_ptr;

    if (*head_ptr == nullptr) {
        *head_ptr = new_node;
        *tail_ptr = new_node; }
    
    else {
        (*tail_ptr)->next = new_node;
        *tail_ptr = new_node; }  
}

void fw_insert(Node** head_ptr,int pos,int vl)
{
    Node *newnode = new Node;
    newnode->data = vl;
    Node *temp = *head_ptr;
    pos--;
    while(pos!=1)
    {
        temp = temp->next;
        pos--;
    }
    Node *temp2 = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = temp2;
    temp2->prev = newnode;
}
void bw_insert(Node **tail_ptr,int pos,int vl)
{
    Node *new_node = new Node;
    new_node -> data = vl;
    
    Node* temp = *tail_ptr;
    while(pos!=1)
    {
        temp = temp->prev;
        pos--;
    }
    Node *temp2 = temp->prev;
    temp2->next = new_node;
    new_node->next = temp;
    new_node->prev = temp2;
    temp->prev = new_node;

}

void insert(Node** head_ptr,Node** tail_ptr,int pos,int value)
{
    if(*head_ptr==nullptr||pos==1)
    {
        push_front(head_ptr,tail_ptr,value);
        return;
    }
    int len = length(*head_ptr);
    if(pos==len+1)
    {
        push_back(head_ptr,tail_ptr,value);
    }
    else if(pos<=len/2)
    {
        fw_insert(head_ptr,pos,value);
    }
    else
    {
        bw_insert(tail_ptr,len-pos+1,value);
    }
}


int value()
{
    int value;
    cout <<endl<< "Enter value to be insert : ";
    cin >> value;
    return value;
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

bool emptylist(Node* temp)
{
    if(temp==NULL){
        cout<<"Empty List";
        return 1;
    }
    return 0;
        

}
void forward_trv_show(Node* itr)
{
    if(emptylist(itr))
        return;

    while(itr!=NULL)
    {
        cout<<itr->data<<"\t";
        itr = itr->next;
    }
}

void backward_show(Node* itr)
{
    if(emptylist(itr))
        return;
   
    while(itr!=nullptr){
        cout << itr->data << "\t";
        itr = itr->prev;    
    }  
}

void Delete(Node** head_ptr, int pos,Node **tail_ptr)
{
   if(emptylist(*head_ptr))
        return;

    if (pos == 1)
    {
        Node* temp =*head_ptr;
        *head_ptr = (*head_ptr)->next;
        if(*head_ptr==NULL)
            return;
        (*head_ptr)->prev = nullptr;
        delete temp;
        return;
    }

    if(pos==length(*head_ptr))
    {
        Node* temp = *tail_ptr;
        *tail_ptr = (*tail_ptr)->prev;
        (*tail_ptr)->next = nullptr;
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
    Node *Head = nullptr;
    Node *Tail = nullptr;
    int val;
     int pos,input;

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
        insert(&Head,&Tail,pos,val);
        break;   
    }

    case 2:
    {
        val = value();
        push_front(&Head,&Tail,val);
        break;
    }

    case 3:
    {
        val = value();
        push_back(&Head,&Tail,val);    
        break;
    }

    case 4:
    {
        cout<<"Enter value to be search : ";
        cin >> val;
        int k= search(Head,val);
        k?(cout<<"\nElement found at : "<<k):cout<<"\nnot found";
        break;
    }

    case 5:
    {
        cout<<"\n Length of the list is : "<<length(Head);
        break;
    }

    case 6:
    {
        cout<<"\nElements in your lists are : ";
         forward_trv_show(Head);
        break;
    }
    
    case 7:
    {
        cout<<"\nEnter position to be delete : ";
        cin >> pos;
        Delete(&Head,pos,&Tail);
       break;
    }
    default:
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
