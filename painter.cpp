#include<bits/stdc++.h>
using namespace std;

bool isPossible(int x, vector<int> v, int k)
{
    int c = 1;
    int cur = 0;
    for(int i = 0; i< v.size(); i++)
    {
        cur+=v[i];
        if(cur>x)
        {
            c++;
            cur = v[i];
        }
    }
    if(c<= k )
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    
}