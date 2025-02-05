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
/*
----------------------Algorithm to create new Node----------------------
1. Create a new Node
2. Read the data and initialize all the fields accordingly.
3. Initialize prev and next pointers to NULL
4. Return the new Node
*/
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
/*
------------------Algorithm to insert a new Node at the beginning------------------
1.create a new Node
2.if head is NULL, assign the new Node to head
3.else,
    assign the next of new Node to head and prev of head to new Node
    assign head to new Node
*/
void insertFirst(Node** head){
    Node* newNode=createNode();
    if(*head==NULL){
        *head=newNode;
    }
    else{
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
    }
}
/*
-------------------Algorithm to insert a new Node at the end-------------------
1. Create a new Node
2. if head is NULL, assign the new Node to head
3. else,
    assign temp to head
    iterate through the list till the last Node and assign temp to the last Node.
    assign the next of temp to new Node and prev of new Node to temp
*/
void insertLast(Node** head){
    Node* newNode=createNode();
    if(*head==NULL){
        *head=newNode;
    }
    else{
        Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}
/*
----------------------------Algorithm to delete the first Node----------------------------
1. if head is NULL, print "List is Empty"
2. else if head->next is NULL (means there is only one node), free head and assign NULL to head
3. else,
    assign temp to head
    update head to head->next.
    free temp.
    assign NULL to prev of head
*/
void deleteFirst(Node** head){
    if(*head==NULL){
        printf("List is Empty\n");
    }
    else if((*head)->next==NULL){
        free(*head);
        *head=NULL;
    }
    else{
        Node* temp=*head;
        *head=(*head)->next;
        free(temp);
        (*head)->prev=NULL;
    }
}
/*
----------------------------Algorithm to delete the last Node----------------------------
1. if head is NULL, print "List is Empty"
2. else if head->next is NULL (means there is only one node), free head and assign NULL to head
3. else,
    assign temp to head
    iterate through the list till the last Node and assign temp to the last Node.
    free temp.
    assign NULL to next of prev of temp
*/
void deleteLast(Node** head){
    if(*head==NULL){
        printf("List is Empty\n");
    }
    else if((*head)->next==NULL){
        free(*head);
        *head=NULL;
    }
    else{
        Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
    }
}
/*
----------------------------Algorithm to display the list----------------------------
1. if head is NULL, print "List is Empty"
2. else,
    assign temp to head
    iterate through the list till the last Node and print the data of each Node.
    increment count for each Node.
    print the number of nodes.
*/
void display(Node* head){
    int count=0;
    if(head==NULL){
        printf("List is Empty\n");
    }
    else{
        Node* temp=head;
        while(temp!=NULL){
            printf("\nSSN:%d\nName:%s\nDept:%s\nDesignation:%s\nSal:%d\nPhNo:%s\n",temp->ssn,temp->name,temp->dept,temp->designation,temp->sal,temp->phNo);
            temp=temp->next;
            count++;
        }
        printf("Number of nodes:%d\n",count);
    }
}

void main(){
    Node* head=NULL;
    int choice;
    printf("\n1.Insert First\n2.Insert Last\n3.Delete First\n4.Delete Last\n5.Display\n6.Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insertFirst(&head);
                    break;
            case 2: insertLast(&head);
                    break;
            case 3: deleteFirst(&head);
                    break;
            case 4: deleteLast(&head);
                    break;
            case 5: display(head);
                    break;
            case 6: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
    while(choice!=6);
}