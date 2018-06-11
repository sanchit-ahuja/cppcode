#include<iostream>
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
     long long int n,tc;
    
    cin >> n;
    cout<<endl;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout<<endl;
    cin >>tc;
    cout<<endl;
    while(tc--)
    {
        int q;
        cin>>q;
        cout<<endl;
        insertsort(arr,n);
        int x=binarysearch(arr,q,n);
        cout<<x<<endl;
    }
    return 0;

}