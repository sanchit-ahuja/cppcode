#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<char,int> umap;
    umap['B'] = 1;
    umap['B'] -= 1;
    cout<<umap.count('B')<<endl;
    // cout<<umap['B'];
    if(umap.find('B')!=umap.end()) {
        cout<<'d';
    }
    // cout<<umap.find('B')!=umap.end()<<endl;
}