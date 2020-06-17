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
    int n = 5;
    int INF = 1e+9;
    vector<vector<pair<int,int>>>adj(n);
    vector<int>dist(n,INF);
    dist[0] = 0;
    for(int i = 0;i<n-1;i++) {
        for(auto u : adj[i]) {
            if(dist[i] + u.second < dist[u.first]) {
                dist[u.first] = dist[i] + u.second;
            }
        }
    }
    for(int i = 0;i<n-1;i++) {
        
    }    
    return 0;
}
