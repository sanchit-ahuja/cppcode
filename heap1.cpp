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

// vector<int>arr;
//The below function is for a single node in a tree
void max_heapify(int n, int i,vector<int>&arr) {
    // arr.resize(n);
    int left = 2*i;
    int right = 2*i+1;
    int largest;
    if(left<=n && arr[i]<arr[left]) {
        largest = left; //Child cannot be bigger than the parent
    }
    else {
        largest = i; //Works
    }
    if(right<=n && arr[largest]<arr[right]) { //Checking if the left one is smaller than right if largest = left
        largest = right;
    }
    if(largest != i) { //The heap property violated
        swap(arr[largest],arr[i]);
        max_heapify(n,largest,arr); //Go into recursion for other nodes
    }
}

void build_max_heap(vector<int>&arr) {
    int n = arr.size();
    for(int i = n/2;i>=1;i--) {
        max_heapify(n,i,arr);
    }
}

void heapsort(vector<int>&arr) {
    int sz = arr.size();
    build_max_heap(arr);
    for(int i = sz;i>=2;i--) {
        swap(arr[1],arr[i]);
        sz -= 1;
        max_heapify(sz,1,arr);
    }
}

int main() {
    vector<int>arr = {-1,4,3,7,1,8,5};
    heapsort(arr);
    for(int x : arr) {
        cout<<x<<" ";
    }
    //val >=child && val<root    
    return 0;
}
