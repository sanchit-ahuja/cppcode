#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

int main() {
    int n;
    cin>>n;
    vector<int>dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1;i<=n;i++) {
        for(char c: to_string(i)) {
            dp[i] = min(dp[i],1+dp[i-(c-'0')]);
        }
    }
    cout<<dp.back()<<endl;    
    return 0;
}
