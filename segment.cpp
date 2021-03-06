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

const int MAXN = 4*1e+5+1;

vector<ll>sums(MAXN+1,0);

void build(vector<ll>&a,int x, int lx, int rx) {
    if(lx > rx) {
        return;
    }
    if(lx == rx) {
        sums[x] = a[lx];
        return;
    }
    int mid = (lx+rx)/2;
    build(a,2*x, lx, mid);
    build(a,2*x+1,mid+1,rx);
    sums[x] = sums[2*x] + sums[2*x+1];
}

ll sum (int x, int lx, int rx, int l, int r) {
    if(l>rx|| r < lx) {
        return 0;
    }
    if(lx<=l && rx>=r) {
        return sums[x];
    }
    int mid = (l+r)/2;

    ll s1 = sum(2*x,lx,rx,l,mid);
    ll s2 = sum(2*x+1,lx,rx,mid+1,r);
    return s1+s2;
}

void update(int x, int l, int r, int pos, int val) {
    if(pos<l|| pos > r) {
        return;
    }
    if(l == r) {
        sums[x] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(2*x,l,mid,pos,val);
    update(2*x+1,mid+1,r,pos,val);
    sums[x] = sums[2*x] + sums[2*x+1];
}

int main() {
   int n,m;
   cin>>n>>m;
   vector<ll>a(n,0);
   loop(i,n) {
       cin>>a[i];
   }
   build(a,1,0,n-1);
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
           cout<<sum(1,l,r-1,0,n-1)<<endl;
       }
   }
}

/* 
    void build(vector<int>&a, int l, int r, int i) {
        if(l > r) return;
        if(l == r) sums[l] = a[l];
        int mid = (l+r)/2;
        build(a,l,mid,2*i);
        build(a,mid+1,r,2*i+1);
        sums[i] = sums[2*i] + sums[2*i+1];
    }

    int sum(int i, int l_q, int r_q, int l, int r) {
        if(l_q > r || r < l_q) return 0;
        if(l_q<=l && r_q<=r) return sums[i];
        int mid = (l+r)/2;
        int s1 = update(2*i,l_q,r_q,l,mid);
        int s2 = update(2*i+1,l_q,r_q,mid+1,r);
        return s1 + s2;
    }
    void update(int i, int pos, int l, int r, int val) {
        if(pos< l || pos > r) return;
        if(l == r) sums[l] = val;
        int mid = (l+r)/2;
        update(2*i,pos,l,mid,val);
        update(2*i+1,pos,mid+1,r,val);
        sums[i] = sums[2*i] + sums[2*i+1];
    }
 */