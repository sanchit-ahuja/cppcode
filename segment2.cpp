#include<bits/stdc++.h>
using namespace std;

vector<int>tree(10,0);
// int A[5];

void build(vector<int>&a,int node,int start,int end)
{
    if(start==end){
        tree[node]=a[start];
    }
    else{
        int mid=(start+end)/2;
        //recur on left side
        build(a,2*node,start,mid);
        //recur on right side
        build(a,2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

int query(int node, int start,int end,int l,int r)
{
    //given query out of bounds
    if(l>end||r<start){
        return 0;
    }
    if(l<=start && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    return p1+p2;
}

// void update(int node,int start,int end,int idx, int val)
// {
//     if(start==end){
//         A[idx]+=val;
//         tree[node]+=val;
//     }
//     else
//     {
//         int mid=(start+end)/2;
//         if(idx>=start && idx<=end){
//             update(2*node,start,mid,idx,val);
//         }
//         else{
//             update(2*node+1,mid+1,end,idx,val);
//         }
//         tree[node]=tree[2*node]+tree[2*node+1];
//     }
    
// }


int main()
{
   vector<int> a = {1,3,-2,8,-7};
   int n = a.size();
   build(a,1,0,n-1);
   cout<<query(1,0,2,0,n-1)<<endl;
     
}