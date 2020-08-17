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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    loop(i, n)
    {
        cin >> a[i];
    }

    int mx = -1;
    vector<pii> possible;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
            {
                possible.pb({i, j});
            }
        }
    }
    /* The below soln wont work. Worst case is O(n^3). We need to use prefix sum to calculate the left, right,up and down 
        empty possible

     */

    for (auto p : possible)
    {
        int x = p.first;
        int y = p.second;
        int i = x, j = y;
        int cnt = 0;
        //up
        while (i >= 0 && a[i--][j] == '.')
        {
            // i--;
            if (i < 0 || a[i][j] == '#')
            {
                break;
            }
            cnt++;
        }
        i = x, j = y;
        //down
        while (i < n && a[i++][j] == '.')
        {
            if (i >= n || a[i][j] == '#')
            {
                break;
            }
            cnt++;
            // i++;
        }
        //right
        i = x, j = y;
        while (j >= 0 && a[i][j--] == '.')
        {
            if (j < 0 || a[i][j] == '#')
            {
                break;
            }
            cnt++;
        }

        i = x, j = y;

        while (j < m && a[i][j++] == '.')
        {
            if (j >= m || a[i][j] == '#')
            {
                break;
            }
            cnt++;
        }
        mx = max(cnt, mx);
    }
    cout << mx + 1 << endl;
    return 0;
}
