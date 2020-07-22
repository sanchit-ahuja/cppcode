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
    IOS
    vector<int>nums = {10,9,2,5,3,7,101,18};
    int n = nums.size();
    vector<int>len(n,1),parent(n,-1),d(n,1);
    //Length of the LIS
    for(int i =0;i<n;i++) {
        for(int j = 0;j<i;j++) {
            if(nums[i]>nums[j]) {
                len[i] = max(len[i],1+len[j]); 
            }
        }
    }

    //Construction revisited
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<i;j++) {
            if(nums[i]>nums[j] && d[i]<d[j]+1) {
                d[i] = d[j] + 1;
                parent[i] = j;
            }
        }
    }
    int ans = d[0],pos = 0;
    for(int i = 1;i<n;i++) {
        if(d[i]>ans) {
            ans = d[i]; //From where the max lis starts
            pos = i; //Get that idx
        }
    }
    vector<int>subs;
    while(pos != -1) { //Reach till the idx where d[i] = 1
        subs.push_back(nums[pos]);
        pos = parent[pos];
    }
    reverse(subs.begin(),subs.end());
    for(int u : subs) {
        cout<<u<<" ";
    }
    cout<<endl;
    // cout<<*max_element(len.begin(),len.end())<<endl;    
    return 0;
}
