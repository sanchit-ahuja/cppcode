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


bool dfs(vector<vector<int>>&adj, int src, int trg,vector<int>&visited) {
    visited[src] = 1;
    if(src == trg) {
        return true;
    }
    for(int i = 0;i<adj.size();i++) {
        if(adj[src][i] == 1 && !visited[i]) {
            if(dfs(adj,i,trg,visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int test;
    cin>>test;
    for(int t=1;t<=test;t++) {
        int n;
        cin>>n;
        vector<vector<char>>ans(n,vector<char>(n,'N'));
        vector<vector<int>>adj(n,vector<int>(n,0));
        string inp;
        cin>>inp;
        string outp;
        cin>>outp;

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(i == j) {
                    adj[i][j] = 1;
                }
                if(abs(i-j) == 1) {
                    if(outp[i] == 'Y' && inp[j] == 'Y') {
                        adj[i][j] = 1;
                    }
                }
            }            
        }

        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                vector<int>visited(n,0);
                if(dfs(adj,i,j,visited)) {
                    ans[i][j] = 'Y';
                }
            }
        }
        
        cout<<"Case #"+to_string(t) +":"<<endl;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }    
    return 0;
}
