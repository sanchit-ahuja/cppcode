#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long x,y;
        cin>>x>>y;
        if(y<=x)
        {
            cout<<"YES"<<endl;
        }
        else if(x==1||x==3||x==2 && y!=1 && y>3)
        {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }
}