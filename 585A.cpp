#include<bits/stdc++.h>
using namespace std;
int main(){
    int a1,a2,k1,k2,n;
    cin>>a1;
    cin>>a2;
    cin>>k1;
    cin>>k2;
    cin>>n;
    int x=min(k1,k2);
    int cntam=0;
    int cntbm=0;
    int ax,kx,ay,ky;
    if(k1<k2){
        ax=a1;
        kx=k1;
        ay=a2;
        ky=k2;
    }
    else{
        ax=a2;
        kx=k2;
        ay=a1;
        ky=k1;
    }
        while(ax){
            n-=kx;
            if(n<0){
                break;
            }
            cntam+=1;
            ax--;
        }
        while(ay){
            n-=ky;
            if(n<0){
                break;
            }

            cntbm+=1;
            ay--;
            
        }
        int maxi=cntam+cntbm;
        if(k1<k2){
        ax=a1;
        kx=k1;
        ay=a2;
        ky=k2;
    }
    else{
        ax=a2;
        kx=k2;
        ay=a1;
        ky=k1;
    }
    int cntami=0;
    int cntbmi=0;
    // cout<<ay<<'s'<<endl;
    while(ay){
            n-=ky;
            if(n<0){
                break;
            }

            cntbmi+=1;
            ay--;
            
        }
           while(ax){
            n-=kx;
            if(n<0){
                break;
            }
            cntami+=1;
            ax--;
        }

    cout<<cntami+cntbmi<<endl;
}