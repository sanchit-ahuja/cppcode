#include<bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
class TrieNode {
    public:
        TrieNode *children[ALPHABET_SIZE];
        bool isend;
    
};

TrieNode * getNode() {
    TrieNode* node = new TrieNode();
    node->isend = false;
    for(int i = 0;i<ALPHABET_SIZE;i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(string word, TrieNode* node) {
    TrieNode* curr = node;
    for(char x : word) {
        if(curr->children[x-'a'] == NULL) {
            curr->children[x-'a'] = getNode();
        }
        curr = curr->children[x-'a'];
    }
    curr->isend = true;
}

bool search(string word, TrieNode* node) {
    TrieNode* temp = node;
    for(char x : word) {
        if(!temp->children[x-'a']) {
            return false;
        }
        temp = temp->children[x-'a'];
    }
    return temp->isend;
}



int countchild(TrieNode* root, int &index)
{
    TrieNode* crawl = root;
    int cnt = 0;
    for(int i = 0;i <ALPHABET_SIZE;i++)
    {
        if(crawl->children[i])
        {
            cnt++;
        }
    }
}

int main()
{
    deque<char>dq;
    dq.push_front('a');
    dq.push_front('d');
    dq.push_front('f');
    dq.push_front('g');
    for(char x : dq) {
        cout<<x<<endl;
    }
}
