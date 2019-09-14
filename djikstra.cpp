#include<bits/stdc++.h>
using namespace std;
#define V 9


//function to find vertex with minimum dist from the set of vertices not yet included in spt.
int mindist( bool spt[], int dist[])
{
    int min = INT_MAX;
    int min_index = 0;
    for(int i = 0 ; i < V; i++)
    {
        if(spt[i] == false && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
        return min_index;
    }
}

int printSolution(int dist[], int n) 
{ 
   printf("Vertex   Distance from Source\n"); 
   for (int i = 0; i < V; i++) 
      printf("%d tt %d\n", i, dist[i]); 
} 
  


void djikstra( int graph[V][V], int src)
{
    int dist[V];
    bool spt[V];
    for(int i = 0; i< V; i++)
    {
        dist[i] = INT_MAX;
        spt[i] = false;
    }
    dist[src] = 0;
    for( int cnt = 0; cnt < V - 1; cnt++)
    {
        int u = mindist(spt, dist);
        spt[u] = true;
        for(int v = 0; v < V; v++)
        {
            //Updating dist only when u not in spt and edge exist and total weight of path from src to v through u is less than v 
            if(spt[u] == false && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v]; 
            }
        }
    }
}