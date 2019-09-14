#include<iostream>
#include<bits/stdc++.h>
using namespace std;
queue<int> q1, q2;

int n=0;
void push(int x)
{
    n++;  
    q2.push(x);
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
        }
    queue<int> q;
    q=q1;
    q1=q2;
    q2=q;
}

void pop()
{
    if(q1.empty())
        return;
    q1.pop();
    n--;
}

int top()
{
    if (q1.empty())
        return -1;
    return q1.front();
}

int size()
{
    return n;
}


int main()
{
    push(1);
    push(2);
    push(3);

    cout<< "current size: " << size() << endl;
    cout<< top() << endl;
    pop();
    cout<< top() << endl;
    pop();
    cout<< "current size: " << size() << endl;


}