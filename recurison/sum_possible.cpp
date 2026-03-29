#include<iostream>
using namespace std;
void sum_pos(int arr[],int size,int index,int sum ){
    if(index==size){
        cout<<sum<<" ";
        return;
    }
    
    sum_pos(arr,size,index+1,sum);
    sum_pos(arr,size,index+1,sum+arr[index]);
}
int main(){
    int arr[6]={2,5,1,6,7,11};
    int sum=0;
    
    sum_pos(arr,6,0,sum);
}