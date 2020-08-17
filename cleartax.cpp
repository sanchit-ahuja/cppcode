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

int main() {

    vector<int> li ={640,571,541,681,326,942,599,162,481,18,422,732,131,847,840,134,312,86,717,508,853,66,156,650,870,445,652,446,452,993,472,283,206,542,121,536,194,24,82,158,399,278,863,154,834,865,79,109,897,972,461,778,631,426,368,192,228,513,858,981,531,344,964,5,578,114,754,20,99,402,12,462,309,484,884,555,292,411,998,616,455,911,289,432,125,975,930,689,938,406,971,442,836,105,985,622,841,935,31,506};
    sort(all(li));
    int n = li.size();
    int bucket_size = 17;
    int bucket_nums = ((li[n-1]-li[0])/bucket_size) + 1;
    int left = 1,right = bucket_size;
    int bucket_num = 0;
    vector<int>umap(bucket_nums);
    for(int x : li) {
        if(x>=left && x<=right) {
            umap[bucket_num]++;
        }
        else {
            while(x>right) {
                left+=bucket_size;
                right+=bucket_size;
                bucket_num+=1;
            }
            umap[bucket_num]+=1;
        }
    }
    for(int i = 0;i<umap.size();i++) {
        cout<<i<<" "<<umap[i]<<endl;
    }
    return 0;
}
