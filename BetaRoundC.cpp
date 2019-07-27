#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unordered_map <string,int> umap;
    for(int i = 0;i<n;i++)
    {
        string s;
        cin>>s;
        if(umap.find(s) == umap.end())
        {
            umap[s] += 1;
            cout<<"OK"<<endl;
        }
        else
        {
            string c = to_string(umap[s]);
            string k = s + c;
            cout<<k<<endl;
            umap[s]+=1;
        }
        

    }
    while(l--)
    {
        for(int i = 6;i<8;i++)
        {
            for(int j = k;j<k+2;j++ )
            {
                if(sq.find(A[i][j])==sq.end() &&A[i][j]!='.')
                {
                    sq[A[i][j]]+=1;
                }
                else
                {
                    return 0;
                }
            }
        }
        k+=3;
    }
    
}