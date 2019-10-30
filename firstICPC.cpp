#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string n;
        cin>>n;
        int mn=stoi(n);
        for(int i=0;i<n.size();i++)
        {
            string temp=n;
            temp.erase(i,1);
            mn=min(mn,stoi(temp));
        }
        cout<<mn<<endl;
    }
}