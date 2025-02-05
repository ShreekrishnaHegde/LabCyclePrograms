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
#include <stdlib.h>

typedef struct Node{
    int sem;
    char usn[10];
    char name[20];
    char branch[10];
    char phNo[10];
    struct Node* next;
}Node;

/*
------------------------Algorithm to create new Node------------------------
1. Create a new Node
2. Read the data and initialize all the fields accordingly.
3. Initialize next pointer to NULL
4. Return the new Node
*/
Node* createNode(){
    Node* newNode=(Node*)malloc(sizeof(Node));
    printf("\nEnter USN:");
    scanf("%s",newNode->usn);
    printf("Enter Name:");
    scanf("%s",newNode->name);
    printf("Enter Branch:");
    scanf("%s",newNode->branch);
    printf("Enter Sem:");
    scanf("%d",&newNode->sem);
    printf("Enter PhNo:");
    scanf("%s",newNode->phNo);
    newNode->next=NULL;
    return newNode;
}
/*
------------------------------------Algorithm to insert a new Node at the beginning------------------------------------
1.create a new Node
2.if head is NULL, assign the new Node to head
3.else,
    assign the next of new Node to head
    update head to new Node
*/
void insertFirst(Node** head){
    Node* newNode=createNode();
    if(*head==NULL){
        *head=newNode;
    }
    else{
        newNode->next=*head;
        *head=newNode;
    }
}
/*
-------------------------------------Algorithm to insert a new Node at the end-------------------------------------
1.create a new Node
2.if head is NULL, assign the new Node to head
3.else,
    assign temp to head
    iterate through the list till the last Node and assign temp to the last Node.
    assign the next of temp to new Node
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
    }
}
void deleteFirst(Node** head){
    if(*head==NULL){
        printf("List is Empty\n");
    }
    else{
        Node* temp=*head;
        *head=(*head)->next;
        free(temp);
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
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
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
            printf("%d %s %s %s %s\n",temp->sem,temp->usn,temp->name,temp->branch,temp->phNo);
            count++;
            temp=temp->next;
        }
        printf("Number of Nodes:%d\n",count);
        printf("\n");
    }
}

void main(){
    Node* head=NULL;
    int choice,data;
    printf("1.Insert First\n2.Insert Last\n3.Delete First\n4.Delete Last\n5.Display\n6.Exit");
    do{
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insertFirst(&head);
                break;
            case 2:
                insertLast(&head);
                break;
            case 3:
                deleteFirst(&head);
                break;
            case 4:
                deleteLast(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    while(choice!=6);
}