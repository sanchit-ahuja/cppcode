#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long c[n];
        long long l[n];
        for(long long i=0;i<n;i++)
        {
            cin>>c[i];
        }
        for(long long i=0;i<n;i++)
        {
            cin>>l[i];
        }
        long long ans=0; long long min=1000000;
        for(int i=0;i<n;i++)
        {
            if(min>c[i])
            {
                min=c[i];
            }
            ans=ans+min*l[i];
        }
        cout<<ans<<endl;
    }
}