#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long x[n],y[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }
        long long maxx=-1,maxy=-1,minx=10000000,miny=10000000;
        for(int i=0;i<n;i++)
        {
            if(maxx<x[i])
            {
                maxx=x[i];
            }
            if(maxy<y[i])
            {
                maxy=y[i];
            }
            if(miny>y[i])
            {
                miny=y[i];
            }
            if(minx>x[i])
            {
                minx=x[i];
            }
        }
        if(maxx-minx>maxy-miny)
        {
            cout<<(maxx-minx)*(maxx-minx)<<endl;
        }
        else
        {
            cout<<(maxy-miny)*(maxy-miny)<<endl;
        }
    }
}