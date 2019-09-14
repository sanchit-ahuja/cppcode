#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set <int> a;
    unordered_set <int> b;
    int an;
    cin>>an;
    int x;
    for(int i = 0; i < an; i++)
    {
        int y;
        cin>>y;
        a.insert(y);
    }
     int bn;
    cin>>bn;
    for(int i = 0; i < bn; i++)
    {
        int x;
        cin>>x;
        b.insert(x);
    }
    vector<int> ans;
    for(auto k = a.begin(); k!=a.end();k++)
    {
        for(auto j = b.begin(); j!=b.end();j++)
        {
            int l = *k + *j;
            int f = *k;
            int c = *j;
            if(a.find(l) == a.end() && b.find(l) == b.end())
            {
                ans.push_back(f);
                ans.push_back(c);
                break;                
            }
        }
    }
    cout<<ans[0]<< " " <<ans[1]<<endl;
}