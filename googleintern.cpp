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

// const int ALPHABET_SIZE = 26;
// class TrieNode{
//     public:
//         TrieNode *children[ALPHABET_SIZE];
//         bool endofword;
// };

// TrieNode* getNode() {
//     TrieNode* node = new TrieNode();
//     node->endofword=false;
//     for(int i=0;i<26;i++) {
//         node->children[i] = NULL;
//     }
//     return node;
// }

// void addWord(TrieNode* node, string word) {
//     TrieNode* curr = node;
//     for(auto x : word) {
//         if(curr->children[x-'a'] == NULL) {
//             curr->children[x-'a'] = getNode();
//         }
//     }
//     curr->endofword = true;
// }

// bool solve(const char *ch,TrieNode* node) {
//     if(!node) {
//         return false;
//     }
//     if(*ch == '\0') {
//         return node->endofword;
//     }
//     if(*ch!='?') {
//         if(node->children[*ch-'a']) {
//             return solve(ch+1,node->children[*ch-'a']);
//         }
//     }
//     else {
//         for(int i = 0;i<ALPHABET_SIZE;i++) {
//             if(solve(ch+1,node->children[i])) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool search(string word,TrieNode* node) {
//     TrieNode* curr = node;
//     if(!curr) {
//         return false;
//     }
//     return solve(word.c_str(),curr);
// }

class WordDictionary {
public:
    bool is_end;
    WordDictionary* children[26];
    WordDictionary() {
        this->is_end = false;
        for(int i = 0;i<26;i++) {
            this->children[i] = NULL;
        }
    }
    
    void addWord(string word) {
        WordDictionary* curr = this;
        for(char x: word) {
            if(curr->children[x-'a'] == NULL) {
                curr->children[x-'a'] = new WordDictionary();
            }
            curr = curr->children[x-'a'];
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        WordDictionary* curr = this;
        if(curr == NULL) {
            return false;
        }
        return searchfinal(word.c_str(),curr);
    }
    bool searchfinal(const char *ch, WordDictionary* temp) {
        if(!temp) {
            return false;
        }
        if(*ch == '\0') {
            return temp->is_end;
        }
        if(*ch!='?') {
            if(temp->children[*ch-'a']) {
                
            return searchfinal(ch+1,temp->children[*ch-'a']);
                                
            }
        }
        else {
            for(int i = 0;i<26;i++) {
                if(searchfinal(ch+1,temp->children[i])) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {

    int n,m;
    cin>>n>>m;
    // TrieNode* node = getNode();  
    WordDictionary* obj = new WordDictionary();
    loop(i,n) {
        string s;
        cin>>s;
        obj->addWord(s);
    }
    int q;
    cin>>q;
    int cnt = 0;
    while(q--) {
        string s;
        cin>>s;
        if(obj->search(s)) {
            cnt+=1;
        }

    }
    cout<<cnt<<endl;
    return 0;
}
