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
struct Edge {
    int u,v,wt;
};
const int INF  =  1e+9;
int main() {
    
    int n,m;
    cin>>n>>m;
    int k = m;
    vector<Edge>edges;
    while(k--) {
        Edge e1;
        cin>>e1.u>>e1.v>>e1.wt;
        edges.pb(e1);
    }
    vector<int>d(n,INF);
    d[0] = 0;
    bool any = false;
    for(int i = 0;i<n-1;i++) {
        for(int j = 0;j<m;j++) {
            if(d[edges[j].u] < INF) { //Needed for negative wt edges
                if(d[edges[j].v] > d[edges[j].u] + edges[j].wt) {
                    any = true;
                    d[edges[j].v] = d[edges[j].u] + edges[j].wt;
                }
            }
        }
        if(!any) break;
    }
    for(auto x : d) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
