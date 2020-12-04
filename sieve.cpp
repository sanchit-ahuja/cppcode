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

vector<int>sieve(int n, int a = 2) {
    vector<int>ans;
    vector<bool>prime(n+1,true);
    for(int p = 2;p*p<=n;p++) {
        if(prime[p] == true) {
            ans.push_back(p);
            for(int i = p*p;i<=n;i+=p) {
                prime[i] = false;
            }
        }
    }
    return ans;
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



// constint MAXN = pow(2,31)-1;
#define MAXN 100001
int spf[MAXN];

void sieve() {
    spf[1] = 1;
    for(int i = 2;i<MAXN;i++) {
        spf[i] = i;
    }
    for(int i = 4;i<MAXN;i+=2) {
            spf[i] = 2;
        }
    for(int i = 3;i*i<MAXN;i++) {
        
        if(spf[i] == i) //prime already }
        {
            for(int j = i*i;j<MAXN;j+=i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

int main () {
    sieve();
    int x = 12246;
    vector<int> p = getFactorization(x);
    for(int i : p) {
        cout<<i<<' ';
    }
}