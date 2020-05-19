#include<bits/stdc++.h>
using namespace std;
 vector<int>adj[10];

 void add_edge(int u,int v) {
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
// bool dfs(vector<vector<int> > adj, int src, vector<bool> &visit, vector<bool> &recstack)
// {
//     if(visit[src] == false)
//     {
//         visit[src] = true;
//         recstack[src] = true;
//         for(auto i = adj[src].begin();i!=adj[src].end();i++)
//         {
//             if(visit[*i] == false && dfs(adj,*i,visit,recstack))
//             {
//                 return true;
//             }
//             if(recstack[*i]) // Checking for the vertex in recstack
//             {
//                 return true;
//             }
//         }
//     }
//     recstack[src] = false; // Removing the vertex from rec stack
//     return false;
// }

// bool iscycle(vector<vector<int>> adj)
// {
//     vector<bool> visit(adj.size(),false);
//     vector<bool> recstack(adj.size(),false);
//     for(int i = 0; i<adj.size(); i++)
//     {
//         if (dfs(adj,i,visit,recstack))
//         {
//             return true;   
//         }
//         return false;
//     }

// }

// bool dfs(int v,vector<int>&color) {
//     color[v] = 1;
//     for(int u : adj[v]) {
//         if(dfs(u,color)) {
//             return true;
//         }
//         else if(color[u] == 1) {
//             return true;
//         }
//     }
//     return false;
// }

bool dfs(int v, vector<int>&color) {
    color[v] = 1;
    for(int u : adj[v]) {
        if(dfs(u,color)) {
            return true;
        }
        else if(color[u]==1) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

int main() {
   
    add_edge(1,2);
    add_edge(1,4);
    add_edge(2,3);
    add_edge(3,4);
    add_edge(3,6);
    vector<int>color;
    color.assign(4,0);
    for(int i = 1;i<= 3;i++) {
        if(dfs(i,color)) {
            cout<<"YES";
        }
        cout<<"NO";
    }

}