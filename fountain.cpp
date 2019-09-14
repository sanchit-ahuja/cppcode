#include<bits/stdc++.h>
using namespace std;

pair<int,int>func(pair<int,int> &a, pair<int,int> &b){
    int a1=a.first;
    int a2=a.second;
    int b1=b.first;
    int b2=b.second;
    if(b1>=a1 && a1>=b2 && b2>=a2 && a2<=b1){
        return make_pair(a1,b2);
    }
    else if(b1<=a1 && a1<=b2 && a2<=b2 && a2>=b1){
        return make_pair(b1,a2);
    }
    return make_pair(-1,-1);

}

int recur(vector<int> &arr,int i,int l,int r)
{
    if(i==arr.size()){
        return 0;
    }
    int n=arr.size();
    int m=INT_MAX;
    //take fountain
    int l1=max(i-arr[i],0);
    int r1=min(i+arr[i],n-1);
    pair<int,int>p1=make_pair(l1,r1);
    pair<int,int>p2=make_pair(l,r);
    pair<int,int>p3=func(p1,p2);
    if(p3.first==-1 && p3.second==-1){
        return INT_MAX-100000;
    }
    else{
        m=1+recur(arr,i+1,l1,r1);
    }
    //don't take the fountain
    int n2=recur(arr,i+1,l,r);
    return min(m,n2);
}

int main()
{
    pair<int,int>p1=make_pair(5,6);
    pair<int,int>p2=make_pair(3,8);
    pair<int,int>p3=func(p1,p2);
    cout<<p3.first<<" "<<p3.second<<endl;
}