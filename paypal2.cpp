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


int row[] = {1, -1, 0, 0};
int col[] = {0, 0, -1, 1};

int calc(int i, int j, int w, int h) {
    if(w <= h)
        return  i + w * j;
    return h * i + j;
}

bool GET(int bitmask, int i, int j,int w, int h) {
    return (bitmask&(1<<calc(i,j,w,h)));
}

int BFS(int bitmask,int w, int h) {

    vector<vector<int>>distance(w,vector<int>(h,-1));
    int maxDist = 0;
    queue<pair<int,int>> q;

    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            if(GET(bitmask, i, j,w,h)) {
                distance[i][j] = 0;
                q.push({i, j});
            }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        maxDist = max(maxDist, distance[x][y]);
        q.pop();

        for(int d = 0; d < 4; d++) {
            int newx = x + row[d];
            int newy = y + col[d];

            if(newx >= w || newy >= h || newx < 0 || newy < 0)
                continue;
            if(distance[newx][newy] == -1) {
                distance[newx][newy] = distance[x][y] + 1;
                q.push({newx, newy});
            }
        }
    }
    return maxDist;
}

map<pair<int,int>, int> dp;

int solve(int bitmask, int left,int w, int h) {
    if(left == 0) {
        return BFS(bitmask,w,h);
    }
    if(dp.find({bitmask, left}) != dp.end()) {
        return dp[{bitmask, left}];
    }
    int minDistance = INT_MAX;
    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            if(!GET(bitmask, i, j,w,h)) {
                int val = solve((bitmask|(1<<calc(i, j,w,h))), left-1,w,h);
                minDistance = min(minDistance, val);
            }
    return dp[{bitmask, left}] = minDistance;
}
int main() {
    
    int w,h,n;
    cin>>w>>h>>n;
    cout<<solve(0,n,w,h)<<endl;
    return 0;
}
