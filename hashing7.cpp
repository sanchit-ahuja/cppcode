string Solution::fractionToDecimal(int A, int B) {
    long long flag1 = 0;
    A = long long(A);
    B = long long(B);
    if((A < 0 &&B > 0)||(A > 0 && B < 0))
    {
        flag1 = 1;
    }
    // else if (A<0 && B < 0 || A>0 && B > 0)
    // {
    //     flag1 = 0;
    // }
    A = abs(A);
    B = abs(B);
    
    long long q = A/B;
    long long rem = A%B;
    unordered_map <long long,long> m;
    string rec = "";
    while(rem!=0 && m.find(rem)==m.end())
    {
        m[rem] = rec.length();
        rem = 10*rem;
        long long res = rem/B;
        rec += to_string(res);
        rem = rem % B;
    }
    if (rem == 0 &&flag1 == 0)
    {
        long long k = A%B;
        string f;
        while(k)
        {
            k = k*10;
            long long j = k/B;
            f +=to_string(j);
            k = k%B;
        }
        if(f!="")
        {string ans = to_string(q) + "." + f;
        return ans;}
        else
        {
            string ans = to_string(q);
            return ans;
        }
    }
    else if(rem == 0 &&flag1 == 1)
    {
        
        long long k = A%B;
        string f;
        while(k)
        {
            k = k*10;
            long long j = k/B;
            f +=to_string(j);
            k = k%B;
        }
        if(f!="")
        {string ans = "-"  + to_string(q) + "." + f;
        return ans;}
        else
        {
            string ans = "-"  + to_string(q);
            return ans;
        }
        
    }
    else if(rem && flag1 == 0)
    {
        string s = to_string(q) + "." + "(" + rec.substr(m[rem]) + ")";
        return s;
    }
    else
    {
        string s = "-" + to_string(q) + "." + "(" + rec.substr(m[rem]) + ")";
        return s;
    }
}
