#include<iostream>
using namespace std;
int main(){
    int arr[5][4];
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

    int row=0,col=0,i,j;
    while(col<4){
        i=0,j=col;
        while(j>=0){
            cout<<arr[i][j]<<" ";
            i++,j--;
        }
        col++;
    }

    row=1;
    cout<<endl;
    while(row<5){
        i=row,j=3;
        while(i<5){
            cout<<arr[i][j]<<" ";
            i++,j--;
        }
        row++;
    }


}