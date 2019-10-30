#include<bits/stdc++.h>
using namespace std;

int func(string s){
    unordered_set<char>a;
    int start=0;
    int end=0;
    int len=INT_MIN;
    // a.insert(s[0]);
    // a.insert(s[1]);
    // end=2;
    while(end<s.size()){
        if(a.find(s[end])==a.end())
            {a.insert(s[end]);}
        end++;
        while(a.size()>2){
            a.erase(s[start]);
            start++;
            // cout<<start<<endl;
            len=max(len,end-start);
        }
    }
    return len;
}

int main(){
    string s="AAAAAA";
    cout<<func(s)-1<<endl;

}