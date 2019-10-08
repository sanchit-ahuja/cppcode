#include<bits/stdc++.h>
using namespace std;
// int cnta=0;
void dfs(vector<string>&picture,int i,int j, vector<vector<int>> &visited)
{
    if(visited[i][j]){
        return;
    }
    visited[i][j]=1;
    char c=picture[i][j];
    if((i-1>=0)&&(picture[i-1][j]==c))
    {
        dfs(picture,i-1,j,visited);
    }
    if((i+1<picture.size())&&(picture[i+1][j]==c))
    {
        dfs(picture,i+1,j,visited);
    }
    if((j-1>=0)&&(picture[i][j-1]==c))
    {
        dfs(picture,i,j-1,visited);
    }
    if((j+1<picture[0].size())&&(picture[i][j+1]==c))
    {
        dfs(picture,i,j+1,visited);
    }
}

int main()
{
    vector<string> picture={"aaaaa","abbba","accca","aaaaa"};
vector<std::vector<int>> visited(picture.size(), std::vector<int>(picture[0].size(), 0));
    int cnt=0;
    for(int i=0;i<picture.size();i++){
        for(int j=0;j<picture[0].size();j++){
            if(visited[i][j]==0){
                cnt++;
                dfs(picture,i,j,visited);
            }
        }
    }
    // for(int i=0;i<visited.size();i++){
    //     for(int j=0;j<visited[0].size();j++){
    //         cout<<visited[i][j]<<" ";
    //     }
    // }
    cout<<cnt<<endl;
}