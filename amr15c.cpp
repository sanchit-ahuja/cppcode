#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        int flag=0;
        cin>>n>>k;
        if(k>floor(n/2)){
            cout<<-1<<endl;
            flag=1;
            // continue;
        }
        else{
            for(int i=k+1;i<=n;i++){
            cout<<i<<" ";
        }
        for(int i=1;i<k;i++){
            cout<<i<<" ";
        }
        }
        cout<<k<<endl;
    }
}