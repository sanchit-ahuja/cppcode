#include<iostream>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long arr[n];
        for(long long i=0;i<n;i++)
        {
            cin>>arr[i];

        }
        long long sum1=0;long long sum2=0; long long motu=0;long long patlu=n-1;
        while(motu<=patlu)
        {
            if(sum1<=2*sum2)
            {
                sum1+=arr[motu];
                motu++;
            }
            else if(sum1>2*sum2)
            {
                sum2+=arr[patlu];
                patlu--;
            }
        }
        cout<< motu<< " "<< patlu<<endl;
        if(motu>n-motu)
        {
            cout<<"Motu"<<endl;
        }
        else if(motu<n-motu)
        {
            cout<<"Patlu"<<endl;
        }
        else
        {
            cout<<"Tie"<<endl;
        }
    }
}