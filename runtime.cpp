#include<iostream>
#include<chrono>
using namespace std;
auto start = chrono::steady_clock::now();
int main()
{
    /* Code to be write*/
    auto end = chrono::steady_clock::now();
    auto diff = end-start;
    cout<<chrono::duration<double,milli>(diff).count()<<"ms";

}