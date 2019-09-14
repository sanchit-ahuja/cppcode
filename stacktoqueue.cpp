#include<iostream>
#include<stack>

using namespace std;
stack<int> head,tail;
void enqueue(int x)
{
    tail.push(x);
    if(head.empty())
        while(!tail.empty())
        {
            head.push(tail.top());
            tail.pop();
        }

}

void dequeue()
{
    head.pop();
}



int main()
{   
    enqueue(4);
    enqueue(5);
    enqueue(6);
    cout <<head.top() <<endl;
    return 0;
}