#include<bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5

int issafe(int M[][COL], int row, int col, 
           bool visited[][COL]) 
{ 
    // row number is in range, column 
    // number is in range and value is 1 
    // and not yet visited 
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]); 
}

void dfs(int M[][COL], int row, int col, bool visited[][COL])
{
    int rownbr[] = {-1,-1,-1,0,0,1,1,1};
     int colnbr[] = {-1, 0, 1, -1, 1, -1,0,1};
  
    visited[row][col] = true;
    for(int k = 0; k < 8; ++k)
    {
        if(issafe(M,row+rownbr[k],col+colnbr[k],visited))
        {
            dfs(M,row+rownbr[k],col+colnbr[k],visited);
        }
    }
}
int cnt(int M[][COL])
{
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for(int i = 0; i < ROW; i++)
    {
        for( int j = 0; j < COL;j++)
        {
            if(M[i][j] && visited[i][j] == false)
            {
                dfs(M,i,j,visited);
                ++cnt;
            }
        }
    }
    return cnt;
}

int main() 
{ 
    int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 
  
    cout << "Number of islands is: " << cnt(M); 
  
    return 0; 
} 
 