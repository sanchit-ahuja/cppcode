    #include<bits/stdc++.h>
    using namespace std;

    int main()
    {
        int q;
        cin>>q;
        while(q--)
        {
            long long a,b,n,s;
            cin>>a>>b>>n>>s;
            double k = double(double((s-b))/double(n));
            double f = (double)(s)/(double(n));
            long long l = ceil(k);
            long long m = ceil(f);
            // cout<<k<<" "<<f<<endl;
            if(a>=l && abs(l-m)>=1)
            {
                cout<<"YES"<<endl;
            }
            else{   
                cout<<"NO"<<endl;
            }

        }
    }