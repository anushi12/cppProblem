#include <iostream>  
using namespace std;  

// Structure of a node in the binary tree
struct Node {  
    int data;  
    Node *left;  
    Node *right;  
}; 

// Function to create a new node with given data
Node* create(int item)  
{  
    Node* node = new Node;  
    node->data = item;  
    node->left = node->right = NULL;  
    return node;  
}   

// Inorder traversal of the binary tree
void inorder(Node *root)  
{  
    if (root == NULL)  
        return;  
    inorder(root->left);  
    cout<< root->data << "   ";
    inorder(root->right);  
}  

// Function to find the minimum value node in a binary tree
Node* findMinimum(Node* cur)  
{  
    while(cur->left != NULL) {  
        cur = cur->left;  
    }  
    return cur;  
}  

// Insertion operation in the binary tree
Node* insertion(Node* root, int item)  
{  
    if (root == NULL)  
        return create(item); 
    if (item < root->data)  
        root->left = insertion(root->left, item);  
    else  
        root->right = insertion(root->right, item);  
    return root;  
}  

// Function to search for a node in the binary tree
void search(Node* &cur, int item, Node* &parent)  
{  
    while (cur != NULL && cur->data != item)  
    {  
        parent = cur;  
        if (item < cur->data)  
            cur = cur->left;  
        else  
            cur = cur->right;  
    }  
}  

// Deletion operation in the binary tree
void deletion(Node*& root, int item)   
{  
    Node* parent = NULL;  
    Node* cur = root;  
    search(cur, item, parent);   
    if (cur == NULL)  
        return;  
    if (cur->left == NULL && cur->right == NULL)   
    {  
        if (cur != root)  
        {  
            if (parent->left == cur)  
                parent->left = NULL;  
            else  
                parent->right = NULL;  
        }  
        else  
            root = NULL;  
        free(cur);       
    }  
    else if (cur->left && cur->right)  
    {  
        Node* succ  = findMinimum(cur->right);  
        int val = succ->data;  
        deletion(root, succ->data);  
        cur->data = val;  
    }  
    else  
    {  
        Node* child = (cur->left)? cur->left: cur->right;  
        if (cur != root)  
        {  
            if (cur == parent->left)  
                parent->left = child;  
            else  
                parent->right = child;
