#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool visit[10];

void dfs(int s)
{
    visit[s] = true;
    for(int i = 0;i<adj[s].size();i++)
    {
        if(!visit[adj[s][i]])
        {
            dfs(adj[s][i]);
        }
    }
}
