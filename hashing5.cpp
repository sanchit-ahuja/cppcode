#include<bits/stdc++.h>
using namespace std;

void findpairs(int arr1[],int arr2[],int m,int n,int x)
{
    unordered_set<int>s1;
    for(int i = 0; i < m;i++)
    {
        s1.insert(arr1[i]);
    }
    for(int j = 0; j<n;j++)
    {
        if(s1.find(x - arr2[j])!=s1.end())
        {
            cout << x - arr2[j] << " "<< arr2[j]<<endl;
        }
    }
}

int main() 
{ 
    int arr1[] = {1, 0, -4, 7, 6, 4}; 
    int arr2[] = {0 ,2, 4, -3, 2, 1}; 
    int x = 8; 
    int n = sizeof(arr1)/sizeof(int); 
    int m = sizeof(arr2)/sizeof(int); 
    findpairs(arr1, arr2, n, m, x); 
    return 0; 
} 