
#include<bits/stdc++.h>
using namespace std;

int ans(int A[],int n)
{
    int cnt = 0;
    for(int i = 0;i<n-1;i++)
    {
        cnt += abs(A[i] - A[i+1]);
        A[i+1] += abs(A[i] - A[i+1]);
    }
    // int n = A.size();
    if(A[n-2]>A[n-1])
    {
        cnt += abs(A[n-2] - A[n-1]);
    }
    return cnt;
}

int main() 
{ 
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Maximum water that can be accumulated is "
        << ans(arr, n);  
} 