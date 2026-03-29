//in selection sort first take the smallest element and then sort it

#include<iostream>
using namespace std;
int main(){
    int arr[]={2,5,78,6,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n-1;i++){
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[idx]>arr[j]){
                idx=j;
            }
        }
        swap(arr[idx],arr[i]);
    } 

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}