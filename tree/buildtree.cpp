#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node *root){
    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void levelorderTraversal(Node* root){
    if(!root) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

}
Node *BinaryTree(){
    int x;
    cout<<"Enter the value: ";
    cin>>x;

    if(x==-1){
        return NULL;
    }

    Node* root=new Node(x);
    cout<<"Enter the left child of "<<x<<"\n";
    root->left=BinaryTree();
    cout<<"Enter the right child of "<<x<<"\n";
    root->right=BinaryTree();

    return root;
}
int main(){
    Node *root=BinaryTree();
    cout<<"inprder traversal"<<" ";
    inorder(root);
}