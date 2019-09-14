#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long x,y,z;
    cin>>x>>y>>z;
    long long coco = (x+y)/z;
    if(coco==(x/z)+(y/z))
    {
        cout<<coco<<" "<<0<<endl;
    }
    else
    {
        /* code */
        long long give = min(z - x%z,z - y%z);
        cout<<coco<<" "<<give<<endl;
    }
    
    

}