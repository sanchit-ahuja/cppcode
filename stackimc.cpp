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

void superSt(vector<string>ops) {
    vector<pair<int,int>>st;
    int i = 0;
    for(string x : ops) {
        if(x.size() > 3) {
            string push = x.substr(0,4);
            if(push == "push") {
                // st.push_back(stoi(x.substr(5)));
                cout<<st[st.size()-1]<<endl;
            }
            else {
                
            }

        }

    }
}

int main() {
    return 0;
}
