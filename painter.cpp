#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<ll,ll>
#define all(x) begin(x), end(x)
#define loop(i,n) for(ll i=0; i<n; i++)
#define rep(i,a,b,c) for(ll i=a; i<b; i+=c)
#define brep(i,a,b,c) for(ll i=a; i>b; i-=c)
#define tc(t) ll t; cin>>t; while(t--)
#define sz(v) ll((v).size())
#define pb push_back

ll func(vector<ll>&arr, ll k, ll mid) {
    ll total = 1;
    ll n = arr.size();
    ll sum = 0;
    loop(i,n) {
        sum += arr[i];
        if(sum > mid) {
            sum = arr[i];
            total++;
        }
    }
    return total<=k;
}

int main() {

    vector<ll>arr = {1000000,1000000};
    ll lo = *max_element(all(arr));
    ll hi = accumulate(all(arr),0);
    ll k = 1;
    ll ans = 0;
    while(lo<=hi) {
        ll mid = lo+(hi-lo)/2;
        if(func(arr,k,mid)) {
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    cout<<ans<<endl;

    return 0;
}
