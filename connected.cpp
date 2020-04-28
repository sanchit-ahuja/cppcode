#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<int>&visited,vector<int>*adj) {
    visited[v] = 1;
    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u,visited,adj);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    while(m--) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt = 0;
    vector<int>visited(n+1,0);
    for(int v = 1;v<=n;v++) {
        if(!visited[v]) {
            dfs(v,visited,adj);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}