#include<iostream>
using namespace std;
void fib(int n){
    int x=0;
    int y=1;
    int sum;
    for(int i=2;i<=n;i++){
        sum=x+y;
        x=y;
        y=sum;
        
    }
    cout<<sum;
}

int main(){
    int n;
    cin>>n;
    fib(n);
}