#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,less<int>> ms;
    ms.push(1);
    ms.push(22);
    ms.push(3);
    while(!ms.empty())
    {cout<<ms.top();
    ms.pop();
    }

    
    
}