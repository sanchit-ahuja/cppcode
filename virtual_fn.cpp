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

class MyBase{
    public:
    void show() {
        cout<<"Base class show fn"<<endl;
    }
    virtual void print(){
        cout<<"base print called"<<endl;
    }
};

class MyDerived: public MyBase{
      void show() {
        cout<<"derived class show fn"<<endl;
    }
     void print(){
        cout<<"derived print called"<<endl;
    }
};

int main() {
    MyBase *baseptr; //ptr
    // same ptr to derive multiple derived obj
    MyDerived derivedobj; //obj
    baseptr = &derivedobj; //passing the address to the baseptr
    // runtime polymorphism
    baseptr->print(); //derived class print fun called
    baseptr->show(); //base class
    // baseptr is pointing to the derived class
    return 0;
}
