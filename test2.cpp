#include<iostream>
using namespace std;

long long int recur(long long int n)
{
    long long int f[n+1];
     long long int i;
    f[0]=0; f[1]=2;
    for(i=2;i<=n;i++)
        f[i]=4*f[i-1]+f[i-2];
    return f[n];
}

int main()
{   
    long long int limit=4000000;
    long long int i=2;
    long long int sum=0;
    while(recur(i)<=limit)
        {
            sum=sum+recur(i);
            i++;
        }
        cout<<sum<<endl;

}