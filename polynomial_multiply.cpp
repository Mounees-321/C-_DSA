#include<iostream>
using namespace std;
struct  Node
{
    	int pow;
    	int co;
    	Node* NEXT;
};

class Polynomial
{
    Node *Head;
    Node *Tail;

public:
    Polynomial():Head(nullptr),Tail(nullptr){}
    void create(int n)
    {
        for(int i=0 ; i<n ; i++)
        {
            Node *newnode = new Node;
            cout<<"Enter pow and coeff  : ";
            cin >> newnode->pow >> newnode->co;
            newnode->NEXT = nullptr;
            if(Head==nullptr)
            {
                Head = newnode;
                Tail = newnode;
                continue;
            }
            Tail -> NEXT = newnode;
            Tail = newnode;
        }
    }

    void Display()
    {
        Node *temp = Head;
        while(temp!=NULL)
        {
            cout<<temp->co<<"X^"<<temp->pow<<"  +  ";
            temp = temp->NEXT;
        }
    }

    void multiply(Polynomial p1,Polynomial p2)
    {

         for(Node* temp_p1 = p1.Head;temp_p1!=nullptr;temp_p1=temp_p1->NEXT)
         {
            for(Node* temp_p2 = p2.Head;temp_p2!=nullptr;temp_p2=temp_p2->NEXT)
            {
                Node *newnode = new Node;
                if(temp_p1->co==0 || temp_p2->co ==0)
                {
                    newnode->co = 0;
                    newnode->pow = 0;
                }
                else{
                newnode->co = temp_p1->co*temp_p2->co;
                newnode->pow = temp_p1->pow+temp_p2->pow;
                newnode->NEXT = nullptr;}

                if(Head==nullptr)
                {
                    Head = newnode;
                    Tail = newnode;
                    continue;
                }
                Tail->NEXT = newnode;
                Tail = newnode;
            }
        }
    }
};

int main() {
    int n;
    Polynomial p1, p2;
    cout << "Enter how many terms in Polynomial 1: ";
    cin >> n;
    p1.create(n);
    cout << "\nEnter how many terms in Polynomial 2: ";
    cin >> n;
    p2.create(n);
    cout << "\nPOLYNOMIAL 1: ";
    p1.Display();
    cout << "\nPOLYNOMIAL 2: ";
    p2.Display();
    Polynomial p3 ;
    p3.multiply(p1,p2);
    cout<< "\n Polunomial 3 : ";
    p3.Display();


}