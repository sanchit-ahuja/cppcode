#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int func(int n, int diff)
{
    if(abs(diff) > 0)
    {
        return 0;
    }
    if(n == 1 && diff == 0)
    {
        return 2;
    }
    if(n == 1 && diff)
}