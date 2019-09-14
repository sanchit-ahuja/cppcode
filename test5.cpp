#include<iostream>
using namespace std;

int main()
{   
    long long prod=0;
    for(int i=1;i<=100;i++)
        for(int j=i+1;j<=100;j++)
            prod=prod+i*j;
    long long fin=2*prod;
    cout<<fin <<endl;
}