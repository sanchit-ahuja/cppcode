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
    vector<string>arr = {"L","L","L","C1"};
    int n = 2;
    string s = "";
    set<int>idx;
    loop(i,n) {
        s+='0';
        idx.insert(i);
    }  
    for(string x : arr) {
        if(x[0] == 'L' && idx.size()>0) {
            int idc = *idx.begin();
            s[idc] = '1';
            idx.erase(idx.begin());
        }
        else if(x[0] == 'C') {
            int idc = x[1] - '0';
            if(!idx.count(idc)) {
                idx.insert(idc);
            }
            s[idc] = '0';
        }
    }
     cout<<s<<endl;
    return 0;
}
