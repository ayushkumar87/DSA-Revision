#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int mul=1;
    int sum=0;
    while(n>0){
        int ld=n%2;
        sum=sum+ld*mul;
        n=n/2;
        mul=mul*10;
    }
    cout<<sum;
}