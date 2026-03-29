#include<iostream>
#include<climits>
using namespace std;
// void printmaxdiff(int arr[],int size){
    
//     int smax[3];
//     smax[2]=arr[size-1];
//     for(int i=size-2;i>=0;i--){
//         smax[i]=smax[i-1]+arr[i];
//     }
//     int maxi=INT_MIN;
//     for(int i=0;i<size;i++){
//         int c=smax[i+1]-arr[i];
//         maxi=max(maxi,c);
//     }
//     cout<<maxi;

// }

void printmaxdiff(int arr[],int size){
    int suff=arr[size-1];
    int max=INT_MIN;
    for(int i=size-2;i>=0;i--){
        int c=suff-arr[i];
        if(c>max){
            max=c;
        }
        if(arr[i]>suff){
            suff=arr[i];
        }
    }
    cout<<max;
}








int main(){
    int arr[3]={8,6,9};
    printmaxdiff(arr,3);
}