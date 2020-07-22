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

bool flag_check(vector<int>&in, vector<int>&out,vector<vector<int>>&adj,)

int main() {
    vector<vector<int>>adj(7);
    adj[0] = {};
    adj[1] = {2,3};
    adj[2] = {2,4,4};
    adj[3] = {1,2,5};
    adj[4] = {3,6};
    adj[5] = {6};
    adj[6] = {3};
    
    vector<int>out(7,0);
    vector<int>in(7,0);
    int edges = 0;
    for(int i = 0;i<7;i++) {
        for(int to : adj[i]) {
            in[to]++;
            out[i]++;
            edges++;
        }
    }
    //check euler path
    
    return 0;
}
