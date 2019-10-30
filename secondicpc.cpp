#include <bits/stdc++.h>
using namespace std;
 
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define f first
#define s second
#define pii pair<LL, LL>
#define ll long long int
#define ld long double
#define si set<int>
#define mii map<int,int>
#define vii vector<pair<int,int> >
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int> >
#define all(v) v.begin(),v.end()
#define fr(i,n) for(int i = 0; i < n; ++i)
#define fr1(i,n) for(int i=1;i<=n;i++)
#define pb push_back
// #define mp make_pair
#define nu 100001
#define mod 1000000007
 
 
 int check(pair<int,int> a, pair<int,int>  b)
 {
     int x1,x2,y1,y2;
     x1  = a.first; y1 = a.second;
     x2 = b.first ; y2 = b.second;


    if(x2<=y1)
        return 1;
    
    if(y2<=y1)
        return 1;

    return 0;    

 }
 
 
int main()
{
 
    int t,n,a,b,c,flag;
    vector<pair<int,int>> t1,t2;
    map <int,vector<pair<int,int>>> mp;

    cin>>t;
    while(t--)
    {
        cin>>n;
        flag=0;
        mp.clear();


        while(n--)
        {
            cin>>a>>b>>c;

            if(mp.find(c)==mp.end())
                mp[c] = t1;

            mp[c].push_back(make_pair(a,b));

        }

        for(auto itr = mp.begin();itr!=mp.end();itr++)
        {

        
            t2 = itr->second;
            if(t2.size()<=2)
                continue;

            sort(t2.begin(),t2.end());

            for(int i=0;i<t2.size()-2;i++)
            {
               
               if(check(t2[i],t2[i+1])+check(t2[i+1],t2[i+2])+check(t2[i],t2[i+2])==3)
                {

                    cout<<"NO"<<endl;
                    flag=1;
                    break;
                }

            }

            if(flag==1)
                break;

        }


        if(flag==0)
            cout<<"YES"<<endl;
    }
 
}
 
 
 




