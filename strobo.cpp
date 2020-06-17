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

void solve(vector<string>&ans,int n,int len) {
    if(n == 0) {
        ans.push_back("");
        return;
    }
    if(n == 1) {
        ans.push_back("0");
        ans.push_back("1");
        ans.push_back("8");
        return;        
    }
    solve(ans,n-2,len);
    int sz = ans.size();
    for(int i = 0;i<sz;i++) {
        string curr = ans[i];
        if(n!=len) {
            ans.push_back("0" + curr+ "0");
        }
        ans.push_back("1"+curr+"1");
        ans.push_back("8"+curr+"8");
        ans.push_back("6"+curr+"9");
        ans.push_back("9"+curr+"6");
        // ans.erase(ans.begin());
    }
}

int main() {
    vector<string>ans;
    solve(ans,4,4);
    
    }
    return 0;
}
