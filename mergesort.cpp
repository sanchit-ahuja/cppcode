#include<bits/stdc++.h>
using namespace std;

void merge(int arr [], int l, int m, int r)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L1[n1], R1[n2];
    for(int i = 0; i < n1;i++)
    {
        L1[i] = arr[l + i];
    }

    for(int j = 0; j < n2;j++)
    {
        R1[j] = arr[m + 1 + j];
    }
    k = l, i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(L1[i]<=R1[j])
        {
            arr[k] = L1[i];
            i++;
        }
        else 
        {
            arr[k] = R1[j];
            j++;
        }
        k++;

    }
    while (i < n1)
    {
        arr[k] = L1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R1[j];
        j++;
        k++;
    }

}

void mergeSort(int arr [], int l, int r)
{
    if(l<r)
    {
        int m = l + (r - l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr, l, m, r);
    }
}





void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}