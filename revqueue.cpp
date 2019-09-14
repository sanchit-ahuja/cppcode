#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int>& q)
{   
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

void print(queue<int> &q)
{
    while(!q.empty())
    {
        cout<< q.front() << " ";
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int tc;
    cin >> tc;
    while(tc--!=0)
    {
        queue<int> q;
        int n;
        int arr[n];
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            q.push(arr[i]);
        }
        reverse(q);
        print(q);
        


    }
    return 0;
}