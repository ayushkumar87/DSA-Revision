#include<iostream>
#include<cmath>
using namespace std;
// #include<math.h>

void sum_pos(int n,int num,int power,int total,int &count){
    if(total==num){
        count++;
        return;
    }
    if(total>num){
        return;
    }

    sum_pos(n+1,num,power,total,count);
    sum_pos(n+1,num,power,total+pow(n,power),count);
}
int main(){
    int n=1,num=100,power=2,total=0,count=0;
    sum_pos(n,num,power,total,count);
    cout<<count;

}