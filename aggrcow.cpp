#include<iostream>
using namespace std;

void swap(long long* a, long long* b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (long long arr[], long long low, long long high)
{
    long long pivot = arr[high];    // pivot
    long long i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(long long arr[], long long low, long long high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

bool poly(long long arr[],long long x,long long n,long long c)
{
    long long cowsplaced=1; long long pos=arr[0];
    for(long long i=1;i<n;i++)
    {
        if(arr[i]-pos>=x)
        {
            cowsplaced++;
            if(cowsplaced==c)
            {
                return true;
            }
            pos=arr[i];
        }
    }
    return false;
}


int main()
{
    int t;
    long long C;
    long long N;
    
    cin>>t;
    while(t--)
    {
        cin>>N>>C;
        long long arr[N];
        for(long long i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        quickSort(arr,0,N-1);
        long long lo=0;
        long long hi=arr[N-1]-arr[0];
        long long cowsplaced=1;
        long long pos=arr[0];
        while(lo<hi)
        {
            long long x=lo+(hi-lo+1)/2;
            if(poly(arr,x,N,C)==true)
            {
                hi=x;
            }
            else
            {
                lo=x+1;
            }
            
        }
        cout<<hi<<endl;
        


    }
}