#include<bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
struct TrieNode{
    TrieNode *children[ALPHABET_SIZE];
    bool endofword;
};

//Creates a new TrieNode
TrieNode *getNode()
{
    TrieNode *pnode = new TrieNode;
    pnode->endofword = false;
    for(int i = 0; i<ALPHABET_SIZE;i++)
    {
        pnode->children[i] = NULL;
    }
    return pnode;
}

void insert(TrieNode* root, string key)
{
    TrieNode* crawl = root; //temp pointer to root
    for(int i = 0;i <key.length();i++)
    {
        int index = key[i] - 'a'; //get the index of the char to be entered. Here we are just creating a reference to prove that a character exists.
        if(crawl->children[index] == NULL)
        {
            crawl->children[index] = getNode(); //let say index = 1 or b. This means that there exist a reference to b at this location/

        }
        crawl = crawl->children[index]; //Linking these pointers
    }
    crawl->endofword = true;
}

bool search(TrieNode* root, string key)
{
    TrieNode* crawl = root;
    for(int i = 0; i<key.length();i++)
    {
        int index = key[i] - 'a';
        if(crawl->children[index] == NULL)
        {
            return false;
        }
        crawl = crawl->children[index];
    }
    return (crawl!=NULL && crawl->endofword == true);
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