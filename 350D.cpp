#include<bits/stdc++.h>
using LL = long long;
using namespace std;

bool check(long long mid, int k, int n, long long *a, long long *b)
{
    long long ans = 0;
    for(int i = 0;i < n; i++)
    {
        ans+= max(0LL,a[i]*mid - b[i]);
        if(ans > k) return 0;
    }
    return ans <= k;
}

int main()
{
    int n,k;
    cin>>n>>k;
    long long a[n];
    long long b[n];
    for(int i = 0;i <n;i++){cin>>a[i];}
    for(int i = 0;i <n;i++){cin>>b[i];}
    int lo = 0;
    int hi = (int)2e9;
    while (lo < hi)
    {
        LL mid = (lo + hi + 1)>>1;
        if(check(mid,k,n,a,b)){lo = mid;}
        else
        {
            hi = mid -1;
        }
        
    }
    cout<<lo<<endl;
}