 #include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->data=data;
        prev=NULL;
        next=NULL;

    }
};
int main(){
    int arr[5]={10,20,30,40,50};
    Node* head;
    head=new Node(arr[0]);
    Node* first=head;
    for(int i=0;i<5;i++){
        first->next=new Node(arr[i]);
        first->next->prev=first;
        first=first->next;

    }
    first=head;
      
}