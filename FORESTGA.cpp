#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

bool f(long long H[],long long R[],long long n,long long w,long long l,long long x)
{
    long long total_cut=0;
    for(int i=0;i<n;i++)
    {
        long long ht=H[i]+R[i]*x;
        if(ht>=l)
        {
            total_cut+=ht;
        }
    }
    if(total_cut>=w)
    {
        return true;
    }
    return false;
}

int main()
{
    long long n,w,l;
    cin>>n>>w>>l;
    long long H[n],R[n];
    for(int i=0;i<n;i++)
    {
        cin>>H[i]>>R[i];
    }
    long long lo=0;
    long long hi=pow(10,18)+11;
    while(lo<hi)
    {
        long long x=lo+(hi-lo)/2;
        if (f(H,R,n,w,l,x))
        {
            hi=x;
        }
        else
        {
            lo=x+1;
        }
    }
    cout<<lo<<endl;
}