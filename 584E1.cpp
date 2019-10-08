#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        vector<int>v;
        for(int i=0;i<m;i++){
            int k=INT_MIN;
        for(int j=0;j<n;j++){
            k=max(k,arr[j][i]);

        }
        v.push_back(k);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=v[i];
        }
        printf("go %d\n",ans);
    }
}