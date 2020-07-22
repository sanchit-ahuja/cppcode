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
    s.push_back('$');
    int n  = s.size();
    vector<int>p(n),c(n); //c->equivalence class vector, p->initial suffix array
    //k = 0
    vector<pair<char,int>>a(n); //->char mapping of initial char to initial idx
    loop(i,n) {
        a[i] = {s[i],i};
    }
    sort(all(a)); //Sorting the first chars lexi
    loop(i,n) {p[i] = a[i].second;} //initial suffix array
    
    c[p[0]] = 0;

    rep(i,1,n,1) {
        if(a[i].first == a[i-1].first) {
            c[p[i]] = c[p[i-1]]; //Same equivalence class for same idx
        }
        else {
            c[p[i]] = c[p[i-1]] + 1;
        }
    }

    int k = 0; //current transition
    while((1<<k)<n) {

        vector<pair<pair<int,int>,int>>a(n); //first pair.pair.first first k part, pair.pair.second second k part, pair.second indices stored

        loop(i,n) {
            a[i] = {{c[i],c[(i+(1<<k))%n]},i};
        }
        sort(all(a));
        loop(i,n) {p[i] = a[i].second;} //initial suffix array for next k transitions
        
        c[p[0]] = 0;

        rep(i,1,n,1) {
        if(a[i].first == a[i-1].first) {
            c[p[i]] = c[p[i-1]]; //Same equivalence class for same idx
        }
        else {
            c[p[i]] = c[p[i-1]] + 1;
        }
    }
    
        k++;   
    }
    loop(i,n) {
        cout<<p[i]<< ' ';
    }
    cout<<endl;
    return 0;
}
