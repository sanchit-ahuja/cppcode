#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    long long k=pow(2,n-1);
    // cout<<k<<endl;
    int cnt=0;
    while(k){
        cnt+=1;
        k=k/4;
    }
    if(k%4==0){
        cout<<cnt-1<<endl;
    }
    else
    {
        cout<<cnt<<endl;
    }
    
    // cout<<cnt<<endl;
}