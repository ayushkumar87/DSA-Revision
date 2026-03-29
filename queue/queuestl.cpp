#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>q;
    q.push(5);
    q.push(8);
    q.push(9);
    q.pop();
    cout<<q.front()<<" ";
    cout<<q.back()<<" ";
    cout<<q.empty()<<" ";
    cout<<q.size()<<" "; 
}
