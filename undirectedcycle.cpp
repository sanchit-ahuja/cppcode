#include<bits/stdc++.h>
using namespace std;

vector<int>adj[10];
vector<int>parent;
vector<int>color; //Taking 0 - white, 1 - gray 2 - black


int n,cycle_start,cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for(int u : adj[v]) {
        if(color[u] == 0) {
            parent[u] = v;
        }
        if(dfs(u)) {
            return true;
        }
        else if(color[u] == 1) {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}
void find_cycle() {
    parent.assign(n,-1);
    color.assign(n,0);
    cycle_start = -1;
    for(int v = 0;v<n;v++) {
        if(color[v] == 0 && dfs(v)) {
            break; //Found a cycle for a vertex
        }
    }
    if(cycle_start == -1) {
        cout<<"Acyclic"<<endl;
    }
    else {
        vector<int>cycle;
        cycle.push_back(cycle_start);
        for(int v = cycle_start;v!=cycle_end;v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(),cycle.end());
        cout<<"Cycle: "<<endl;
        for(int v: cycle) {
            cout<<v<<" "<<endl;
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[1].push_back(3);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(6);
    adj[6].push_back(4);
    for()
}

// bool dfsutil(int v, vector<bool> visited, int parent)
// {
//     visited[v] = true;
//     for(int i = 0; i< adj[v].size(); i++)
//     {
//         if(visited[adj[v][i]] == false)
//         {
//             if(dfsutil(adj[v][i], visited,v))
//             {
//                 return true;
//             }
//         }

//         // if an adjacent vertex visited but not parent implies a cycle exists.
//         else if( adj[v][i] != parent)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// bool hascycle()
// {
//     vector<bool>visited(5,false);
//     for(int i = 0; i<5;i++)
//     {
//         if(visited[i] == false)
//         {
//             if(dfsutil(i,visited,-1))
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main()
// {
//     addedge(1,0);
//     addedge(0,2);
//     addedge(2,1);
//     addedge(0,3);
//     addedge(3,4);
//         cout<<hascycle()<<endl;
// }