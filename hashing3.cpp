#include<bits/stdc++.h>
using namespace std;

bool check(int arr[], int n, int k)
{
    set <int> s1;
    for(int i = 0;i<n;i++){
        if(s1.find(arr[i])!=s1.end())
        {
            return true;
        }
        s1.insert(arr[i]);
        if(i >= k)
        {
            s1.erase(arr[i - k]);
        }
    }
    return false;
}

int main()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (check(arr, n, 3)) 
        cout << "Yes"; 
    else
        cout << "No"; 
}