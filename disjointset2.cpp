#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define loop(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b,c) for(int i=a; i<b; i+=c)
#define brep(i,a,b,c) for(int i=a; i>b; i-=c)
#define tc(t) int t; cin>>t; while(t--)
#define sz(v) int((v).size())
#define pb push_back

class Node {
    public:
        int data;
        Node* parent;
        int rank;
        Node(int val) {
            data = val;
            parent = NULL;
            rank = -1;
        }
};
map<int,Node*>umap;
void makeset(int data) {
    Node* temp = new Node(data);
    temp->parent = temp;
    umap[data] = temp;

}

Node* findparent(Node* val) {
    Node* parent = val->parent;
    if(parent == val) {
        return parent;
    }
    val->parent = findparent(val->parent);
    // return findparent(parent); //This will not result in path compression
    return val->parent; //When coming out of the recursion for all the parent will be set as the first one
}

void union_set(int a, int b) {
    Node* p1 = findparent(umap[a]);
    Node* p2 = findparent(umap[b]);
    if(p1->data == p2->data) {
        return;
    }
    if(p1->rank>=p2->rank) {
        p1->rank = p1->rank == p2->rank?p1->rank+1:p1->rank;
        p2->parent = p1;
    }
    else {
        p1->parent = p2;
    }
}
vector<int>parent;

int find(vector<int>&parent,int i) {
    if(parent[i] == -1) {
        return i;
    }
    int num= find(parent,parent[i]);
    return num;
} 

void uni(vector<int>&parent, int m, int n) {
    int p1 = find(parent,m);
    int p2 = find(parent,n);
    if(p1 != p2) {
        parent[p2] = p1;
    }
}


int main() {
    
    return 0;
}
