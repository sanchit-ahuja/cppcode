#include<bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
class TrieNode{
    public:
        TrieNode *children[ALPHABET_SIZE];
        bool endofword;
};

//Creates a new TrieNode
// TrieNode *getNode()
// {
//     TrieNode *pnode = new TrieNode;
//     pnode->endofword = false;
//     for(int i = 0; i<ALPHABET_SIZE;i++)
//     {
//         pnode->children[i] = NULL;
//     }
//     return pnode;
// }

TrieNode *getNode() {
    TrieNode* pnode = new TrieNode();
    pnode->endofword = false;
    for(int i =0;i<ALPHABET_SIZE;i++) {
        pnode->children[i] = NULL;
    }
    return pnode;

}

// void insert(TrieNode* root, string key)
// {
//     TrieNode* crawl = root; //temp pointer to root
//     for(int i = 0;i <key.length();i++)
//     {
//         int index = key[i] - 'a'; //get the index of the char to be entered. Here we are just creating a reference to prove that a character exists.
//         if(crawl->children[index] == NULL)
//         {
//             crawl->children[index] = getNode(); //let say index = 1 or b. This means that there exist a reference to b at this location/

//         }
//         crawl = crawl->children[index]; //Going to the next child
//     }
//     crawl->endofword = true;
// }
void insert(TrieNode* root, string key) {
    TrieNode* curr =root;
    for(char x:key) {
        if(curr->children[x-'a'] == NULL) {
            curr->children[x - 'a'] = getNode();
        }
        curr = curr->children[x-'a'];
    }
    curr->endofword = true;
}


bool search(TrieNode* root, string key) {
    TrieNode* temp = root;
    for(char x : key) {
        if(temp->children[x-'a'] == NULL) {
            return false;
        }
        temp = temp->children[x-'a'];
    }
    return temp->endofword;
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
    char x = '13';
    cout<<-2/2<<endl;
    return 0;
}
