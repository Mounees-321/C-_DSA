#include<iostream>
#include<stack>
using namespace std;

struct term {
    int coeff;
    int expo;
    term(): coeff(0), expo(0) {}
};

void display(stack<term> p) {
    while(!p.empty()) {
        cout << p.top().coeff << "X^" << p.top().expo << "\t+\t";
        p.pop();
    }
}

stack<term> add(stack<term> p1, stack<term> p2) {
    stack<term> p;
    term temp;
    while(!p1.empty() || !p2.empty()) {
        if(p1.top().expo > p2.top().expo) {
            p.push(p1.top());
            p1.pop();
        } else if(p2.top().expo > p1.top().expo) {
            p.push(p2.top());
            p2.pop();
        } else {
            temp.coeff = p1.top().coeff + p2.top().coeff;
            temp.expo = p1.top().expo;
            p.push(temp);
            p1.pop();
            p2.pop();
        }
    }

    return p;    
}

int main() {
    stack<term> p1;
    stack<term> p2;
    term temp;
    char ch;

    cout << "\nEnter Polynomial 1 (from higher power to lower): ";
    do {
        cout << "Enter coeff and pow: ";
        cin >> temp.coeff >> temp.expo;
        p1.push(temp);
        cout << "Do you want to continue (y/n): ";
        cin >> ch;
    } while(ch != 'n');

    cout << "\nPolynomial 1: ";
    display(p1);

    cout << "\nEnter Polynomial 2: ";
    do {
        cout << "\nEnter coeff and pow: ";
        cin >> temp.coeff >> temp.expo;
        p2.push(temp);
        cout << "Do you want to continue (y/n): ";
        cin >> ch;
    } while(ch != 'n');

    cout << "\nPolynomial 2: ";
    display(p2);

    stack<term> p3 = add(p1, p2);

    cout << "\nResultant Polynomial: ";
    display(p3);

    return 0;
}
