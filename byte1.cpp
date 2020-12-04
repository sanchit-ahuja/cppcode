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
    
    vector<int>arr = {}; //"2-5,7-9,11"
    // string ans = "";
    vector<string>res;
    int n = arr.size();
    int i = 0;
    while(1) {
        int a = arr[i];
        while(i+1<n && arr[i+1]-arr[i] == 1) {
            i++;
        }
        int b = arr[i];

        // cout<<a<<' '<<b<<endl;
        if(a != b) {
            string ans = "";
            ans = ans + to_string(a) + "->" + to_string(b);
            res.push_back(ans);
        }
        else {
            string ans = "";
            ans += to_string(a);
            res.push_back(ans);
        }
        i++;
        if(i == n) {
            break;
        }
    }
    for(auto x : res) {
        cout<<x<<endl;
    }
    // ans.pop_back();
    // cout<<ans<<endl;
    return 0;
}
