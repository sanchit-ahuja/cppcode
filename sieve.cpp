#include<bits/stdc++.h>
using namespace std;

void sieve(int n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==true){
            cout<<i<<endl;
        }
    }

}

// vector<int>sieve(int n) {
//     vector<int>ans;
//     vector<bool>prime(n,true);
//     for(int p = 2;p*p<=n;p++) {
//         if(prime[p] == true) {
//             ans.push_back(p);
//             for(int i = p*p;i<=n;i+=p) {
//                 prime[i] = false;
//             }
//         }
//     }
//     return ans;
// }

int main()
{
    // vector<int>ans = sieve(20);
    for(int x:ans) {
        cout<<x<<endl;
    }
}