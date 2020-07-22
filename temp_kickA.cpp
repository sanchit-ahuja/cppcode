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


vector<vector<int>>temp;
void dfs(int u,vector<int>&visited) {
    visited[u] = true;
    int cnt = 0;
    for(int v : temp[u]) {
        if(!visited[v]) {
            dfs(v,visited);
        }
    }
}

int main() {
    IOS
    int n,q;
    cin>>n>>q;
    vector<vector<int>>adj(n+1);
    for(int i = 0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    temp = adj;
    vector<int>ans(n);
    while(q--) {
        int a,c;
        cin>>a>>c; //a root c ccoin
        vector<int>visited(n+1,0);
        int cnt = 0;
        dfs(a,visited);
        for(int i = 1;i<=n;i++) {
            if(visited[i]) {
                ans[i-1] +=c;
            }
        }
        // ans[a-1] = cnt;
    }
    for(int x : ans) {
        cout<<x<<" ";
    }    
    cout<<endl;
    return 0;
}
