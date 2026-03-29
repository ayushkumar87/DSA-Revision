#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int count[26];
    for(int i=0;i<26;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        int idx=s[i]-'a';
        count[idx]++;
    }

    for(int i=0;i<26;i++){
        for(int j=0;j<count[i];j++){
            char c='a'+i;
            cout<<c<<" ";
        }
    }
}