#include<iostream>
#include<climits>
using namespace std;

void printmaxSubarraysum(int arr[],int size){
    // int maxi=INT_MIN,prefix=0;

     if(size==1){
            cout<<arr[0];
            return;
        }
        int maxi=INT_MIN,prefix=0;
        for(int i=0;i<size;i++){
            prefix=prefix+arr[i];
            if(prefix>maxi){
                maxi=prefix;
            }
            if(prefix<0){
                prefix=0;
            }
        }
        cout<<maxi;
}
int main(){
    int arr[3]={8,6,9};
    printmaxSubarraysum(arr,3);
}