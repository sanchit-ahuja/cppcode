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
    ll n,m;
    cin>>n>>m;
    // vector<vector<int>>A(n,vector<int>(m,0));
    ll A[n][m];
    for(int i = 0;i<n;i++){
        loop(j,m) {
            cin>>A[i][j];
        }
    }
    int q;
    cin>>q;
    while(q--) {
        ll a;
        cin>>a;
        ll g = m-1;
        ll h = 0;
        ll flag = 0;
        // cout<<h<<' '<<g<<'t'<<endl;
        while(h<n && g>=0) {
            if(h>=n||g<0) {
                break;
            }
            if(a == A[h][g]) {
                flag = 1;
                cout<<h<<' '<<g<<endl;
                break;
            }
            else if(a<A[h][g]) {
                g--;
            }
            else {
                h++;
            }
        }
        if(flag == 0) {
            cout<<-1<<' '<<-1<<endl;
        }
        else {
            continue;
        }
    }    
    return 0;
}
