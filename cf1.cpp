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
    tc(t) {
        ll r,g,b,w;
        cin>>r>>g>>b>>w;
        vector<ll>mi = {r,g,b};
        ll mini = *min_element(all(mi));
        mi[0] -= mini;
        mi[1] -= mini;
        mi[2] -= mini;
        w += 3*mini;
        int odd = 0,even = 0;
        // cout<<r<<g<<b<<'f'<<endl;
        // cout<<w<<endl;
        mi.pb(w);
        if(mi[3]!=0 && mi[0] == 0 && mi[1] == 0 && mi[2] == 0) {
            cout<<"Yes"<<endl;
            continue;
        }
        int cnt_0 = 0;
        for(int x : mi) {
            if(x%2) {
                odd+=1;
            }
            else {
                even+=1;
            }
        }

        if(odd<=1) {
            cout<<"Yes"<<endl;
            continue;

        }

        else {
            cout<<"No"<<endl;
            continue;
        }



    }    
    return 0;
}
