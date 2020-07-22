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

    int n;
    cin>>n;
    vector<int>a(n);
    loop(i,n) {
        cin>>a[i];
        if(a[i]%2 == 0) {
            a[i] = 1;
        }
        else {
            a[i] = -1;
        }
    }
    unordered_map<int,int>umap;
    umap[0] = 1;
    ll sum = 0;
    ll ans = 0;
    for(int x : a) {
        sum+=x;
        if(umap.count(sum)) {
            ans += umap[sum];
        }
        umap[sum]+=1;
    }
    cout<<ans<<endl;

    return 0;
}
