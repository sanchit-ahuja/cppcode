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

int main()
{
    long long int arr[]={1,2,3,4,5,6,7};
    int x=arr[binarysearch(arr,3,7)];
    cout<<x<<endl;
    return 0;
}