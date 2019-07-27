    int Solution::isValidSudoku(const vector<string> &A) {
        unordered_map <char,int> hori;
        unordered_map <char,int> verti;
        unordered_map <char,int> sq;
        for(int i = 0; i<A.size();i++)
        {
            string s = A[i];
            for(int j = 0;j<s.length();j++)
            {
                if(hori.find(s[i])==hori.end()&&s[i]!='.')
                {
                    hori[s[i]] += 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<A.size();j++)
            {
                if(verti.find(A[j][i]) == verti.end() && A[j][i] != '.')
                {
                    verti[A[j][i]] += 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        int l = 3;
        int k = 0;
        while(l--)
        {
            for(int i = 0;i<2;i++)
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
            k += 3;
        }
        l = 3;
        k = 0;
        while(l--)
        {
            for(int i = 3;i<5;i++)
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
        l = 3;
        k = 0;
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
        
        return 1;

    }
