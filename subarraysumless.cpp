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
    vector<int>arr= {1,11,2,3,15};
    int n = arr.size();
    int k = 10;
    int i = 0, j = 0, sum = 0, cnt = 0;
    while(i<n && j<n) {
        if(sum <= k) {
            if(j>=i) {
                cnt+=(j-i);
            }
            sum+=arr[j];
            if(j<n) {
                j++;
            }
        }
        else {
            sum -= arr[i];
            i++;
        }
    }
    cout<<cnt<<endl;    
    return 0;
}





