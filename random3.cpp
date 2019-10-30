#include<bits/stdc++.h>
using namespace std;

long long fact(int n){
    long long  arr[n+1];
    arr[0]=1;
    for(int i=1;i<=n;i++){
        arr[i]=i*arr[i-1];
    }
    return arr[n];
}

int main(){
    // cout<<fact(4)<<endl;
    int n;
    cin>>n;
    long long k=fact(n);
    long long odd=0;
    for(int i=1;i<=n;i=i+2){
        odd-=k/(fact(i));
    }
    long long even=0;
    for(int i=2;i<=n;i=i+2){
        even+=k/(fact(i));
    }
    long long ans=k+odd+even;
    cout<<ans<<endl;
}