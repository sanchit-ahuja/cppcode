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
    vector<int>a = {1,1,2,1,2,1,1};

    int cnt = 0;
    for(int i = 1;i<a.size()-1;i++) {
        if(a[i-1] == a[i]) {
            if(a[i]!=a[i+1]) {

                cnt++;
            }
        }
        else if(a[i] == a[i+1]) {
            if(a[i]!=a[i-1]) {
                cnt++;
            }
        }

        else if(a[i-1] == a[i+1]) {
            if(a[i]!=a[i-1]) {
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
    


    return 0;
}
