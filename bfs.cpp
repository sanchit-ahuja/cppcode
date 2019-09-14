#include<bits/stdc++.h>
using namespace std;

vector<int> v[10];
bool visited[10];
int level[10];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0; i < v[p].size();i++)
        {
            if(visited[v[p][i]]==false)
            {
                level[v[p][i]] = 1+level[p];
                q.push(v[p][i]);
                visited[v[p][i]]= true;
            }
        }
    }
}