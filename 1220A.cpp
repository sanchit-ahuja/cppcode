#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<char,int>m;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        m[s[i]]++;
    }
    int cnt1=m['n'];
    int cnt0=m['z'];
    for(int i=0;i<cnt1;i++){
        cout<<1<<" ";
    }
    for(int i=0;i<cnt0;i++){
        cout<<0<<" ";
    }
}