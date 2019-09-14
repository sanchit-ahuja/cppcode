#include<bits/stdc++.h>
using namespace std;

bool issub(int arr1[], int arr2[], int m, int n)
{
    set <int> set1;
    set <int> set2;
    set <int> set3;
    for(int i = 0; i < m;i++)
    {
        set1.insert(arr1[i]);
    }
    for(int i = 0; i < n;i++)
    {
        set2.insert(arr2[i]);
    }
    set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),insert_iterator<set<int>>(set3,set3.begin()));
    if(set3 == set2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7}; 
        int arr2[] = {231,32,313,12}; 
          
        int m = 6;
        int n = 4;
        cout<<issub(arr1,arr2,m,n)<<endl;
}