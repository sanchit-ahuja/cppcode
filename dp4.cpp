#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int func(vector <int> &A, int x, int y)
{
    if (x > y || x >= A.size() || y <= 0) {
        return 0;
}
    if(dp[x][y] != -1)
    {
        return dp[x][y];
    }
    int a = A[x] + min(func(A,x+2,y),func(A,x+1,y-1));
    int b = A[y] + min(func(A,x+1,y-1),func(A,x,y-2));
    int ans = max(a,b);
    dp[x][y] = ans;
    return ans;
}

int main()
{
    vector<int> A;
    A.push_back(20);
    A.push_back(30);
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
    A.push_back(10);
    int a = A.size()-1;
   memset(dp,-1,sizeof(dp));
    int ans = func(A,0,a);
    cout<<ans<<endl;

}
