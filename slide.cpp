#include<bits/stdc++.h>
using namespace std;

int window(int arr[],int n, int k)
{
    int max_sum = 0;
    for(int i = 0; i < k; i++)
    {
        max_sum+= arr[i];
    }
    int window_sum = max_sum;
    for(int i = k; i< n; i++)
    {
        window_sum += arr[i] - arr[i-k];
        max_sum = max(window_sum,max_sum);
    }
    return max_sum;
}