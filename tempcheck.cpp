#include<bits/stdc++.h>
using namespace std;

int main() {
    for(int i = 1;i<26;i++) {
        // cha;
        char x = 'l' + i<123?'l'+i:('l'+i)%123 + 'a';
        cout<<x<<endl;
    }
    // cout<<(char)('h' + 1)<<endl;
}