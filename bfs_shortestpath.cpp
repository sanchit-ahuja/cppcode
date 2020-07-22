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

bool isvalid(int i, int j,int m,int n) {
    if(i<0||j<0||i>=m||j>=n) {
        return false;
    }
    return true;
}
int row[] = {-1,0,0,1};
int col[] = {0,1,-1,0};

int bfs(vector<vector<char>>&arr,pair<int,int>&src,pair<int,int>&dest) {
    int m = arr.size();
    int n = arr[0].size();
    queue<pair<pair<int,int>,int>>q; //coordinates and dist
    q.push({src,0});
    // int ans = 0;
    while(!q.empty()) {
        auto x = q.front();
        if(x.first.first == dest.first && x.first.second == dest.second) {
            return x.second;
            // cout<<x.second<<endl;
            // return 0;
        }
        q.pop();
        for(int i = 0;i<4;i++) {
            // cout<<'f'<<endl;
            if(isvalid(row[i]+x.first.first,col[i]+x.first.second,m,n) && arr[row[i]+x.first.first][col[i]+x.first.second] == '.') {
                // cout<<x.second<<endl;
                 arr[row[i]+x.first.first][col[i]+x.first.second] = '#';
                 q.push({{x.first.first+row[i],x.first.second+col[i]},x.second+1});   
            }
        }
    }
    return -1;
}

int main() {
   
   int m,n;
   cin>>m>>n;
   vector<vector<char>>arr(m,vector<char>(n,'.'));
   
   loop(i,m) {
       loop(j,n) {
           cin>>arr[i][j];
       }
   }
    vector<pii>targets;
   for(int i = 0;i<m;i++) {
       for(int j = 0;j<n;j++) {
           if(arr[i][j] =='.') {
               targets.pb({i,j});
           }
       }
   }
   //{0,0} -->{2,4}
   int ans = INT_MIN;
//    pii src = {0,0};
//    pii dest = {0,0};
//    cout<<bfs(arr,src,dest)<<endl;
//    for(auto v : targets) {
//        cout<<v.first<<" "<<v.second<<endl;
//    }
   for(int i = 0;i<targets.size();i++) {
       pii src = {targets[i].first,targets[i].second};
    //    cout<<src.first<<" "<<src.second<<"src"<<endl;
       for(int j = 0;j<targets.size();j++) {
        pii dest = {targets[j].first,targets[j].second};
    //    cout<<dest.first<<" "<<dest.second<<"dest"<<endl;
        vector<vector<char>>temp2 = arr;
        int temp = bfs(arr,src,dest);
        arr=temp2; 
        // cout<<temp<<endl;
        ans = max(temp,ans);
       }
   }
   cout<<ans<<endl;
    return 0;
}
