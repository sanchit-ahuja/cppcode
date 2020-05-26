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
    tc(t) {
        ll n,k,x;
        cin>>n>>k>>x;
        vector<ll>a(n,0);
        for(ll i = 0;i<n;i+=k) {
            a[i] = x;
        }
        
        for(ll i = 0;i<n;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }    
    return 0;
}
