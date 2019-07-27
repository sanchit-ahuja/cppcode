#include<bits/stdc++.h>
using namespace std;
 
 struct Node{
     int data;
     Node* left;
     Node* right; 
 };

Node* NewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode; 
}

bool search(Node* root, int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data){return true;}
    else if(data <= root->data) return search(root->left,data);
    else
    {
        return search(root->right, data);
    }
    
}

Node* insert(Node* root, int data)
{
    if(root == NULL)
    {
        root = NewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = insert(root->left,data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
    
}

 
 int main()
 {
    Node* root = NULL;
 }