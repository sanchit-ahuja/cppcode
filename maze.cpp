#include<bits/stdc++.h>
using namespace std;
int rowNum[] = {-1, 0, 0, 1}; 
int colNum[] = {0, -1, 1, 0}; 
int bfs(vector<vector<int>>&visited,pair<int,int> src, pair<int,int>dest,vector<vector<int>>maze)
{
    queue<pair<pair<int,int>,int>>q;
    if(maze[src.first][src.second]==0||maze[dest.first][dest.second]==0){
        return -1;
    }
    visited[src.first][src.second]=1;
    q.push(make_pair(src,0));
    while(!q.empty()){
        pair<pair<int,int>,int>temp=q.front();
        q.pop();
        if(temp.first.first==dest.first && temp.first.second==dest.second){
            return temp.second;
        }
        for(int i=0;i<4;i++){
            int r=temp.first.first+rowNum[i];
            int c=temp.first.second+colNum[i];
            if(r>=0 && c>=0 && r<maze.size() && c<maze[0].size() && visited[r][c]==false && maze[r][c]){
                visited[r][c]=true;
                q.push(make_pair(make_pair(r,c),temp.second+1));
            }
        }
    }
    return -1;
}


int main()
{
    vector<vector<int>>maze= {{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 } };
        vector<vector<int>>visited(maze.size(),vector<int>(maze[0].size(),0));
        pair<int,int>src=make_pair(0,0);
        pair<int,int>dest=make_pair(3,4);
        cout<<bfs(visited,src,dest,maze)<<endl;
}