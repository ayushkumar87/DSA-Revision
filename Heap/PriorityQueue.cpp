#include <iostream>
#include <queue>

using namespace std;

int main(){
    //max heap
    // priority_queue<int> p;

    // p.push(10);
    // p.push(20);
    // p.push(30);

    // p.pop();
    // cout<<p.top();

    //min heap
    priority_queue<int,vector<int>,greater<int> >p;
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    cout<<p.top()<<" ";

    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    
    return 0;
}