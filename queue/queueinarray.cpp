#include<iostream>
using namespace std;
class Queue{
    public:
    int front;
    int rear;
    int *arr;
    int size;
    Queue(int size){
        front=rear=0;
        this->size=size;
        arr=new int[size];
    }

    //push element in queue
    void push(int data){
        //1: check Queue is full or not
        if(rear==size){
            cout<<"queue is full";
            return;
        }
        arr[rear]=data;
        rear++;
    }

    //pop element from the queue
    void pop(){
        if(front==rear){
            cout<<"Queue is empty";
            return;
        }
        front++;
        size=rear-front+1;
    }

    bool empty(){
        return front==rear;
    }
    
};
int main(){
    Queue q(5);
    q.push(1);
    q.push(2);

}