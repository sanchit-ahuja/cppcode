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
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<char>>matrix(n,vector<char>(m));
    loop(i,n) {
        loop(j,m) {
            cin>>matrix[i][j];
        }
    }
    int ans = 0;
    for(int mask_r = 0;mask_r<(1<<n);mask_r++){
        for(int mask_c = 0; mask_c<(1<<m);mask_c++) {
            int cnt = 0;
            for(int i = 0;i<n;i++) {
                for(int j = 0;j<m;j++) {
                    if(matrix[i][j] == '#' &&!(mask_r&(1<<i)) && !(mask_c&(1<<j))) {
                        cnt++;
                    }
                }
            }
            if(cnt == k) {
                ans++;
            }
        }
    }
    cout<<ans<<endl; 
    return 0;
}
