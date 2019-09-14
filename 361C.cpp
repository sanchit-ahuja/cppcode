#include<bits/stdc++.h>
using namespace std;

long long check(long long n)
{
    long long ans = 0;
    for(long long k = 2; k*k*k<=n; k++)
    {
        ans += n/(k*k*k);
    }
    return ans;
}

int main()
{
    long long m;
    cin>>m;
    long long i = 0;
    long long j = (long long)1e+16;
    while(i<j)
    {
        long long mid = i + j >> 1;
        if(check(mid)>= m )
        {
            j = mid;
        }
        else
        {
            i = mid + 1;
        }
    }
    if(check(j) == m) cout<<j<<endl;
    else cout <<-1<<endl;
}