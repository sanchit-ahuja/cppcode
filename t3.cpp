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
ll getxor(ll a) {
    if(a%4==0) {
        return a;
    }
    if(a%4 == 3) {
        return 0;
    }
    if(a%4 == 2) {
        return a+1;
    }
    if(a%4 == 1) {
        return 1;
    }
    return -1;
}
int main() {
    ll a,b;
    cin>>a>>b;
    ll ans = getxor(a-1)^getxor(b);
    cout<<ans<<endl;
    return 0;
}
