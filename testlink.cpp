#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

void push(struct node **head,int data)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=(*head);
    (*head)=new_node;
}

void deleteany(struct node **head,int key)
{
    struct node *temp=*head,*prev;
    if(temp!=NULL&& temp->data==key)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)return;
    prev->next=temp->next;
    free(temp);


}

void print(struct node *node)
{
    while(node!=NULL)
    {
        cout<< node->data<< endl;
        node=node->next;
    }
}

int main()
{
    struct node* head=NULL;
    push(&head,7);
    push(&head,4);
    push(&head,21);
    print(head);
    return 0;
}