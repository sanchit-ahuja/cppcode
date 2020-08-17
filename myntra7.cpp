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

// 2, 1, -1, -2, -2, -1, 1, 2
// 1, 2, 2, 1, -1, -2, -2, -1
vector<int>row = {2, 1, -1, -2, -2, -1, 1, 2};
vector<int>col = {1, 2, 2, 1, -1, -2, -2, -1};

bool isvalid(int m, int n, int i,int j) {
    if(i<0||j<0||i>=m||j>=n) {
        return false;
    }
    return true;
}

int bfs(int n, int sr, int sc, int er, int ec) {
    queue<pair<pair<int,int>,int>>q;
    q.push({{sr,sc},0});    
    // vector<>visited()
    set<pair<int,int>>visited;
    visited.insert({sr,sc});
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        int r = x.first.first;
        int c = x.first.second;
        int moves = x.second;

        if(r == er && c == ec) {
            return moves;
        }
        for(int k = 0;k<row.size();k++) {
            if(isvalid(n,n,r+row[k],c+col[k]) && !visited.count({r+row[k],c+col[k]})){
                visited.insert({r+row[k],c+col[k]});
                q.push({{r+row[k],c+col[k]},moves+1});

            }
        }
    }
    return -1;
}


int main() {
    cout<<bfs(10,0,0,0,2)<<endl;
    return 0;
}
