#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define loop(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b, c) for (int i = a; i < b; i += c)
#define brep(i, a, b, c) for (int i = a; i > b; i -= c)
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define sz(v) int((v).size())
#define pb push_back

vector<int>parent;
vector<int>size;
// void make_set(int v) {
//     parent[v] = v;
// }
int find_set(int a) {
    if(parent[a] == a) {
        return parent[a];
    }
    return parent[a] = find_set(parent[a]);

}

void union_set(int a, int b) {
    a = find_set(a); //parent of a
    b = find_set(b); //parent of b

    if(a != b) { //if they don't have the same parent m
        parent[b] = a; 
    }
}

void union_by_size(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(size[a]<size[b]) {
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
    }
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int main()
{
    
    return 0;
}

/* void size(int a, int b) {
    int a = find_set(a);
    int b = find_set(b);
    if(a!=b) {
        if(size[a] < size[b]) {
            swap(a,b);
        }
        parent[b] = a;
        size[a]+=size;
    }
} */