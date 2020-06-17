
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
vector<int>ans;
void solve(int num, int i) {
    queue<int>q;
    q.push(i);
    while(!q.empty()) {
        int number = q.front();
        q.pop();

        // cout<<number<<'f'<<endl;
        if(number<=num) {
            ans.push_back(number);
        
        int last_dig = number%10;
        if(last_dig == 0) {
            q.push((number*10)+(last_dig+1));
        }
        else if(last_dig == 9) {
            q.push((number*10)+(last_dig-1));
        }
        else {
            q.push((number*10)+(last_dig-1));
            q.push((number*10)+(last_dig+1));
        }
        }
    }
}

int main() {
    // vector<int>ans;    
    int num = 105;
    for(int i = 1;i<=9;i++) {
        solve(num,i);
    }
    // solve(105,1);
    for(int x : ans) {
        cout<<x<<endl;
    }
    return 0;
}
