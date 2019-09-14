#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long neg = 0;
    long long zero = 0;
    long long negsum = 0;
    long long possum = 0;
    long long zerosum = 0;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin>>x;
        if(x < 0)
        {
            neg += 1;
            negsum += abs(x+1);
            // cout<<negsum<<'d'<<endl;
        }
        else if(x == 0)
        {
            zero += 1;
            zerosum += 1;
        }
        else if(x > 0)
        {
            /* code */
            possum += (x - 1);
        }
    }
    // cout<<possum<<" "<<negsum<<" "<<zerosum;
    long long total = possum + negsum + zerosum;
    if(neg%2 != 0 && zero == 0)
    {
        total += 2;
    }
    cout<<total<<endl;
}