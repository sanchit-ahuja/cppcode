#include<bits/stdc++.h>
using namespace std;

void connected(vector<vector<int>> adj, int src, vector<bool> &visit)
{
    if(visit[src] == false)
    {
        visit[src] = true;
        for(auto itr = adj[src].begin(); itr != adj[src].end(); itr++)
        {
            connected(adj,*itr,visit);
        }
    }
}

int ans(vector<vector<int>> adj)
{
    int cnt = 0;
    vector<bool> visit(adj.size(), false);
    for(int i = 0; i<adj.size(); i++)
    {
        if(visit[i] == false)
        {
            cnt++;
            connected(adj,i,visit);
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> adj;
    int v,e,src,dest;
    cin>>v>>e;
    adj.resize(v);
    while(e--)
    {
        cin>>src>>dest;
        adj[src].push_back(dest);
        adj[dest].push_back(src);

    }
    cout<<ans(adj);
    return 0;
}