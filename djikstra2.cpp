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
    vector<pair<int,int>>adj[6]; // 1 -2 (4) 1 node 2 node and wt = 4
    adj[1].push_back({4,9});
    adj[4].push_back({1,9});
    adj[1].push_back({5,1});
    adj[5].push_back({1,1});
    adj[5].push_back({4,2});
    adj[4].push_back({5,2});
    adj[1].push_back({2,5});
    adj[2].push_back({1,5});
    adj[2].push_back({3,2});
    adj[3].push_back({2,2});
    adj[3].push_back({4,6});
    adj[4].push_back({3,6});
    int INF = 1e+9;
    vector<int>dist(6,INF);
    vector<int>vis(6,0);
    dist[1] = 0;
    priority_queue<pair<int,int>>q;
    q.push({0,1});     //pq of dist and node, minimum dist node needed
    while(!q.empty()) {
        int a = q.top().second;
        int d = q.top().first;
        q.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto u : adj[a]) {
            int b = u.first;
            int w = u.second;
            if(dist[a]+w<dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b],b});
            }
        }

    }
    for(int x: dist) {
        cout<<x<<endl;
    }
    return 0;
}

/* 
    priority_queue<pair<int,int>,vector<pair<int,int>,greater<int>>pq;
    pq.push({0,1}); //Dist and src vertex
    vector<int>dist(n,INF);
    dist[0] = 0;
    vector<int>vis(n,0);
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        if(vis[x.second] == 1) continue;
        vis[x.second] = 1;
        for(auto u : adj[x.second]) {
            int b = u.first;
            int w = u.second;
            if(dist[x.second]+w<dist[b]) {
                dist[b] = dist[x.second]+w;
                q.push({dist[b],b});
            }
        }
    }
 */