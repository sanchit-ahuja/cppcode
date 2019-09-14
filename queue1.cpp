#include<iostream>
#include<vector>

using namespace std;

class Queue
{
    private:
        int n;
        vector<int> queue;
        int head;
        int tail;
        int items;
    public:
   Queue(int s) : n(s), head(0), tail(-1), items(0)
    { queue.resize(n); }

    void enqueue(int j)
    {
        if (tail==n)
            tail=-1;
        queue[++tail]=j;
        items++;
    }
    int remove()
    {
        int temp=queue[head++];
        if (head==n)
            head=0;
        items--;
        return temp;
    }
    int peekfront()
    {
        return queue[head];

    }
    bool isEmpty()
    {
        return(items==0);

    }
    bool isFull()
    {
        return(items==n);

    }
    int size()
    {
        return items;
    }
};

int main()
    {
    Queue queue(5);
    queue.enqueue(2);
    queue.enqueue(4);
    queue.enqueue(3);
    queue.enqueue(6);
    queue.enqueue(8);
    while(!queue.isEmpty())
    {
        int n=queue.remove();
        cout << n << " ";

    }
    cout << endl;
    return 0;
    }
