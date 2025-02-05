/*
Design, Develop and Implement a menu driven Program for the following operations on
Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation,
Sal, PhNo .
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it.
c. Perform Insertion and Deletion at End of DLL .
d. Perform Insertion and Deletion at Front of DLL.
e. Demonstrate how this DLL can be used as Double Ended Queue.
f. Exit
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int ssn;
    char name[20];
    char dept[10];
    char designation[10];
    int sal;
    char phNo[10];
    struct Node* prev;
    struct Node* next;
}Node;

Node* createNode(){
    Node* newNode=(Node*)malloc(sizeof(Node));
    printf("\nEnter SSN:");
    scanf("%d",&newNode->ssn);
    printf("Enter Name:");
    scanf("%s",newNode->name);
    printf("Enter Dept:");
    scanf("%s",newNode->dept);
    printf("Enter Designation:");
    scanf("%s",newNode->designation);
    printf("Enter Sal:");
    scanf("%d",&newNode->sal);
    printf("Enter PhNo:");
    scanf("%s",newNode->phNo);
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
