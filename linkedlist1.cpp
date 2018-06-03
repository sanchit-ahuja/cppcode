#include<iostream>
using namespace std;

class Link
{
    public:
    int idata;
    Link* pnext;
    Link(int d)
    {
        idata=d;
        pnext=NULL;
    }
    void displayLink()
    {
        cout << idata << endl;
    }
};

class LinkedList
{
    private:
    Link* head;
    public:
    LinkedList()
    {
        head=NULL;
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    void insertFirst(int data)
    {
        Link* node=new Link(data);
        node->pnext=head;
        head=node;
    }
    void removeFirst()
    {
        Link *temp=head;
        head=head->pnext;
        delete temp;
    }
    bool removeany(int key)
    {
        Link* temp=head;
        Link* prev=head;
        while(temp->idata!=key)
        {
            prev=temp;
            temp=temp->pnext;
        }
        if(temp!=NULL&&temp->idata==key)
        {
            head=head->pnext;
        }
        else
            prev->pnext=temp->pnext;
        delete temp;
        return true;
            

    }
    void displaylist()
    {
        while(head!=NULL)
        {
            head->displayLink();
            head=head->pnext;
        }
    }
};

int main()
{
    LinkedList list;
    list.insertFirst(22);
    list.insertFirst(23);
    list.insertFirst(24);
    list.displaylist();
    return 0;

}