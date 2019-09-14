#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarysearch(long long int arr[], long long int key, long long int n)
{
    int low=0;
    long long int high=n-1;
    while(low<=high)
    {
        long long int mid=(low+high)/2;
        if(arr[mid]<key)
            low=mid+1;
        else if(arr[mid]>key)
            high=mid-1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        long long int a,b;
        cin>>n>>a>>b;
        long long int x[n];
        for(long long i=0;i<n;i++)
        {
            cin>>x[i];
        }
        //sort(x,x+n);
        long long counta=0;
        long long countb=0;
        for(int i=0;i<n;i++)
        {
            if(x[i]==a)
            {
                counta+=1;
            }
            if(x[i]==b)
            {
                countb+=1;
            }
        }
        //cout<<counta<<countb<<endl;
        double prob=((double) counta*countb)/((double) n*n);
        cout<<prob<<endl;
    }
}