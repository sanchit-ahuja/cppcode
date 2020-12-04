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


//Refer to back to back SWE video
//1. Main crux of the algo is to maintain a running row sum. Reducing the 2D array --> 1D array.
//2. The cumulative sum squishes the rectangle to 1D row. Now we can apply which subarray had maximum sum and we can use Kadane algo for that.
int main() {

    vector<vector<int>>arr = {{6,-5,-7,4,-4},{-9,3,-6,5,2},{-10,4,7,-6,3},{-8,9,-3,3,-7}};
    int ans = INT_MIN;
    int row = arr.size();
    int col = arr[0].size();
    for(int i = 0;i<col;i++) { //Left pointer
        vector<int>running(row,0);
        for(int j = i;j<col;j++) { //Right pointer
            for(int k = 0;k<row;k++) {
                running[k] += arr[k][j];
            }
            for(int x : running) {
                cout<<x<<" ";
            }
            cout<<endl;
            //Kadane here
            int val = running[0];
            int temp = running[0];
            for(int k = 1;k<row;k++) {
                    if(val>0) {
                        val+=running[k];
                    }
                    else {
                        val = running[k];
                    }
                    temp = max(val,temp);

            }
            cout<<temp<<"temp"<<endl;
            ans = max(ans,temp); 
        }
    }
    cout<<ans<<endl;    
    return 0;
}
