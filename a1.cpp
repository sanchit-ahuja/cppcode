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
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    loop(i,n) {
        cin>>a[i];
    }
    int ans = INT_MAX;
    for(int i = 0;i+k-1<n;i++) {
        int j = i+k-1; //Consider a window of size k
        if(a[i]<0 && a[j]<0) {
            ans = min(ans,abs(a[i])); //all nos are negative then consider 
        }
        else if(a[i]>0 && a[j]>0)  {
            ans = min(ans,abs(a[j]));
        }
        else {
            ans = min(ans,abs(a[i]) + abs(a[j])+min(abs(a[i]),abs(a[j])));
        }
    }   
    cout<<ans<<endl;    
    return 0;
}
