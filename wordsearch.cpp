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

string word;
vector<vector<char>>board;
bool solve(int i, int j, int l) {
    if(l == word.size()) {
        return true;
    }
    if(i<0 || j < 0 || i>=board.size() || j>= board[0].size() || board[i][j] == '*') {
        return false;
    }
    if(board[i][j] != word[l]) {
        return false;
    }
    char temp = board[i][j];
    board[i][j] = '*';
    bool ans = solve(i+1,j,l+1) || solve(i-1,j,l+1) || solve(i,j+1,l+1) || solve(i,j-1,l+1);
    board[i][j] = temp;
    return ans;
}
class TrieNode {
    
};
// set<string>ans;
// void solve(int i, int j, string word, TrieNode* root) {
//     if(i<0 || j< 0 || i >= board.size()|| j >= board[0].size() || board[i][j] == '*') {
//         return;
//     }
//     if(root->children[board[i][j] - 'a']) {
//         word += board[i][j];
//         root = root->children[board[i][j]-'a'];
//         if(root->is_end) {
//             ans.insert(word);
//         }
//     }

// }


int main() {
    for(int i = 0;i<board.size();i++) {
        for(int j = 0;j<board[0].size();j++) {
            if(solve(i,j,0)) {
                return true;
            }
        }
    }   
    stack<pair<string,int>>st;
    st.push({"sma",2});
    return 0;
}
