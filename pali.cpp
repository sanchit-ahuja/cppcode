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


int numbits(int num) {
 int temp = 0;
    while(num) {
        temp+=1;
        num/=2;
    }
    return temp;    
}
int check(int bits,int num) {
    int j = 0,k = bits;
    while(j<=bits && k>=0) {
            int bit1 = num&(1<<j);
            int bit2 = num&(1<<k);
            if(bit1 == bit2) {
                j++;
                k--;
            }
            else {
                break;
            }
        }
        return j == bits-1 && k == 0;
}

const int a = 2*(1e+4);
int main() {
    int n;
    cin>>n;
    int cnt = 1;
    int ans = 0;
    // int num = 27;
    // int bits = numbits(num);
//     int j = 0,k = bits-1;
//     while(j<=bits && k>=0) {
//         int bit1 = num&(1<<j);
//         int bit2 = num&(1<<k);
//         cout<<bit1 << bit2<<endl;
//         if(bit1 == bit2) {
//             j++;
//             k--;
//         }
//         else {
//             break;
//         }
//     }
//     cout<<j<<' '<<k;
// }
    for(int i = 2;i<=a;i++) {
        int num = i;
        int bits = numbits(num);
        int j = 0, k = numbits(num)-1;
        cout<<i<<endl;
        
        // cout<<j<<' '<<k<<endl;
        if(j == 0 && k == bits-1) {
            ans = i;
            cnt+=1;
        }
        if(cnt == n) {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
