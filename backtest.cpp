#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> powerset; // stores all subsets
    vector<int> subset; // temporary subset which will be updated as the recursive function executes    

int k = 0;
void backtrack(vector<int>& nums, int start){
        powerset.push_back(subset);

        for(int i = start; i < nums.size(); i++){  
            // recording all subsets that include nums[i]
            subset.push_back(nums[i]);
            // for(int i = 0;i<subset.size();i++)
            // {
            //     cout<<subset[i]<<"goo"<<endl;
            // }
            backtrack(nums, i+1);
            k+=1;
            //cout<<k<<"run"<<endl;
            cout<<subset.back()<<'d'<<endl;            
            // remove nums[i] from the present subset and move further to explore subsets that don't contain nums[i]
            subset.pop_back();
        }
}


int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    backtrack(nums,0);
}
