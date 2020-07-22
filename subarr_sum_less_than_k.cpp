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

    //Finding the max subarray sum less than k
    // arr = {-2,3,-3,6,5}; k = 4 ans = 3 //best to use an upperbound on a data structure like map/set to find the no
    //1. sum(i,j) = sum(j,0)- sum(i,0) --> upper-bound on sum-k, if found return sum - upper_bound
    int k = 4;
    vector<int>arr = {-2,3,-3,6,5};
    set<int>s;
    int n = arr.size();
    int sum = 0;
    int ans = 0;
    loop(i,n) {
        sum += arr[i];
        auto it = s.upper_bound(sum-k);
        if(it!=s.end()) ans = max(ans,sum-*it);
        s.insert(sum); 
    }

    cout<<ans<<endl;
    return 0;
}
