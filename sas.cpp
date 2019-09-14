#include<iostream>
using namespace std;
void insertsort(long long int arr[],long long int n)
{
    for(int j=1;j<n;j++)    
    {
        int key=arr[j];
        int i=j-1;
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
    int t;
    cin>>t;
    long long n;
    long long x;
    while(t--)
    {
        cin >>n>>x;
        long long arr[n];
        for(long long i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        insertsort(arr,n);
        long long bottles=0;
        long long sum=0;
        for(long long i=0;i<n;i++)
        {
            sum=sum+arr[i];
            if(sum>x)
            {
                break;
            }
            bottles++;
            
        }
        cout<<bottles<<endl;
    }
}