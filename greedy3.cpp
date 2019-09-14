#include<iostream>
using namespace std;


void insertsort(long long int arr[],long long int n)
{
    for(long long int j=1;j<n;j++)    
    {
        long long int key=arr[j];
        long long int i=j-1;
        while(i>=0&&arr[i]>key)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,q;
        cin>>n>>q;
        long long int arr[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        insertsort(arr,n);
        long long cost=0;
        for(int i=0;i<n-1;i++)
        {
            cost+=(arr[i+1]-arr[i])*q;
        }
        cout<<cost<<endl;

    }
}