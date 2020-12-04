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

const int MAXN = 4*(1e+5)+1;

vector<ll> mini(MAXN + 1, LLONG_MAX);

void build(vector<ll>&a,int x, int lx, int rx) {
    if(lx > rx) {
        return;
    }
    if(lx == rx) {
        mini[x] = a[lx];
        return;
    }
    int mid = (lx+rx)/2;
    build(a,2*x, lx, mid);
    build(a,2*x+1,mid+1,rx);
    mini[x] = min(mini[2*x],mini[2*x+1]);
}

ll getmini (int x, int lx, int rx, int l, int r) {
    if(l>rx|| r < lx) {
        return LLONG_MAX;
    }
    if(lx<=l && rx>=r) {
        return mini[x];
    }
    int mid = (l+r)/2;

    ll s1 = getmini(2*x,lx,rx,l,mid);
    ll s2 = getmini(2*x+1,lx,rx,mid+1,r);
    return min(s1,s2);
}

void update(int x, int l, int r, int pos, int val) {
    if(pos<l|| pos > r) {
        return;
    }
    if(l == r) {
        mini[x] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(2*x,l,mid,pos,val);
    update(2*x+1,mid+1,r,pos,val);
    mini[x] = min(mini[2*x],mini[2*x+1]);
}

int main() {
   int n,m;
   cin>>n>>m;
   vector<ll>a(n,0);
   loop(i,n) {
       cin>>a[i];
   }
   build(a,1,0,n-1);
    // for(int x : mini) {
    //     cout<<x<<endl;
    // }
    // cout<<getmini(1,0,2,0,n-1)<<endl;
   while(m--) {
       int op;
       cin>>op;
       if(op == 1) {
           int i; ll v;
            cin>>i>>v;
            update(1,0,n-1,i,v);
       }
       else {
           int l, r;
           cin>>l>>r;
           cout<<getmini(1,l,r-1,0,n-1)<<endl;
       }
   }
}
