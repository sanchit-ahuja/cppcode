#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost){
   int max_so_far = 0;
   int max_ending_here = 0;
   for(int i=0;i<cost.size();i++){
       max_ending_here += cost[i];
       if(max_ending_here<0){
           max_ending_here = 0;
       }
       max_so_far = max(max_ending_here,max_so_far);
   }
   return max_so_far;
}

int main(){
    vector<int> cost = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<solve(cost)<<endl;

}