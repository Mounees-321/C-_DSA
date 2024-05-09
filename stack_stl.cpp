#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class Stack {
    stack<T> newstack;
    int max_size = 10;

public:
    void push(T data) {
        if (newstack.size() == max_size) {
            cout << "\nStack is full" << endl;
            abort();
        } 
        else {
            newstack.push(data);
        }
    }

    T pop() {
        if (newstack.empty()) {
            cout << "\nStack Underflows" << endl;
            abort();
        } 
        else {
            T val = top();
            newstack.pop();
            return val;
        }
    }

    T top() {
        return newstack.top();
    }

    int size() {
        return newstack.size();
    }

    bool isempty() {
        return newstack.empty();
    }

    bool isfull() {
        return newstack.size() == max_size;
    }
};

int main() {
    Stack<int> mystack;
    int inp, val;

    while (true) {
        cout << "\nWhat do you want to do with the stack: ";
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Is Empty" << endl;
        cout << "5. Is Full" << endl;
        cout << "6. Size" << endl;
        cout << "\nEnter choice: ";
        cin >> inp;

        switch (inp) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                mystack.push(val);
                break;
            case 2:
                cout << "\nPopped value: " << mystack.pop();
                break;
            case 3:
                if (!mystack.isempty())
                    cout << "\nTop: " << mystack.top();
                break;
            case 4:
                mystack.isempty() ? cout << "\nYeah! It's an Empty Stack" : cout << "\nNot Empty Stack";
                break;
            case 5:
                mystack.isfull() ? cout << "\nYeah! It's a Full Stack" : cout << "\nNot Full Stack";
                break;
            case 6:
                cout << "Size: " << mystack.size();
                break;
            default:
                cout << "Wrong entry";
                break;
        }

        char ch;
        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;
        if (ch != 'y') {
            cout << "\n:)";
            break;
        }
    }

    return 0;
}
