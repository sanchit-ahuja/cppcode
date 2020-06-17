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

    int C,N,M;
    cin>>C>>N>>M;
    vector<int>queries(M);
    vector<int>temp(N);
    loop(i,N) cin>>temp[i];
    loop(i,M) cin>>queries[i];
    // int MAX_DAYS = *max_element(queries.begin(),queries.end());
    int MAX_DAYS = 50;
    // vector<vector<int>>dp(C+1,vector<int>(MAX_DAYS+1),0);
    // int dp[C+1][MAX_DAYS+1] = {};
    int dp[MAX_DAYS+1][C+1] = {};
    for(int i = 0;i<N;i++) {
        // dp[temp[i]][0]+=1; //Setting up the initial freq
        dp[0][temp[i]]+=1;
    }
    for(int days = 0;days<MAX_DAYS;days++) {
        for(int i = 1;i<=C;i++) {
            if(i<=(C/2)) {
                dp[days+1][2*i] += dp[days][i]; 
            }
            else {
                dp[days+1][i] += 2*dp[days][i];
            }
        }
    }
   
    for(int x : queries) {
        int ans = 0;
        for(int i = 0;i<=C;i++) {
            ans+=dp[x][i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
