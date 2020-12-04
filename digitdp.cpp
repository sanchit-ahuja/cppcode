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

const int mod = 1e9+7;
void add(int &a, int b) {
    a+=b;
    if(a >= mod) {
        a -= mod;
    }
}

int main() {
    string k;
    cin>>k;
    int d;
    cin>>d;
    int len = k.size();
    vector<vector<int>>dp(d,vector<int>(2,0));
    // dp[sum][smaller_already] --> the number of ways to choose digits so far such that the sum
    // of digits modulo D is 'sum' and smaller already says that we have chosen a smaller digit than in K
    dp[0][0] = 1;
    for(int where = 0; where < len; where++) {
        vector<vector<int>>dp2(d,vector<int>(2,0));
        for(int sum = 0;sum<d;sum++) {
            for(bool sml_already : {false, true}) {
                for(int digit = 0; digit<10;digit++) {
                    if(digit > k[where]- '0' && !sml_already) {
                        break; // if the current digit is greater than the prev digit && the prev digit is also not taken care off, then break

                    }
                    add(dp2[(sum+digit)%d][sml_already|| digit<k[where]-'0'],dp[sum][sml_already]);
                    // dp2[sum+digit%d][sml_already || digit < k[where]-'0'] += dp[sum][sml_already]
                }
            }
     
      }
      dp = dp2;
    }
    int answer = (dp[0][true] + dp[0][false])%mod;
    --answer;
    if(answer == -1) {
        cout<<mod-1<<endl;
    }
    cout<<answer<<endl;
    return 0;
}
