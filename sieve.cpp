#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sieve(long long n)
{
    bool arr[n+1];
    memset(arr,true,sizeof(arr));
    for(long long p=2;p*p<=n;p++)
    {
        if(arr[p]==true)
        {
            for(long long i=2*p;i<=n;i=i+p)
            {
                arr[i]=false;
            }
        }
    }
    
    int count=0;
    for(long long p=2;p<=n;p++)
    {
        if(arr[p])
        {
            count++;
            if(count==10001)
            {
                cout<<p<<endl;
                break;
            }
        }
    }
}

int main()
{
    sieve(1000000);
    return 0;
}