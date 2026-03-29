#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void print(string s,int index,string c){
    if(index==s.size()){
        cout<<c<<" ";
        return;
    }

    print(s,index+1,c);
    print(s,index+1,c+s[index]);

}
int main(){
    string s="abcd";
    string c="";
    int idx=0;
    print(s,idx,c);
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
    

}