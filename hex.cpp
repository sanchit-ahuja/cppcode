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

string convert(int num) {
    string ans = "";
    while(num) {
        int rem = num%16;
        if(rem>=0 && rem<=9) {
            ans += rem+'0';
        }
        else if(rem == 10) {
            ans+='A';
        }
        else if(rem == 11) {
            ans+='B';
        }
        else if(rem == 12) {
            ans+='C';
        }
        else if(rem == 13) {
            ans+='D';
        }
        else if(rem == 14) {
            ans+='E';
        }
        else if(rem == 15) {
            ans +='F';
        }
        
        num = num/16;
    }
    reverse(ans.begin(),ans.end());
    return ans;

}

int sumdig(int num) {
    int ans = 0;
    while(num) {
        int rem = num%10;
        ans+=rem;
        num/=10;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    unordered_map<int,char>umap;
    umap['0'] = 0;
    umap['1'] = 1;
    umap['2']  = 2;
    umap['3'] = 3;
    umap['4'] = 4;
    umap['5'] = 5;
    umap['6'] = 6;
    umap['7'] = 7;
    umap['8'] = 8;
    umap['9'] = 9;
    umap['A'] = 10;
    umap['B'] = 11;
    umap['C'] = 12;
    umap['D'] = 13;
    umap['E'] = 14;
    umap['F'] = 15;
    string ans = "";
    int temp1 = n;
    while(1) {

        int num = sumdig(temp1); //sum the incoming num
        // cout<<num<<'f'<<endl;
        string conv = convert(num); //to hex
        // cout<<conv<<"26"<<endl;
        if(conv.size() == 1) {
            ans = conv;
            break;
        }
        int temp = 0;
        for(char x:conv) {
            temp+=umap[x];
        }
        // cout<<temp<<'s'<<endl;
        temp1 = temp; 
        if(temp1>=0&&temp1<=15) {
            ans = convert(temp1);
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
