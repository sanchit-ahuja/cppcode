#include<bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, string s, string &k, int start){
    if(start==s.size()){
        ans.push_back(k);
        return;
    }
    string t=k;
    solve(ans,s,k,start+1);
    k=t;
    k.push_back(s[start]);
    solve(ans,s,k,start+1);
    k=t;
    //k.pop_back();
}

int main()
{
    vector<string>ans;
    string k;
    solve(ans,"345",k,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}