#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Stack {
public:
    int precedence(char ch) {
        if (ch == '^')
            return 4;
        else if (ch == '*' || ch == '/' || ch == '%')
            return 3;
        else if (ch == '+' || ch == '-')
            return 2;
        else
            return 1;
    }

    string infix_to_postfix(string my_exp) {
        string res;
        stack<char> opr;
        for (char ch : my_exp) {
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                res += ch;
            } else if (ch == '(') {
                opr.push(ch);
            } else if (ch == ')') {
                while (!opr.empty() && opr.top() != '(') {
                    res += opr.top();
                    opr.pop();
                }
                opr.pop() ;
            } else {
                while (!opr.empty() && precedence(ch) <= precedence(opr.top())) {
                    if (opr.top() != '(' && opr.top() != ')') {
                        res += opr.top();
                    }
                    opr.pop();
                }
                opr.push(ch);
            }
        }
        while (!opr.empty()) {
            res += opr.top();
            opr.pop();
        }
        return res;
    }
};

int main() {
    string express = "a+b*(c^d-e)^(f+g*h)-i";
    Stack Convert;
    cout << Convert.infix_to_postfix(express);

    return 0;
}
