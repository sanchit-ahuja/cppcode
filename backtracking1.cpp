#include<bits/stdc++.h>
using namespace std;
#define N 8

bool issafe(int sol[N][N],int x, int y)
{
    return (x>=0 && x<N && y>=0 &&y<N &&sol[x][y] == -1);
}

void printSolution(int sol[N][N]) 
{ 
    for (int x = 0; x < N; x++) 
    { 
        for (int y = 0; y < N; y++) 
            printf(" %2d ", sol[x][y]); 
        printf("\n"); 
    } 
} 

int solvekutil(int x,int y, int sol[N][N],int xMove[N],int yMove[N], int movei)
{
    int k, next_x, next_y;
    if(movei == N*N)
    {
        return true;
    }
    for(k = 0; k<8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if(issafe(sol,next_x,next_y))
        {
            sol[next_x][next_y] = movei;
            if(solvekutil(next_x,next_y,sol,xMove,yMove,movei+1) == true)
            {
                return true;
            }
            else
            {
                sol[next_x][next_y] = -1;
            }
            
        }
    }
    return false;
    

}

bool solvek()
{
    int sol[N][N];
    for(int i = 0;i < N;i++)
    {
        for(int j = 0; j < N;j++)
        {
            sol[i][j] = -1;
        }
    }
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 }; 
    sol[0][0] = 0;
     if (solvekutil(0, 0, sol, xMove, yMove,1) == false) 
    { 
        printf("Solution does not exist"); 
        return false; 
    } 
    else
        printSolution(sol); 
  
    return true; 


}

int main()
{
    solvek();
    return 0;
}