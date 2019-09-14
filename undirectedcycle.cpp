#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];

void addedge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfsutil(int v, vector<bool> visited, int parent)
{
    visited[v] = true;
    for(int i = 0; i< adj[v].size(); i++)
    {
        if(visited[adj[v][i]] == false)
        {
            if(dfsutil(adj[v][i], visited,v))
            {
                return true;
            }
        }

        // if an adjacent vertex visited but not parent implies a cycle exists.
        else if( adj[v][i] != parent)
        {
            return true;
        }
    }
    return false;
}

bool hascycle()
{
    vector<bool>visited(5,false);
    for(int i = 0; i<5;i++)
    {
        if(visited[i] == false)
        {
            if(dfsutil(i,visited,-1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    addedge(1,0);
    addedge(0,2);
    addedge(2,1);
    addedge(0,3);
    addedge(3,4);
        cout<<hascycle()<<endl;
}