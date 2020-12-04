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

vector<int> solve(vector<int>&A) {
    vector<int>ans(A.size(),-1);
    stack<int>nle;
    for(int i = 0;i<A.size();i++) {
        while(!nle.empty() && A[nle.top()] > A[i]) {
            ans[nle.top()] = A[i];
            nle.pop();
        }
        nle.push(i);
    }
    return ans;

}

int main() {
    vector<int>arr = {4,8,5,2,25};
    vector<int>ans = solve(arr);
    for(auto x : ans) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
