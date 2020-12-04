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


int solve(int blck, int i, int j, int mask,vector<string>&matrix) {
    if(i == matrix[0].size()) {
        return solve(blck,0,j+1,mask,matrix); //go to the next col
    }
    if(j == matrix.size()) {
        return 0;
    }
    int res = INT_MAX;
    // int missingcol = ((1<<(int)matrix.size()) - 1 - (1 << i)) & mask; //if we are blocked, then we need to turn off the ith bit
    int missicol = (mask &(1<<i)) ? (mask^(1<<i)) : mask; 
    if(matrix[i][j] == '#') { //Blcked
        res = solve(blck,i+1,j,missicol,matrix);
    }
    else {
        if( blck == 1) {
            res = min(res, solve(blck,i+1,j,missicol,matrix)); //If there is a horizontal row then fuck off vertical col and continue with the horizontal one
        }

        if(mask &(1<<i)) {
            res = min(res, solve(0,i+1,j,mask,matrix)); //if there's a vertical row at the position we're take that
        }

        res = min(res, 1+ solve(1,i+1,j,missicol,matrix));
        res = min(res,1+ solve(0,i+1,j,mask,matrix));    
    }
    return res;
}

int main() {
    vector<string>arr= {"....."
,"....."
,"....."
,"....."
,"....."};
    cout<<solve(0,0,0,0,arr)<<endl;
    return 0;
}
