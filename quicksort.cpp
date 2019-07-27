#include<bits/stdc++.h>
using namespace std;

int partition (int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l+1;
    for(int j = l + 1;j<r;j++)
    {
        if (arr[j]<=pivot)
        {
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[l],arr[i-1]);
    return i-1; // Getting the idx of the partitioned element pos
}

void quickSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int pidx = partition(arr,l,r);
        quickSort(arr,l,pidx-1);
        quickSort(arr,pidx+1,r);
    }
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {3,8,2,5,1,4,7,6}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout<<partition(arr,0,n);
    quickSort(arr, 0, n); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
} 