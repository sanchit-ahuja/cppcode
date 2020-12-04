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

// void dfs(vector<int>&visited, vector<vector<int>>&adj, vector<int>art,vector<int>&par,vector<int>&low, vector<int>&tin, int v, int time) {
//     visited[v] = 1;
//     tin[v] = time;
//     low[v] = time;
//     time++;
//     int childcount = 0; //for root of the dfs
//     bool isart = false;
//     for(int u : adj[v]) {
//         if(u == par[v]) {
//             continue; //u is parent of v or not
//         }
//         if(!visited[u]) {
//             par[u] = v;
//             childcount++;
//             dfs(visited,adj,art,par,low,tin,v,time);
//             if(tin[v]<=low[u]) {
//                 isart = true;
//             }
//             else {
//                 low[v] = min(low[v],low[u]);
//             }
              
//         } 
//         else {
//             low[v] = min(low[v],tin[u]);
//         }
//     }
//     if(par[v] == -1 && childcount >=2 || (par[v]!=-1 && isart)) {
//         art.push_back(v);
//     } 
// }

vector<vector<int>>adj;
vector<int>visited;
vector<int>tin,low;
vector<int>art;
void dfs(int v, int p = -1, int time) {
    //p = parent of vertex
    visited[v] = 1;
    tin[v] = low[v] = time++;
    int children = 0; //only for rooted vertices
    bool isart = false;
    for(int u : adj[v]) {
        if(u == p) continue; //if the incoming edge is the parent of current vertex root node
        if(!visited[u]) {
            p = v;
            children++;
            dfs(u,p,time);
            if(tin[v]<=low[u]) {
                isart = true;
            }
            else {
                low[v] = min(low[v],low[u]);;
            }
        }
        else {
            //already visited u 
            low[v] = min(low[v],tin[u]);
        }
    }
    if(p == -1 && children>=2 || p !=-1 && isart) {
        art.pb(v);
    }
}

int main() {
    
}
