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
    vector<string>a(n);
    unordered_map<string,ll>umap;
    loop(i,n) {
        string s;
        cin>>s;
        sort(all(s));
        umap[s]+=1;
        // cin>>a[i];
    }

    ll cnt = 0;
    for(auto x : umap) {
        if(x.second>=2) {
            cnt += ((x.second)*(x.second-1))/2;
        }
    }    
    cout<<cnt<<endl;
    
    return 0;
}
