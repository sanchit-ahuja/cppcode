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
    return key;
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
    long long int n,q,power;
    cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++)
      {  cin>>arr[i];
      }
      cin>>q;
      
      while(q--)
      {
          cin>>power;
          long long int i=0;
          //insertsort(arr,n);
          if(arr[i]<=power)
          {   long long int sum=0;
              long long int count=0;  
              for(long long int j=0;j<=n;j++)
              {
                  sum=sum+j;
              }
            cout<<n<<" "<<sum<<endl;
          }
          else
          {   long long int sum=0;
              long long int x=arr[binarysearch(arr,power,n)];  
              for(long long int j=0;j<=x;j++)
              {
                  sum=sum+j;
              }
            cout<<x<<" "<<sum<<endl;
          }    

        
      }
    return 0;
    
}

