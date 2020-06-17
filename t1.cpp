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
    int n,m;
    cin>>n>>m;
    map<int,int>umap;
    for(int i = 1;i<=n;i++) {
        int a, b;
        cin>>a>>b; //b = packet number
        if(umap.count(b)) {
            if(a>umap[b]) {
                umap[b]= a;
                continue;
            }
            else {
                continue;
            }
        }
        umap[b]= a;
        
    }
    int cnt = 0;
    for(auto x : umap) {
        cnt+=x.second;
        // cout<<x.first<<x.second<<endl;
        // cout<<x.second.first<<" "<<x.second.second<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}
