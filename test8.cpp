#include<iostream>
using namespace std;

int main()
{
    int a=3;
    int b=4;
    int c=5;
    while((a+b+c!=1000)&&(c*c!=a*a+b*b))
    {
        a++;
        b++;
        c++;
        cout<<a<<b<<c<<endl;
    }

    
}