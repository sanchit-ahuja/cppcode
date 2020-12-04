#include<bits/stdc++.h>
using namespace std;

vector<int>dig(int n) {
    vector<int>ans;
    while(n) {
        int num = n%10;
        n = n/10;
        ans.push_back(num);
    }
    return ans;
}
int sum(vector<int>&dig) {
    int ans = 0;
    for(int i = 0;i<dig.size();i++) {
        int num1 = dig[i];
        for(int j = i+1;j<dig.size();j++) {
            int num2 = dig[j];
            ans += num1*num2;
        }
    }
    return ans;
}

vector<int> sieve(int n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    vector<int>ans;
    for(int i=2;i<=n;i++){
        if(prime[i]==true){
            ans.push_back(i);
        }
    }
    return ans;
}
int countingSpecialNumbers(int A, int B) {
    const int n = 1e+5;
    vector<int>prime = sieve(n);
    int ans = 0;
    for(int i = A;i<=B;i++) {
        vector<int>digit = dig(i);
        if(digit.size() == 1) {
            continue;
        }
        int total = sum(digit);
        if(prime[total]) {
            cout<<total<<endl;
            ans+=1;
        }
    }
    return ans;
    
}

int main() {
    vector<int>prim = sieve(15);
    for(int i = 0;i<prim.size();i++) {
       cout<<prim[i]<<endl; 
    }
//   int ans = countingSpecialNumbers(1,20);
//   cout<<ans<<endl;
}