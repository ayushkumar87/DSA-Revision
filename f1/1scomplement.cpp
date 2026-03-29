#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    int mul=1;
    while(n>0){
        int ld=n%10;
        if(ld==1){
            ld=0;
        }
        else{
            ld=1;
        }
        sum=sum+ld*mul;
        mul=mul*10;
        n=n/10;
    }
    cout<<sum;

}