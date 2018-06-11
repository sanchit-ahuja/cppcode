#include<iostream>
using namespace std;

int main()
{
    long long n,m,max=-1,sum=0;
    cin>>n>>m;
    long long arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(max<arr[i])
        {
            max=arr[i];
        }
        sum=sum+arr[i];

    }
    long long lo=max;
    long long hi=sum;
    while(lo<hi)
    {
        long long x=lo +(hi-lo)/2;
        long long days=1;
        long long curr_time=0;
        for(long long i=0;i<n;i++)
        {
            if(arr[i]+curr_time<=x)
            {
                curr_time+=arr[i];
            }
            else
            {
                ++days;
                curr_time=arr[i];
            }
        }
        if(days<=m)
        {
            hi=x;
        }
        else
        {
            lo=x+1;
        }
    }
    cout<<lo<<endl;
    return 0;


}