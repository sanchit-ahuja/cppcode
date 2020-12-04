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

void merge(vector<int>&arr, int left, int right, int mid) {
    int n_l = mid - left + 1;
    int n_r = right - mid;
    vector<int>lef(n_l),righ(n_r);
    for(int i = 0;i<n_l;i++) {
        lef[i] = arr[left+i];
    }

    for(int i = 0;i<n_r;i++) {
        righ[i] = arr[mid+1+i];
    }

    int i =0,j=0,k=left;
    while(i<n_l && j<n_r) {
        if(lef[i]<=righ[j]) {
            arr[k] = lef[i];
            i++;
        }
        else {
            arr[k] = righ[j];
            j++;
        }
        k++;
    }
    while(i<n_l) {
        arr[k] = lef[i];
        i++;
        k++;
    }

    while(j<n_r) {
        arr[k] = righ[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>&arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,right,mid);
    }
}


int main() {
    vector<int> a = { 12, 11, 13, 5, 6, 7 };
    mergesort(a,0,a.size()-1);
    loop(i,a.size()) {
        cout<<a[i]<<endl;
    }
    return 0;
}
