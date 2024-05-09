#include<iostream>
using namespace std;

struct Node
{
    int coeff, power;
    Node *next;
    Node() : coeff(0), power(0), next(nullptr) {}
};

class Polynomial
{
    Node *head;
    Node *tail;
    int size;

public:
    Polynomial() : head(nullptr), size(0) {}
    void create()
    {
        int n;
        cout << "\nEnter how many elements: ";
        cin >> n;
        size = n;
        for (int i = 0; i < n; i++)
        {
            Node *newnode = new Node;
            cout << "\nEnter Power term: ";
            cin >> newnode->power;
            cout << "Enter Coeff term: ";
            cin >> newnode->coeff;
            newnode->next = nullptr;
            if (head == nullptr)
            {
                head = newnode;
                tail = head;
            }
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
        }
    }

    void display()
    {
        cout << "Your Polynomial: ";
        Node *temp = head;
        cout << endl;
        while (temp != nullptr)
        {
            cout << temp->coeff << " X^" << temp->power << "\t"<<"+";
            temp = temp->next;
        }
        cout << endl;
    }

    void add(Polynomial p1, Polynomial p2)
    {
        Node *eq1 = p1.head;
        Node *eq2 = p2.head;

        while (eq1 != nullptr || eq2 != nullptr)
        {
            Node *newnode = new Node;
            if(eq1==NULL)
            {
                newnode->coeff = eq2->coeff;
                newnode->power = eq2->power;
                eq2 = eq2->next;
            }
            else if(eq2==NULL)
            {
                newnode->coeff = eq1->coeff;
                newnode->power = eq1->power;
                eq1 = eq1->next;
            }
            else if (eq1->power == eq2->power)
            {
                newnode->coeff = eq1->coeff + eq2->coeff;
                newnode->power = eq1->power;
                eq1 = eq1->next;
                eq2 = eq2->next;
            }
            else if (eq1->power > eq2->power)
            {
                newnode->coeff = eq1->coeff;
                newnode->power = eq1->power;
                eq1 = eq1->next;
            }
            else
            {
                newnode->coeff = eq2->coeff;
                newnode->power = eq2->power;
                eq2 = eq2->next;
            }

            newnode->next = nullptr;

            if (head == nullptr)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                tail = newnode;
            }
            size++;
        }
    }
};

int main()
{
    Polynomial p1, p2, p3;
    cout << "Enter details for Polynomial 1: ";
    p1.create();
    p1.display();
    cout << "Enter details for Polynomial 2: ";
    p2.create();
    p2.display();
    cout << "Adding Polynomials...\n";
    p3.add(p1, p2);
    p3.display();

    return 0;
}
