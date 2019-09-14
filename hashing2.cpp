#include<bits/stdc++.h> 
using namespace std; 
  
/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
/* A utility function to insert a node at the 
   begining of a linked list*/
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = 
        (struct Node*) malloc(sizeof(struct Node)); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
}

void storeele(Node* head1, Node* head2, unordered_map<int,int>&eleocc)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1||temp2)
    {
        if(temp1)
        {
            eleocc[temp1->data]++;
            temp1 = temp1->next;
        }

        if(temp2)
        {
            eleocc[temp2->data]++;
            temp2 = temp2->next;
        }
    }
}


Node *getintersection(unordered_map<int,int>&eleocc)
{
    Node* result;
    for(auto it = eleocc.begin(); it!=eleocc.end();it++)
    {
        if(it->second == 2)
        {
            push(&result,it->first);
        }
    }
}

struct Node *getUnion(unordered_map<int, int> eleOcc) 
{ 
    struct Node *result = NULL; 
  
    // Push all the elements into the resultant list 
    for (auto it=eleOcc.begin(); it!=eleOcc.end(); it++) 
        push(&result, it->first); 
  
    return result; 
} 
  
  