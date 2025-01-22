/*
---------------------------11------------------------------
Design, Develop and Implement a menu driven Program for the following operations on
Binary Search Tree (BST) of Integers.
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2.
b. Traverse the BST in Inorder, Preorder and Post Order.
c. Search the BST for a given element (KEY) and report the appropriate message.
d. Exit.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* create(int data);
void printInOrder(Node* node);
void printPreOrder(Node* node);
void printPostOrder(Node* node);
Node* search(Node* node,int key);
Node* insert(Node* node,int data);

void main(){
    int data,item,ch,key;
    Node* root=NULL;
    printf("\n1.Insertion\n2.Display\n3.Search\n4.Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the element: ");
                    scanf("%d",&data);
                    root=insert(root,data);
                    break;
            case 2: printf("\nPreorder Traversal: ");
                    printPreOrder(root);
                    printf("\nInorder Traversal: ");
                    printInOrder(root);
                    printf("\nPostorder Traversal: ");
                    printPostOrder(root);
                    break;
            case 3: printf("\nEnter the element to be searched: ");
                    scanf("%d",&key);
                    search(root,key)==NULL ? printf("\nElement Found"): printf("\nElement not found");
                    break;
            case 4: printf("\nThank you!");
                    exit(0);
            default: exit(0);                    
        }
    }
    while(ch!=4);
}

//to create and initialize the node
Node* create(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
/*
-----------------------------------Algorithm for PostOrder Traversal------------------------
Traverse left subtree
Traverse the right subtree
Visit the root and print the data.
*/
void printPostOrder(Node* node){
    if(node==NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    printf(" %d",node->data);
}
/*
-------------------------Algorithm for inorder Traversal--------------------
Inorder(root):
If root is NULL, then return
Inorder (root -> left)
Process root (For example, print root’s data)
Inorder (root -> right)
*/
void printInOrder(Node* node){
    //Base Condition
    if(node==NULL)
        return;
    //Print Left Sub tree
    printInOrder(node->left);
    //Print Node
    printf("%d ",node->data);
    //Print Right Sub tree
    printInOrder(node->right);
}
/*
-----------------------------algorithm for PreOrder Traversal-----------------------------
If root is NULL then return
Process root (For example, print root’s data)
Preorder (root -> left)
Preorder (root -> right)
*/
void printPreOrder(Node* node){
    if(node==NULL)
        return;
    printf(" %d",node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}
Node* search(Node* node,int key){
    if(node==NULL || node->data==key)
        return node;
    if(node->data<key)
        search(node->right,key);
    if(node->data>key)
        search(node->left,key);
}
/*
    ->If the tree is empty, return a new node
    ->If the key is already present in the tree,
        return the node
    ->Otherwise, recur down the tree. 
    ->If the key to be inserted is greater than the node's key,
        insert it in the right subtree
    ->If the key to be inserted is smaller than the node's key,
        insert it in the left subtree
    ->Return the (unchanged) node pointer
*/
Node*  insert(Node* node,int data){
    if(node==NULL)
        return create(data);
    if(node->data==data)
        return node;
    if(data<node->data)
        node->left=insert(node->left,data);
    else
        node->right=insert(node->right,data);
    return node;  
}


