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
    // Main idea is that after a long time the values would get stuck around RL border
    string s;
    cin>>s;
    int n = s.size();
    vector<ll>a(n,0);
    for(int i = 0;i<n-1;i++) {
        //Accumulate on RL
        if(s[i] == 'R' && s[i+1] == 'L') {
            for(int j = i;j>=0 && s[j] =='R';j--) {
                if(abs(i-j)%2 == 0) a[i]++;
                else a[i+1]++;
            }
            for(int j = i+1;j<n&&s[j] == 'L';j++) {
                if(abs(i-j)%2==0) a[i]++;
                else a[i+1]++;
            }
        }
    }
    for(auto x : a) {
        cout<<x<<" ";
    }   
    cout<<endl; 
    return 0;
}
