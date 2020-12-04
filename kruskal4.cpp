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

// int n = 6

class DSU {
    public:
    int n;
    vector<int>par,rnk;
    DSU(int n) {
        this->n = n;
        par.resize(n);
        rnk.resize(n);
    }
    void make_set(int v) {
        par[v] = v;
        rnk[v] = 0;
    }

    int find_par(int a) {
        if(a == par[a]) {
            return a;
        }
        return a = find_par(par[a]);
    }
    void union_set(int a, int b) {
        a = find_par(a);
        b = find_par(b);
        if(a!=b) {
            if(rnk[a] < rnk[b]) {
                swap(a,b);
            }
            par[b] = a;
            if(rnk[a] == rnk[b]) rnk[a]++;
        }
    }
};

class Edge {
    public:
    int u,v,weight;
    Edge(int u, int v, int weight) {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};
vector<Edge*>edges;
vector<Edge*>results;
int main() {
   int n,k;
    cin>>n>>k;
    DSU* dsu = new DSU(n);
    // parent.resize(n),rnk.resize(n);
    for(int i = 0;i<n;i++) {
        dsu->make_set(i);
    }
   while(k--) {
       int u,v,wt;
       cin>>u>>v>>wt;
       Edge *e1 = new Edge(u-1,v-1,wt);       
       Edge *e2 = new Edge(v-1,u-1,wt);
       edges.pb(e1);
       edges.pb(e2);
   } 
   sort(all(edges),[](Edge*e1, Edge*e2) {
       return e1->weight<e2->weight;
   });
   ll cst = 0;
//    cout<<edges.size()<<"size"<<endl;
   for(auto edge : edges) {
       if(dsu->find_par(edge->u) != dsu->find_par(edge->v)) {
        //    cout<<edge->u<<" "<<edge->v<<endl;
           cst+=edge->weight;
           results.pb(edge);
           dsu->union_set(edge->u,edge->v);
       }
   }
//    for(auto x : results) {
//        cout<<x->u<<" "<<x->v<<" "<<x->weight<<endl;
//    }
   cout<<cst<<endl;
    return 0;
}
