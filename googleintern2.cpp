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



int findMaxOR(vector<int>&arr) 

{ 

    // sort the array in decreasing 

    // order 

    // sort(arr, arr + n); 

    sort(all(arr));
    int n = arr.size();
    
    reverse(all(arr));
    // Maximum element in the set 

    int maxOR = arr[0]; 

  

    int count = 1; 

  

    for (int i = 1; i < n; i++) { 

        // if bitwise or with the next element is 

        // greater than current value 

        if ((maxOR | arr[i]) > maxOR) 

        // then add this element in the set and 

        // update the current maxOR value 

        { 

            maxOR = maxOR | arr[i]; 

            count++; 

        } 

    } 

  

    return count; 

} 




int main() {

    vector<int>arr = {1,2,3,4,5};
    cout<<findMaxOR(arr)<<endl;
    return 0;
}
