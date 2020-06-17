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
    int n;
    cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    int cnt = 0;
    while(1) {
        if(cnt == n) {
            break;
        }
        if(a == b) {
            cout<<cnt<<endl;
            break;
        }
        char x = a[0]; 
        a.erase(0,1);
        b.pop_back();
        // a.push_back(x);
        cnt+=1;
    }
    if(cnt == n) {
        cout<<cnt<<endl;
    }    
    return 0;
}
