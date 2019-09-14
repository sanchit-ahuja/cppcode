#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int> > adj, int src, vector<bool> &visit, vector<bool> &recstack)
{
    if(visit[src] == false)
    {
        visit[src] = true;
        recstack[src] = true;
        for(auto i = adj[src].begin();i!=adj[src].end();i++)
        {
            if(visit[*i] == false && dfs(adj,*i,visit,recstack))
            {
                return true;
            }
            if(recstack[*i]) // Checking for the vertex in recstack
            {
                return true;
            }
        }
    }
    recstack[src] = false; // Removing the vertex from rec stack
    return false;
}

bool iscycle(vector<vector<int>> adj)
{
    vector<bool> visit(adj.size(),false);
    vector<bool> recstack(adj.size(),false);
    for(int i = 0; i<adj.size(); i++)
    {
        if (dfs(adj,i,visit,recstack))
        {
            return true;   
        }
        return false;
    }

}