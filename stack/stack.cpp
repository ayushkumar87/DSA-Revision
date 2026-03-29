#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>s;
    s.push(4);
    s.push(14);
    s.push(42);
    s.pop();
    cout<<s.top();
    return 0;
}