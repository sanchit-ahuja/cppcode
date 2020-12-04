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


 

 
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size());
    int len = 0;
    for (int num : nums) {
        int i = binary_search(dp.begin(), dp.begin()+len, num);
        if (i < 0) {
            i = -(i + 1);
        }
        dp[i] = num;
        if (i == len) {
            len++;
        }
    }
    return len;
}


int CeilIndex(vector<int>& v, int l, int r, int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
  
int LongestIncreasingSubsequenceLength(vector<int>& v) 
{ 
    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1; // always points empty slot in tail 
  
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
  
        // new smallest value 
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 
  
        // v[i] extends largest subsequence 
        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
  
        // v[i] will become end candidate of an existing 
        // subsequence or Throw away larger elements in all 
        // LIS, to make room for upcoming grater elements 
        // than v[i] (and also, v[i] would have already 
        // appeared in one of LIS, identify the location 
        // and replace it) 
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 
  
    return length; 
} 

int solve(vector<int> v1, vector<int> v2) {
    unordered_map<int, int> v2_idx;
    for (int i = 0; i<v2.size(); i++)
        v2_idx[v2[i]] = i+1; // assume idx starting from 1
    
    vector<int> new_v1;
    
    for (int i : v1) {
        if (v2_idx[i] == 0)
            continue;
        new_v1.push_back(v2_idx[i]);
    }
    
    return v2.size() - LongestIncreasingSubsequenceLength(new_v1);
}


int main() {
   vector<int> v1 = {12,19,19,5,26,2,23,9,23,14,29,7,28,24,28,29,21,16,16};
   vector<int> v2 = {1,2,4,6,15,18,19,24,29};
   cout<<solve(v1,v2)<<endl; 
//    vector<int>temp = {0,2,1};
//    cout<<lengthOfLIS(temp)<<endl;
}


int ans(vector<int>&v1, vector<int>&v2) {
    unordered_map<int,int>umap;
    for(int i = 0;i<v2.size();i++) {
        umap[v2[i]] = i+1; //idx starting from 1
    }
    vector<int>v1_idx;
    for(int i : v1) {
        if(umap.count(i)) {
            v1_idx.pb(umap[i]);
        }
    }
}