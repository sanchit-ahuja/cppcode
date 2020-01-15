#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> s;
        for(int i=0;i<n;i++)
        {
            string k;
            cin>>k;
            s.push_back(k);
        }
        int cnt = 0;
        for(int i=0;i<10;i++)
        {
            int numones = 0;
            for(int j=0;j<n;j++)
            {
                string t = s[j];
                if(t[i] == '1')
                {
                    numones += 1;
                }
            }
            if(numones%2)
            {
                cnt +=1;
            }
        }
        cout<<cnt<<endl;
    }
}