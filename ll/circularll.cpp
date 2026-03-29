#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
void print(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void reverse(Node* head){
    if(head==NULL){
        return;
    }
    reverse(head->next);
    cout<< head->data;
}
void reverse(Node* head){
    Node* prev=NULL;
    Node* temp;
    while(head!=NULL){
        temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;

    }

    head=prev;

}
void circular(Node* head){
    Node* first=head;
    while(first->next!=NULL){
        first=first->next;
    }
    first->next=head;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *head=new Node;
    head->data=arr[0];
    head->next=NULL;
    Node *temp=head;
    for(int i=1;i<n;i++){
        temp->next=new Node;
        temp=temp->next;
        temp->data=arr[i];
        temp->next=NULL;
    }
    print(head);
    reverse(head);
    circular(head);
}
