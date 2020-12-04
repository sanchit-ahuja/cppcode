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

const int N = 1e+5;
vector<int>solve(vector<int> &A, vector<vector<int> > &B) {
    // cout<<"work";
    for(auto x : B) {
        umap[x[0]-1].push_back({x[1]-1,2*x[2]});
        umap[x[1]-1].push_back({x[0]-1,2*x[2]});
    }
    set<pair<int,int>>q;
    vector<int>dist(A.size(),0);
    for(int i = 0;i<A.size();i++) {
        dist[i] = A[i];
        q.insert({dist[i],i});
    }
    while(!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        // cout<<v<<endl;
        for(auto x : umap[v]) {
            ll u = x.first;
            ll w = x.second;
            // cout<<dist[u]<<endl;
            if(dist[u]>dist[v]+w) {
                q.erase({dist[u],u});
                // cout<<'g'<<endl;
                dist[u] = dist[v]+w;
                q.insert({dist[u],u});
            }
        }
    }
    return dist;
    // return ans;
}


int main() {
    vector<int>A={42,10,9,6,46,28};
    vector<vector<int>>B ={{1,2,3},{1,3,28},{2,4,42},{3,4,3},{4,5,2},{5,6,6}};
    vector<int>ans = solve(A,B);
    for(auto x: ans) {
        cout<<x<<endl;
    }
    // cout<<solve(A,B)<<endl;
    return 0;
}
