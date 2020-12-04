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

int partition(vector<int>&arr, int left, int right) {
    int pivot = arr[right];
    int idx = left;
    for(int i = left;i<right;i++) {
        if(arr[i]<=pivot) {
            swap(arr[i],arr[idx]);
            idx++;
        }
    }
    swap(arr[right],arr[idx]); //swap the pivot with the end
    return idx;

}

void quicksort(vector<int>&arr, int left, int right) {
    if(left < right) {
        int idx = partition(arr,left,right);
        quicksort(arr,left,idx-1);
        quicksort(arr,idx+1,right);
    }
}

int main() {
    vector<int>arr={2,1,11,9,2,3};
    quicksort(arr,0,arr.size()-1);
    loop(i,arr.size()) {
        cout<<arr[i]<<" ";
    }

    return 0;
}


/* 
1. Average O(nlgn) Worst O(n2)
2. Partition Strategy matters
3. How to partition? -> Last element could be pivot. Get the elements smaller than the pivot on the lhs and greater on rhs. 
4. Call quicksort recursively on lhs and rhs
5. Inplace so O(1)
 */
/* 
    int partition(int left, int right) {
        int idx = left,pivot = arr[right];
        for(int i = left;i<right;i++) {
            if(arr[idx]<=pivot) {
                swap(arr[idx],arr[i]);
                idx++;
            }
        }
        swap(arr[idx],arr[right]);
        return idx;
    }
 */