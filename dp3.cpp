#include<bits/stdc++.h>
using namespace std;

int count(int S[], int m, int n)
{
    int table[n+1][m+1];
    int x,y;

    for(int i = 0; i < m; i++)
    {
        table[0][i] = 1;
    }
    for(int i = 1; i <= n;i++)
    {
        table[i][0]=0;
    }
    for(int i = 1; i <=n;i++)
    {
        for(int j = 1; j<=m;j++)
        {
            x = (i - S[j-1] >=0) ? table[i - S[j-1]][j] : 0;
            y = table[i][j-1];
            table[i][j] = x + y;
            
        }
    }
    return table[n][m];
}

int main() 
{ 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 4; 
    cout << count(arr, m, n); 
    return 0; 
} 