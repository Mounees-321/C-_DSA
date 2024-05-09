#include<iostream>
using namespace std;
class MyCircularQueue {
    int *arr;
    int capacity, size;
    int front, rear;

public:
    MyCircularQueue(int k) {
        arr = new int[k];
        capacity = k;
        front = rear = -1;
        size = 0;
    }

    ~MyCircularQueue() {
        delete[] arr;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            if (front == -1)
                front = rear;
            size++;
            return true;
        }
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        else {
            front = (front + 1) % capacity;
            size--;
            if (size == 0)
                front = rear = -1;   
            return true;
        }
    }


    int Front() {
        return isEmpty() ? -1 : arr[front];
    }

    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    int index = front;
    cout << "Circular Queue elements: ";
    do {
        cout << arr[index] << " ";
        index = (index + 1) % capacity;
    } while (index != (rear + 1) % capacity);
    cout << endl;
}
};

int main(){
    int k;
    cout<<"Enter n : ";
    cin>>k;
    MyCircularQueue circularQueue(k);
    
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
                if (circularQueue.enQueue(value))
                    cout << "Enqueued successfully." << endl;
                else
                    cout << "Queue is full. Enqueue failed." << endl;
                break;
            }
            case 2: {
                if (circularQueue.deQueue())
                    cout << "Dequeued successfully." << endl;
                else
                    cout << "Queue is empty. Dequeue failed." << endl;
                break;
            }
            case 3:
                cout << "Front element: " << circularQueue.Front() << endl;
                break;
            case 4:
                cout << "Rear element: " << circularQueue.Rear() << endl;
                break;
            case 5:
                cout << (circularQueue.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 6:
                cout << (circularQueue.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 7:
                circularQueue.display();
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    } while (choice != 8);

    return 0;
}


