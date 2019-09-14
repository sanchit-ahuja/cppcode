#include<bits/stdc++.h>
using namespace std;
typedef  pair<int, int> iPair; 

class Graph
{
    public:
        int V,E;
    vector<pair<int,iPair> > edges;
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        
    }
    void addedge(int u,int v, int w)
        {
             edges.push_back({w, {u, v}}); 
        }
        int kruskal();
};

class DisjointSet
{
    int *rank, *parent, n;
    DisjointSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
         for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int x)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void union_set(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
        if(xset == yset)
            {return;}
        if(rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if(rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }
        else
        {
            parent[yset] = xset;
            rank[xset] = 1 + rank[xset];
        }
    }
};

int Graph::kruskal()
{
    int mst_wt = 0;
    sort(edges.begin(),edges.end());
    DisjointSet ds(V); 
}