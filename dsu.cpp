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
class DSU {
    public:
    ll n;
    vector<ll>sz,parent;
    DSU(ll n) {
        this->n = n;
        sz.resize(n);
        parent.resize(n);
    }
    void make_set(ll a) {
        parent[a] = a;
        sz[a] = 1;
    }
    ll find_parent(ll a) {
        if(parent[a] == a) {
            return a;
        }
        return parent[a] = find_parent(parent[a]);
    }
    void union_set(ll a, ll b) {
        a = find_parent(a);
        b = find_parent(b);
        if( a != b) {
            if(sz[a] < sz[b]) {
                swap(a,b);
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};
int main() {
    ll n,m;
    cin>>n>>m;
    pair<ll,ll>edg[m];
    DSU* dsu = new DSU(n);
    loop(i,m) {
        int a,b;
        cin>>edg[i].first>>edg[i].second;
        edg[i].first--;
        edg[i].second--;
    }
    for(ll i = 0;i<n;i++) {
        dsu->make_set(i);
    }

    // cout<<'w'<<endl;
    ll ans[m];
    ll cnt = ((n-1)*(n))/2;
    for(ll i = m-1;i>=0;i--) {
        ans[i] = cnt;
        ll x = dsu->find_parent(edg[i].first);
        ll y = dsu->find_parent(edg[i].second);
        if(x != y) {
            cnt -= dsu->sz[x]*dsu->sz[y];
            dsu->union_set(x,y);
        }
        // cnt -= dsu->sz[]
    }
    loop(i,m) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
