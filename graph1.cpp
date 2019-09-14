#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void addedge( int u, int v )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << " ";
        for( auto i = adj[f].begin(); i!=adj[f].end(); i++)
        {
            if(!visited[*i])
            {
                q.push(*i);
                visited[*i] = true;
            }
        }
    }
}   