#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool bfs(vector<int> adj[], int src, int dest, int v, int parent[], int dist[])
{
    deque<int> q;
    bool visited[v];
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    visited[src] = true;
    dist[src] = 0;
    q.push_back(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for(int i = 0; i < adj[u].size(); i++)
        {
            if(visited[adj[u][i]] == false)
            {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = 1 + dist[u];
                parent[adj[u][i]] = u;
                q.push_back(adj[u][i]);
            }
            if(adj[u][i] == dest)
            {
                return true;
            }
        }

    }
    return false;

}

void printpath(vector<int> adj[],int s, int dest, int v)
{
    int parent[v], dist[v];

    vector<int> path;
    int crawl = dest;
    while(parent[crawl]!= -1)
    {
        path.push_back(parent[crawl]);
        crawl = parent[crawl];
    }
    cout<< " shortest path length is "<< dist[dest]<< endl;
}

