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
bool isvalid(int i,int j, int m, int n){
        if(i<0||j<0||i>=m||j>=n) {
            return false;
        }
        return true;
    }
    vector<string>ans;
    void solve(int i, int j,int m, int n,string s) {
        if(i==m && j==n) {
            // cout<<i<<' '<<j<<endl;
            ans.push_back(s);
            return;
        }
        if(isvalid(i+1,j,m+1,n+1)) {
            s+='V';
            solve(i+1,j,m,n,s);
            s.pop_back();
        }
        if(isvalid(i,j+1,m+1,n+1)) {
            s+='H';
            solve(i,j+1,m,n,s);
            s.pop_back();
        }
    }
    string kthSmallestPath(vector<int>& dest, int k) {
        solve(0,0,dest[0],dest[1],"");
        sort(ans.begin(),ans.end());
        return ans[k-1];
        // return "";
    }

int main() {
    vector<int>temp = {15,15};
  cout<<kthSmallestPath(temp,155117520)<<endl; 
    return 0;
}
