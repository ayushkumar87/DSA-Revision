#include<iostream>
using namespace std;
void reverse(int arr[],int n,int st,int ed){
    for(int i=st,j=ed;i<=j;i++,j--){
        swap(arr[i],arr[j]);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={2,3,7,11,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=1;
    reverse(arr,n,0,n-k-1);
    reverse(arr,n,n-k,n-1);
     reverse(arr,n,0,n-1);

    print(arr,n);
}