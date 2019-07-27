#include<bits/stdc++.h>
using namespace std;

bool find(int arr1[],int arr2[],int arr3[],int n,int m, int k, int sum)
{
    unordered_set <int> s1;
    for(int i = 0; i< n; i++)
    {
        s1.insert(arr1[i]);
    }
    for(int i = 0; i < m;i++)
    {
        for(int j = 0; j< k;j++)
        {
            if(s1.find(sum - arr2[i] - arr3[j])!=s1.end())
            {
                return 1;
            }
        }
    }
    return 0;
}