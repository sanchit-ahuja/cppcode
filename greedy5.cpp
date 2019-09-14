#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        std::string s;
        cin>>s;
        string res="";
        int len=s.size();
        for(int i=0;i<len;i++)
        {
            if(s[i]!=s[i+1])
            {
                res+=s[i];
            }
        }
        cout<<res<<endl;

        
    }
}