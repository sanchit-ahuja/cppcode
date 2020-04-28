#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> temp = {1, 4, 2, 10, 23, 3, 1, 0, 20};
   int max_sum = 0;
   int windo_sum = 0;
   int k = 5;
   for(int i = 0;i<k;i++) {
       windo_sum += temp[i];
   }
   for(int i = k;i<temp.size();i++) {
       windo_sum += temp[i] - temp[i-k];
       max_sum = max(windo_sum,max_sum);
   }
   cout<<max_sum;
}