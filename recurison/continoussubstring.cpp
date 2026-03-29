#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void fun(string s, int idx, string temp){
    if(temp.size()!=0){
        cout<<temp<<" ";
    }
    if(idx==s.size()){
        return;
    }
    if(temp.size()==0){
        fun(s,idx+1,temp);
        // temp=temp+s[idx];
    }
    fun(s,idx+1,temp+s[idx]);
}
int main(){
    string s="abc";
    // string temp="";
    fun(s,0,"");
    
}