#include<bits/stdc++.h>
using namespace std;

int dictionaryContains(string word) 
{ 
    string dictionary[] = {"mobile","samsung","sam","sung", 
                            "man","mango","icecream","and", 
                             "go","i","like","ice","cream"}; 
    int size = sizeof(dictionary)/sizeof(dictionary[0]); 
    for (int i = 0; i < size; i++) 
        if (dictionary[i].compare(word) == 0) 
           return true; 
    return false; 
} 
int wordbreak(string str, int dp[], int index)
{
    int size = str.size();
    if(index == size)
    {
        return true;
    }
    if(dp[index] == -1)
    {
        for(int i = 1; i <= size; i++)
            {
                dp[index] = (dictionaryContains(str.substr(0,i)) && wordbreak(str.substr(i,size - i),dp,index+1));
                    
            }
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    int ans;
    return ans = dp[index];
    
}

int main() 
{ 
    int dp[INT_MAX];
    memset(dp,-1,sizeof(dp));
    wordbreak("ilikesamsung",dp,0)? cout <<"Yes\n": cout << "No\n"; 
    // wordbreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
    // wordbreak("")? cout <<"Yes\n": cout << "No\n"; 
    // wordbreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
    // wordbreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
    // wordbreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
    return 0; 
} 