#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];

void addedge(int u, int v)
{
    adj[u].push_back(v);
}

void topologicalutil(int v,bool visited[], stack<int> &s)
{
    visited[v] = true;
    for(int i = 0;i<adj[v].size();i++)
    {
        if(visited[i] == false)
        {   
            topologicalutil(adj[v][i],visited,s);
        }
    }
    s.push(v);
}

void topsort()
{
    stack<int> s;
    bool *visited = new bool[6];
    for(int i = 0;i <6;i++)
    {
        visited[i] = false;
    }
    for(int i = 0; i<6;i++)
    {
        if(visited[i] == false)
        {
            topologicalutil(i,visited,s);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    addedge(5,2);
    addedge(5,0);
    addedge(4,0);
    addedge(4,1);
    addedge(2,3);
    addedge(3,1);
    topsort();
}

void dfs(int v, vector<int>&vis, vector<int>*adj,vector<int>&order) {
    vis[v] = true;
    for(int u : adj[v]) {
        if(!vis[u]) {
            dfs(u,vis,adj,order);
        }
    }
    order.push_back(v);
}