#include<iostream>
using namespace std;
class Stack{
    int top;
    int *arr;
    int size;
    public:
    Stack(int size){
        arr=new int[size];
        top=-1;
        this->size=size;
    }

    //push element in array
    void push(int data){
        if(top==size-1){
            cout<<"Stack Overflow\n";
            return;
        }
        top++;
        arr[top]=data;
    }
    //pop element in array
    void pop(){
        if(top==-1){
            cout<<"stack underflow\n";
            return;
        }
        top--;

    }
    // get the to/peek element
    int peek(){
        if(top==-1){
            cout<<"Stack underflow";
            return -1;
        }
        return arr[top];
    }

    //check if array is empty or not
    bool empty(){
        return top==-1;
    }

};
int main(){
    Stack s(4);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    cout<<s.peek()<<" ";
    s.pop();
    cout<<s.peek();
}