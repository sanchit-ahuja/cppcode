#include<bits/stdc++.h>
using namespace std;

bool dfs(int v, bool visited[],bool recstack[],vector<vector<int>> &adj,vector<int> &ans)
{
    if(visited[v]==false){
        visited[v]=true;
        recstack[v]=true;
        for(int i=0;i<adj[v].size();i++){
            if(recstack[adj[v][i]]){
                return true;
            }
            if(visited[adj[v][i]]==false){
                ans.push_back(adj[v][i]);
                dfs(adj[v][i],visited,recstack,adj,ans);
            }
        }
    }
    recstack[v]=false;
    return false;
}

int main(){
  vector<vector<int>>adj(4);
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);
    bool visited[4];
    bool recstack[4];
    vector<int>ans;
    for(int i=0;i<4;i++){
        visited[i]=false;
        recstack[i]=false;
    }
    for(int i=0;i<4;i++){
    (dfs(i,visited,recstack,adj,ans));
    }   
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}