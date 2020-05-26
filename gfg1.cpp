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

int binarysearch(vector<int>&vec) {
    int lo = 0;
    int hi = vec.size()-1;
    while(lo<=hi) {
        int mid = lo + (hi - lo)/2;
        if(vec[mid] - mid == vec[0]) {
            if(vec[mid+1]-vec[mid]>1) {
                return vec[mid]+1;
            }
            else {
                lo = mid + 1;
            }
        }
        else {
            if(vec[mid] - vec[mid-1]>1) {
                return vec[mid]-1;
            }
            else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    
    vector<int>vec = {1, 2, 3, 4};
    cout<<binarysearch(vec)<<endl;
    return 0;
}



//Missing element in sorted consecutive array