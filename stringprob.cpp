#include<iostream>
#include<iostream>
using namespace std;

int main()
{
    long long r,g,b;
    cin>>r>>g>>b;
    long long turns=0;
    long long x=std::min(g,b);
    turns=turns+std::min(r,x);
    r-=turns;
    g-=turns;
    b-=turns;
    turns=turns+(r+g+b)/2+(r+g+b)%2;
    cout<<turns<<endl;
    return 0;

}