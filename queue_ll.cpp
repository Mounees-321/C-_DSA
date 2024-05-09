#include<iostream>
using namespace std;
struct Node
{
   int data;
   Node *next;
   Node():data(0),next(nullptr){}
};

class Queue
{
    Node *head,*tail;
    int data;
    int capacity,count;
public:

    Queue(int n):head(nullptr),tail(nullptr),data(0),count(0),capacity(n){}

    void enqueue(int value)
    {
        if (isfull())
        {
            cout<<"\nQueue full"<<endl;
            return;
        }
         Node *newnode = new Node;
        newnode->data = value;
        newnode->next = nullptr;
        if(head==nullptr)
        {
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        count++;
    }

    void dequeue()
    {
        if(isempty())
        {
            cout<<"Empty Queue\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        count--;
    }
    bool isfull()
    {
        return count == capacity;
    }
    bool isempty()
    {
        return count == 0;
    }
    int front(){return head->data;}

    int rear(){return tail->data;}

    int size(){return count;}
    void display()
    {
        if(isempty())
        {
            cout<<"Empty Queue";
            return;
        }
        Node *temp = head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
    }
};

    int main()
    {
        int k;
        cout<<"Enter n : ";
        cin>>k;
        Queue Q(k);
        int choice;
        do {
            cout << "1. Enqueue" << endl;
            cout << "2. Dequeue" << endl;
            cout << "3. Front" << endl;
            cout << "4. Rear" << endl;
            cout << "5. Is Empty?" << endl;
            cout << "6. Is Full?" << endl;
            cout << "7. Display" << endl;
            cout << "8. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int value;
                    cout << "Enter the value to enqueue: ";
                    cin >> value;
                    Q.enqueue(value);
                    break;
                }
                case 2: {
                    Q.dequeue();
                    break;
                }
                case 3:
                    cout << "Front element: " << Q.front() << endl;
                    break;
                case 4:
                    cout << "Rear element: " << Q.rear() << endl;
                    break;
                case 5:
                    cout << (Q.isempty() ? "Queue is empty." : "Queue is not empty.") << endl;
                    break;
                case 6:
                    cout << (Q.isfull() ? "Queue is full." : "Queue is not full.") << endl;
                    break;
                case 7:
                    Q.display();
                    break;
                case 8:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid choice." << endl;
            }
        }
         while (choice != 8);

        return 0;
    }