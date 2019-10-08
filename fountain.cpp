#include<bits/stdc++.h>
using namespace std;

pair<int,int>func(pair<int,int> &a, pair<int,int> &b){
    int a1=a.first;
    int b1=a.second;
    int a2=b.first;
    int b2=b.second;
    //case 1 (4,6) (5,8)
    if(a1<=a2 && b1<=b2 && a2<=b1){
        return make_pair(a1,b2);
    }
    if(a1>=a2 && b1>=b2 && a2>=b1){
        return make_pair(a2,b1);
    }
    //case 2 (5,10) (6,9)
    if(a1==-2){
        return b;
    }
    if(a1<=a2&&a1<=b2&&b1>=a2&&b1>=b2){
        return a;
    }

    return make_pair(-1,-1);
}

int recur(vector<int> &arr,int i,int l,int r)
{
    if(i==arr.size()){
        if(l==0 && r==arr.size()-1){
            return 0;
        }
        else{
            return INT_MAX-100000;
        }
        
    }
    int n=arr.size();
    int m=INT_MAX;
    //take fountain
    int l1=max(i-arr[i],0);
    int r1=min(i+arr[i],n-1);
    pair<int,int>p1=make_pair(l1,r1);
    pair<int,int>p2=make_pair(l,r);
    pair<int,int>p3;
    if(l1>=l){
        p3=func(p2,p1);
    }
    else{ 
        p3=func(p1,p2);
    }
    if(p3.first==-1 && p3.second==-1 ){
        return INT_MAX-100000;
    }
    else{
        m=1+recur(arr,i+1,p3.first,p3.second);
    }
    //don't take the fountain
    int n2=recur(arr,i+1,l,r);
    // cout<<n2<<endl;
    return min(m,n2);
}

int main()
{
    pair<int,int>p1=make_pair(0,0);
    pair<int,int>p2=make_pair(0,1);
    pair<int,int>p3=func(p1,p2);
    // cout<<p3.first<<" "<<p3.second<<endl;
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(9);

    cout<<recur(arr,0,-2,-2)<<endl;


}