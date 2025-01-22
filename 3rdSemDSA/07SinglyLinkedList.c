/*
Design, Develop and Implement a menu driven Program for the following operations on
the Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem,
PhNo .
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it.
c. Perform Insertion / Deletion at End of SLL.
d. Perform Insertion / Deletion at Front of SLL (Demonstration ofstack).
e. Exit.
*/
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
Node* insertFront(Node* head,int data){
    Node* newNode=createNode(data);
    if(head==NULL){
        
    }
}

void main(){

}