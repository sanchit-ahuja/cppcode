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
vector<int> binarysearch(double query, vector<double>&li) {
    int lo = 0,hi = li.size()-1;
    while(lo<=hi) {
        int mid = lo + (hi-lo)/2;
        if (li[mid]>query+2.0) {
            hi = mid - 1;
        }
        else{
            lo = mid+1;
        }
    }
    vector<int>ans;
    ans.push_back(hi);
    lo = 0,hi = li.size()-1;
    while(lo<=hi) {
        int mid = lo + (hi-lo)/2;
        if (li[mid]<query-2.0) {
            lo = mid + 1;
        }
        else{
            hi = mid-1;
        }
    }
    ans.push_back(lo);
    return ans;
}
int main() {
    vector<double>li = {-3,-0.3,-0.2,0.4,1.1,2.1,2.3,3.0,8.0,11.2,11.4,11.7,12.1,12.2,13.0};
    vector<double>ans;
    // vector<int>temp = binarysearch(-0.3,li);
    // cout<<temp[0]<<temp[1];
    for(double x: li) {
        vector<int>temp = binarysearch(x,li);
        if(temp[0]-temp[1]>=5) {
            ans.push_back(x);
        }
    }
    for(double x:ans) {
        cout<<x<<endl;
    }
    // cout<<binarysearch(4.0,li)<<endl;
    return 0;
}
/*0.4
1.1
11.2
11.4
11.7
12.1
12.2
// 13 */ n = 5