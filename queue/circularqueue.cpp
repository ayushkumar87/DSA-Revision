#include<iostream>
using namespace std;
class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int size){
        front=rear=-1;
        arr=new int[size];
        this->size=size;
    }
    bool empty(){
        return front==-1&& rear==-1;
    }
    bool full(){
        return front==(rear+1)%size;
    }  
    void push(int data){
        if(empty()){
            front=rear=0;
            arr[rear]=data;
            return;
        }
        else if(full()){
            cout<<"Queue is full";
            return;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=data;
            return;
        }
    }
    void pop(){
        if(empty()){
            cout<<"Queue is empty";
            return;
        }
        else if(front==rear){
            cout<<"Element is been poped";
            front=rear=-1;
            return;
        }
        else{
            cout<<"Element is popped";
            front=(front+1)%size;
            return;
        }
    }
};
int main(){
    CircularQueue q(5);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(0);
    q.push(8);

}