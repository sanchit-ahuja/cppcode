#include<bits/stdc++.h>
using namespace std;
int cnt;
void issum(vector<int>&arr,int i,int sum)
{
    if(sum==0){
        cnt+=1;
        return;
    }
    if(i==arr.size() && sum!=0){
        return;
    }
    if(sum<arr[i]){
        issum(arr,i+1,sum);
        return;
    }
    issum(arr,i+1,sum);
    issum(arr,i+1,sum-arr[i]);
    
}

int main()
{
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(11);
    // int cnt=0;
    issum(arr,0,13);
    cout<<cnt<<endl;


}