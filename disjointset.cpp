#include<bits/stdc++.h>
using namespace std;



struct Node {
    int data;
    int rank;
    Node* parent;
};

map <int,Node*> m;

void makeset(int data)
{
    Node* temp = new Node();
    temp->data= data;
    temp->parent = temp;
    temp->rank = -1;
    m[data] = temp;
}

//Find the representative (Root node) and does path compression as well

Node* findset(Node* node)
{
    Node* parent = node->parent;
    if(parent == node)
    {
        return parent;
    } // Root pointer pointing to itself
    node->parent = findset(node->parent);
    return node->parent;
}

void uni(int data1, int data2)
{
    Node* temp2 = m[data2];
    Node* temp1 = m[data1];
    Node* parent1 = findset(temp1);
    Node* parent2 = findset(temp2);
    if(parent1->data == parent2->data)
    {
        return;
    }
    if(parent1->rank >= parent2->rank)
    {
        if(parent1->rank == parent2->rank)
        {
            parent1->rank = 1 + parent1->rank;
        }
        parent2->parent = parent1;
    }
    else
    {
        parent1->parent = parent2;
    }
    
}

int kruskalMST()
{
    int mst_wt = 0;
    
}

int main()
{
    makeset(1);
    makeset(2);
    makeset(3);
    makeset(4);
    makeset(5);
    makeset(6);
    makeset(7);
    uni(1,2);
    uni(2,3);
    uni(4,5);
    uni(6,7);
    uni(5,6);
    uni(3,7);
    Node* k = m[5];
    cout<<findset(k)->data<<endl;
}