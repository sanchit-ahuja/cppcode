#include<iostream>
using namespace std;

int main()
{
    int x1,x2,x3,y1,y2,y3,tc,t,count=0;
    cin >> tc;
    while(tc--)
    {
        cin >>x1>> y1>> x2>> y2>> x3>> y3;
        if((x1-x2)*(x2-x3)+(y1-y2)*(y2-y3)==0)
            count++;
        else if((x1-x2)*(x3-x1)+(y1-y2)*(y3-y1)==0)
            count++;
        else if((x3-x1)*(x2-x3)+(y3-y1)*(y2-y3)==0)
            count++;
    }
    cout<<count;
    return 0;

}
