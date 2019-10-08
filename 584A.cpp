#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k=n;
    sort(a,a+n);
    int visited[n+1];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        int t=a[i];
        // cout<<a[i]<<endl;
        for(int j=i+1;j<n;j++){
            // cout<<a[j]<<endl;    
            if(visited[j]==0){
                // cout<<a[j]<<'s'<<t<<endl;
                if(a[j]%t==0){
                    // cout<<j<<endl;
                    visited[j]=1;
                }
                else{
                    continue;
                }
            }
           
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}