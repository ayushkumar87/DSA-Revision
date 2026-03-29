#include<iostream>
using namespace std;
int main(){
    long int n;
    cin>>n;
    int mul=1;
    long int sum=0;
    while(n>0){
        long int ld=n%10;
        sum=sum+ld*mul;
        mul=mul*2;
        n=n/10;
    }
    cout<<sum;
}