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
    // int arr[] = {2,2,3,5,6};
    vector<int>arr = {3,4,6,8};
    int prev = arr[0];
    for(int i = 1;i<arr.size();i++) {
        int curr = arr[i];
        if(prev == curr) {
            arr[i] += 1;
        }
        prev = arr[i];
    }
    int sum = 0;
    for(int i = 0;i<arr.size();i++) {
        sum+=arr[i];
    }    
    cout<<sum<<endl;
    return 0;
}
