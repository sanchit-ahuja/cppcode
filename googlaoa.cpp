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
    string s;
    cin>>s;
    int x,y; //x -> pr, y ->rp
    // cin>>x>>y;
    stack<char>st;
    int i = 0;
    int cnt = 0;
    while(i<s.size()) {

        if(!st.empty() && s[i] == 'r') {
            if(i+1<s.size() && s[i+1] == 'p') {
                if(x > y && st.top() == 'p') {
                    st.pop();
                    cnt += x;
                    continue;
                }
                else  {
                    i+=2;
                    cnt+=y;
                    continue;
                }
            }
            else if(st.top() == 'p') {
                st.pop();
                cnt+=x;
                continue;
            }
        }
        st.push(s[i]);
        i++;
    }
    cout<<cnt<<endl;  
    return 0;
}
