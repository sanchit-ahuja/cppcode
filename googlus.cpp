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
    vector<vector<int>>arr(10,vector<int>(26,0));
    int n;
    vector<string>temp;
    cin>>n;
    for(int i = 0;i<n;i++) {
        string s;
        cin>>s;
        if(s[0] == '+') {
            arr[s[1]-'0'][s[2]-'A'] = 1;
        }
    }
    int cnt = 0;
    for(int i =0;i<10;i++) {
        for(int j = 0;j<26;j++) {
            if(arr[i][j]) {
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
