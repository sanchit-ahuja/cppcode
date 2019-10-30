#include<bits/stdc++.h>
using namespace std;

int tree[INT_MAX];
int A[INT_MAX];


void build(int node,int start,int end)
{
    if(start==end){
        tree[node]=A[start];
        return;
    }
    else
    {
        int mid=(start+end)/2;
        //left side 
        build(2*node,start,mid);
        //right side
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    
}

int query(int node, int start, int end, int l, int r){
    if(r<start||l>end){
        return 0;
    }
    if(l<=start && end<=r){
        //range represented completely inside the given range
        return tree[node];
    }
    int mid=(start+end)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,end,l,r);
    return p1+p2;

}

void update(int node, int start,int end, int val,int idx)
{
    if(start==end){
        A[idx]+=val;
        tree[node]+=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(start<=idx && idx<=mid)
        {
            update(2*node,start,mid,val,idx);
        }
        else{
            update(2*node+1,mid+1,end,val,idx);
        }
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    
}


