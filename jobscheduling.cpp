#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define loop(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b, c) for (int i = a; i < b; i += c)
#define brep(i, a, b, c) for (int i = a; i > b; i -= c)
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define sz(v) int((v).size())
#define pb push_back

struct Job
{
    int start, finish, profit;
};

bool jobComparataor(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int latestjob(Job arr[], int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j].finish <= arr[i].start)
        {
            //j is the prev job
            return j;
        }
    }
    return -1;
}

int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = 4;
    sort(arr, arr + n, jobComparataor);
    // cout<<latestjob(arr,4)<<endl;
    vector<int> dp(n, 0);
    dp[0] = arr[0].profit;
    for (int i = 1; i < n; i++)
    {

        //take the job
        int profit = arr[i].profit;
        int idx = latestjob(arr, i);
        if (idx != -1)
        {
            profit += dp[idx]; //if taking the job
        }
        dp[i] = max(profit, dp[i - 1]);
    }
    cout << dp.back() << endl;
    return 0;
}
