#include<iostream>
using namespace std;

int main()
{
    int num;
    cin>>num;
    int ig=0;
    while(num)
    {
        if(num&1)
            ig++;
        num=num>>1;
    }
    cout<<ig;
}