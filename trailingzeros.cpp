#include<bits/stdc++.h>
using namespace std;

int trailingZeros(int A)
{
    int count =0;
    while(A)
    {
        count += floor(A/5);
        A = A/5;
    }
    return count;
}

int main()
{
    cout<<trailingZeros(100)<<endl;
}