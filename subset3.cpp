#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>nums,vector<vector<int>>&ans,vector<int>&res, int i){
    if(i==nums.size()){
        ans.push_back(res);
        // res.clear();
        return;
    }
    //take the num
    res.push_back(nums[i]);
    solve(nums,ans,res,i+1);
    //dont take
    solve(nums,ans,res,i+1);

}

int main(){
    vector<int>nums={1,2,3};
    vector<vector<int>>ans;
    vector<int>res;
    solve(nums,ans,res,0);

}