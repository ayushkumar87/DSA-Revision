//we will use step down approach to optimise the tc
#include<iostream>
using namespace std;
void heapify(int arr[],int index,int n){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    
    if(index!=largest){
        swap(arr[index],arr[largest]);
        heapify(arr,largest,n);
    }
}
void BuildMaxHeap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
}
void printHeap(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(arr,10);
    printHeap(arr,10);
}
//TC is O(n) SC is O(logn) but sc can be optimised if we use while loop