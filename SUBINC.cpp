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

int solve(vector<int>&a,int i, int curnum) {
    //take
    if(i == a.size()) {
        return 0;
    }
    int m = 0,n = 0;
    if(a[i]>=curnum) {
        curnum = a[i];
        m = 1 + solve(a,i+1,curnum);
        // cout<<m<<endl;
    }
    else {
        n =  solve(a,i+1,curnum);
    }
    return m+n;
}

int main() {

    tc(t) {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i = 0;i<n;i++) {
            cin>>a[i];
        }
        cout<<solve(a,0,1)<<endl;
    }    
    return 0;
}
