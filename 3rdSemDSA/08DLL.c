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