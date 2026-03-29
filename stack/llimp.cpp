#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class Stack{
    Node* top;
    public:
    Stack(){
        top=NULL;
    }

    //push element
    void push(int data){
        Node *temp=new Node(data);
        if(temp==NULL){
            cout<<"Stack Overflow\n";
            return;
        }

        temp->next=top;
        top=temp;
    }

    //pop element
    void pop(){
        if(top==NULL){
            cout<<"Stack Underflow\n";
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    //top element
    int peek(){
        if(top==NULL){
            cout<<"stack is empty\n";
        }
        return top->data;
    }

    bool empty(){
        return top == NULL;
    }
};
int main(){
    Stack S;
    S.push(10);
    S.push(20);
    cout<<S.empty();
}