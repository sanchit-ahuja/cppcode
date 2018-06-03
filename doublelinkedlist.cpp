#include<iostream>
using namespace std;

class Link{
    public:
    int data;
    Link* next;
    Link* prev;
    Link(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
     void displayLink()
    {
        cout << data << " ";
    }
};

class LinkedList{
    private:
    Link* head;
    Link* tail;
    public:
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    bool isEmpty()
    {
        return head==NULL;

    }
    void insertFirst(int d)
    {
        Link *tmp=new Link( d);
        if(isEmpty())
            tail=tmp;
        else
            head->prev=tmp;
        tmp->next=head;
        head=tmp;

    }
    void insertLast(int d)
    {
        Link *tmp=new Link(d);
        if(isEmpty())
            head=tmp;
        else
            tail->next=tmp;
            tmp->prev=tail;
        tail=tmp;
    }
    void removeFirst()
    {
        Link *tmp=head;
        if(head->next==NULL)
            tail=NULL;
        else
            (head->next)->prev=NULL;
        head=head->next;
        delete tmp;

    }
    void removeLast()
    {
        Link *tmp=tail;
        if(tail->prev==NULL)
            head=NULL;
        else
            (tail->prev)->next=NULL;
        tail=tail->prev;
        delete tmp;
    }
    bool insertAfter(int key,int data)
    {
        Link *curr=head;
        while(curr->data!=key)
        {
            curr=curr->next;
            if(curr==NULL)
                return false;
        }
        Link *tmp=new Link(data);
        if(curr==tail)
        {
            tail->next=tmp;
            tmp->prev=tail;
            tail=tmp;
        }
        else
        {
            tmp->next=curr->next;
            curr->next->prev=tmp;
        }
        tmp->prev=curr;;
        curr->next=tmp;
        return true;

    }
    bool removeKey(int key)
    {
        Link *curr=head;
        while(curr->data!=key)
        {
            curr=curr->next;
            if(curr==NULL)
                {return false;}
        }

        if(curr==head)
        {
            head=curr->next;
        }
        else
            {(curr->next)->prev=curr->prev;
            }delete curr;
        return true;
    }

    void displayforward()
    {
        Link* curr=head;
        while(curr!=NULL)
        {
            curr->displayLink();
            curr=curr->next;
        }
    }


};

int main()
{
    LinkedList list;
    
    list.insertFirst(3);
    list.insertFirst(7);
    list.insertLast(4);
    list.insertLast(9);
    list.removeFirst();
    list.displayforward();
    
}

