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
int romanToNumeral(string s) {
        unordered_map<char,int>umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        int ans = 0;
        int n = s.size();
        int i = 0;
        while(i<n) {
            if(s[i] == 'I' && (i+1<n && (s[i+1] == 'V' || s[i+1] == 'X'))) {   
                    ans += umap[s[i+1]]-umap[s[i]];
                    i+=2;
                    continue;
            }
            else if(s[i] == 'X' && (i+1<n && s[i+1] == 'L')) {
                    ans += umap[s[i+1]]-umap[s[i]];
                    i+=2;
                    continue;
            }
            else {
                ans += umap[s[i]];
                i++;
                continue;
            }
        }
        return ans;
    }

bool customComparator(string name1, string name2) {
  string delimiter = " ";
  int spacePositionName1 = name1.find(delimiter);
  int spacePositionName2 = name2.find(delimiter);
  string nameWithoutRoman1 = name1.substr(0,spacePositionName1);
  string Roman1 = name1.substr(spacePositionName1+1);
  string nameWithoutRoman2 = name2.substr(0,spacePositionName2);
  string Roman2 = name2.substr(spacePositionName2+1);
  int romanToNumeral1= romanToNumeral(Roman1);
  int romanToNumeral2 = romanToNumeral(Roman2);
  cout<<romanToNumeral2<<endl;
  if(nameWithoutRoman1 == nameWithoutRoman2) {
      return romanToNumeral1 < romanToNumeral2;
  }
  return nameWithoutRoman1 < nameWithoutRoman2;
  
}

int main() {
    string name = "LOUIS VIII";
    // cout<<name.find(' ')<<endl;
    string token = name.substr(0,name.find(' '));
    // cout<<name.substr(6)<<endl;

    vector<string>names = {"Louis IX", "Louis VIII"};
    // sort(all(names),customComparator);
    sort(names.begin(),names.end(),customComparator);
    for(auto x : names) {
        cout<<x<<endl;
    }
    // cout<<token<<endl;    
    return 0;
}
