#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

class Edge {

        int u,v,weight;
        Edge(int u, int v, int weight) {
            this->u = u;
            this->v = v;
            this->weight = weight;
        }
};

bool comparator(Edge *e1, Edge *e2) {
    return e1->weight < e2->weight;
}

// Without dsu O(MlgM + N^2)
vector<Edge> edges;
int n = 6;
vector<int>tree_id(n);
vector<Edge> results;
int cost  = 0;

int main() {
    for(int i = 0;i<n;i++) {
        tree_id[i] = i;
    }
    int k = 9;
    while(k--) {
        int u,v,weight;
        cin>>u>>v>>weight;
        Edge e1(u,v,weight);
        Edge e2(v,u,weight);
        edges.push_back(e1);
        edges.push_back(e2);

    }
    sort(edges.begin(),edges.end(),[] (Edge e1, Edge e2) {
        return e1.weight < e2.weight;
    });

    for(auto e : edges) {
        if(tree_id[e.u] != tree_id[e.v]) {
            cost+= e.weight;
            results.push_back(e);
            int old_id = tree_id[e.u],new_id=tree_id[e.v];
            for(int i  =0;i<n;i++) {
                if(tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }
    }
    for(auto e : results) {
        cout<<e.u<<" "<<e.v<<" "<<e.weight<<endl;
    }
    cout<<cost<<endl;

    return 0;
}
