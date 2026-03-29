#include<iostream>
using namespace std;
int findtrip(int arr[],int n,int target){
    for(int i=0;i<n-2;i++){
        int ans=target-arr[i];
        int st=i+1,end=n-1;
        while(st<end){
            if(arr[st]+arr[end]==ans){
                return 1;
            }
            else if(arr[st]+arr[end]>ans){
                end--;
            }
            else{
                st++;
            }
        }
    }
    return -1;
}
int main(){
    int arr[6]={1,4,6,8,10,45};
    int ans=findtrip(arr,6,24);
    cout<<ans;
}  