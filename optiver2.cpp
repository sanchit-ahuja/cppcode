#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<unordered_set>

using namespace std;


bool parseInput(string input, vector<pair<char, char>> &parentChildMap)
{
    int lenInput = input.size();
    if (lenInput == 0)
    {
        return false;
    }
    if (lenInput > 0 && lenInput < 5)
    {
        return true;
    }
    if (input[0] == ' ' || lenInput == ' ')
    {
        return true; // cannot be parsed
    }
    int ptr = 0;
    while (ptr < lenInput)
    {
        int first = ptr;
        if ((first + 4 < lenInput) && (input[first] != '(' || (input[first + 1] < 'A' || input[first + 1] > 'Z') || input[first + 2] != ',' || (input[first + 3] < 'A' || input[first + 3] > 'Z') || (input[first + 4] != ')')))
        {
            return true;
        }
        else if (first + 3 < lenInput)
        {
            parentChildMap.push_back({input[first + 1], input[first + 3]});
        }
        ptr += 6; //assuming a space, if not we will return false already
    }
    return false;
}

bool checkDuplicatePair(vector<pair<char, char>> &parentChildVector, unordered_map<char, unordered_set<char>> &parent, unordered_map<char, unordered_set<char>> &child, unordered_set<char> &uniqueVertices)
{
    for (auto parentChild : parentChildVector)
    {
        if (parent[parentChild.first].count(parentChild.second))
        {
            return true; // there's a duplicate pair
        }
        parent[parentChild.first].insert(parentChild.second);
        child[parentChild.second].insert(parentChild.first);
        uniqueVertices.insert(parentChild.first);
        uniqueVertices.insert(parentChild.second);
    }
    return false;
}

bool checkChildrenCount(unordered_map<char, unordered_set<char>> &parent)
{
    for (auto itr : parent)
    {
        if (itr.second.size() > 2)
        {
            return true;
        }
    }
    return false;
}
bool dfs(unordered_map<char, unordered_set<char>> &umap, char u, unordered_map<char, int> &color)
{
    color[u] = 1;
    for (char x : umap[u])
    {
        if (color[x] == 1)
        {
            return true;
        }
        else if (dfs(umap, x, color))
        {
            return true;
        }
    }
    color[u] = 2;
    return false;
}

bool dfsUndirected(unordered_map<char, vector<char>> &umap, char u, unordered_map<char, int> &color, char parent)
{
    color[u] = 1;
    for (char x : umap[u])
    {
        if (x == parent)
            continue;
        if (color[x] == 1)
        {
            return true;
        }
        else if (dfsUndirected(umap, x, color, u))
        {
            return true;
        }
    }
    color[u] = 2;
    return false;
}
bool checkCycle(vector<pair<char, char>> &parentChildVector, unordered_set<char>&uniqueVertices, unordered_map<char,unordered_set<char>>&parent)
{
    unordered_map<char, vector<char>> umap;
    for (auto x : parentChildVector)
    {
        umap[x.first].push_back(x.second);
        umap[x.second].push_back(x.first);
    }
    unordered_map<char, int> color;
    for (auto x : uniqueVertices)
    {
        if (dfs(parent,x,color) || dfsUndirected(umap, x, color,'.'))
        
        {
            return true;
        }
    }
    return false;
}

pair<int, char> countMultipleRoots(unordered_map<char, unordered_set<char>> &child, unordered_set<char> &uniqueVertices)
{
    int numRoots = 0;
    char root;
    for (auto x : uniqueVertices)
    {
        if (!child.count(x))
        {
            root = x;
            numRoots++;
        }
    }
    if (numRoots > 1)
    {
        return {1, '.'};
    }
    if (numRoots == 0)
    {
        return {1, '.'};
    }
    return {0, root};
}
string solve(unordered_map<char, unordered_set<char>> &parent, char root)
{
    if ( root && !parent.count(root))
    {
        string temp = "";
        temp += "(";
        temp.push_back(root);
        temp+= ")";
        return temp;
    }
    if(!root) {
        return "";
    }
    string ans = "";
    if (parent[root].size() > 1)
    {
        auto ptr1 = parent[root].begin();
        auto ptr2 = ++(parent[root].begin());
        char first = *ptr1;
        char second = *ptr2;
        if (first < second)
        {
            ans += "(";
            ans.push_back(root);
            ans += solve(parent,first) + solve(parent,second) + ")";
        }
        else
        {
            ans += "(";
            ans.push_back(root);
            ans += solve(parent,second) + solve(parent,first) + ")";
        }
    }
    else
    {
        auto ptr = parent[root].begin();
        char first = *ptr;
        ans += "(";
        ans.push_back(root);
        ans += solve(parent,first) + ")";
    }
    return ans;
}

int main() {
    string input = "(A,B) (A,C) (B,D) (D,C)";
    // getline(cin,input);
    vector<pair<char,char>>parentChild;
    unordered_map<char,unordered_set<char>>parent,child;
    unordered_set<char>uniqueVertices;
    char root;
    bool m = parseInput(input,parentChild);
    bool n = checkDuplicatePair(parentChild,parent,child,uniqueVertices);
    unordered_map<char,unordered_set<char>>parentCopy = parent;
    bool cycle = checkCycle(parentChild,uniqueVertices,parent);
    cout<<cycle<<endl;
    root = countMultipleRoots(child,uniqueVertices).second;
    cout<<solve(parentCopy,root)<<endl;
    // if(parseInput(input,parentChild)) {
    //     cout<<"E1"<<endl;
    //     return 0;
    // }
    // else if(checkDuplicatePair(parentChild,parent,child,uniqueVertices)) {
    //     cout<<"E2"<<endl;
    //     return 0;
    // }
    // else if(checkChildrenCount(parent)) {
    //     cout<<"E3"<<endl;
    //     return 0;
    // }
    // else if(checkCycle(parentChild,uniqueVertices)) {
    //     cout<<"E4"<<endl;
    //     return 0;
    // }
    // else if(countMultipleRoots(child,uniqueVertices).first) {
    //     cout<<"E5"<<endl;
    //     return 0;
    // }
    // else {
    //     root = countMultipleRoots(child,uniqueVertices).second;
    //     cout<<solve(parent,root)<<endl;
    //     return 0;
    // }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}