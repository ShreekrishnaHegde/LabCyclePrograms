/*
Design, Develop and Implement a Program for the following operations on Singly circular
Linked List (SCLL) with header nodes
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2
y
2
z-4yz5 +3x3
yz+2xy5
z-2xyz3
.
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in
POLYSUM(x,y,z) Support the program with appropriate functions for each of the above
operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int x,y,z,coef;
    struct Node* next;
}Node;

Node* createNode(int coef,int x,int y,int z);
void display(Node** head);
void insertLast(Node** head,int coef,int x,int y,int z);
void evalulate(Node* head,int x,int y,int z);
Node* add(Node* p1,Node* p2);
Node* isSameDegree(Node* head,int x,int y,int z);

void main(){
    Node *p1=NULL,*p2=NULL,*pSum=NULL;
    insertLast(&p1,6,2,2,1);
    insertLast(&p1,-4,1,2,5);
    insertLast(&p1,3,3,1,1);
    insertLast(&p1,2,1,5,1);
    insertLast(&p1,-2,1,1,3);

    insertLast(&p2,1,2,2,1);
    insertLast(&p2,2,0,1,5);
    insertLast(&p2,-1,3,1,1);
    insertLast(&p2,2,1,5,1);
    insertLast(&p2,-1,1,1,3);

    display(&p1);
    display(&p2);
    pSum=add(p1,p2);
    display(&pSum);
}

Node* createNode(int coef,int x,int y,int z){
    Node* newNode=(Node* )malloc(sizeof(Node));
    newNode->coef=coef;
    newNode->x=x;
    newNode->y=y;
    newNode->z=z;
    //Circular linked list
    newNode->next=newNode;
    return newNode;
}

void display(Node **head){
    if(*head==NULL)
        return;
    Node* temp=*head;
    do{
        printf("%dx^%dy^%dz^%d ",temp->coef,temp->x,temp->y,temp->z);
        temp=temp->next;
    }
    while(temp!=*head);
    printf("\n");
}
void insertLast(Node** head,int coef,int x,int y,int z){
    Node* newNode=createNode(coef,x,y,z);
    if(*head==NULL)
        *head=newNode;
    else{
        Node* temp=*head;
        //Circular linked list
        while(temp->next!=*head)
            temp=temp->next;
        temp->next=newNode;
        newNode->next=*head;
    }
}
void evalulate(Node* head,int x,int y,int z){
    if(head==NULL)
        return;
    Node* temp=head;
    float result=0;
    do{
        result+=temp->coef*pow(x,temp->x)*pow(y,temp->y)*pow(z,temp->z);
        temp=temp->next;
    }
    while(temp!=head);
    printf("\nEvaluation: %d",result);
}
Node* add(Node* p1,Node* p2){
    Node* pSum=NULL;
    Node* temp1=p1;
    Node* temp2=p2;
    do{
        Node* term=isSameDegree(pSum,temp1->x,temp1->y,temp1->z);
        if(term)
            term->coef+=temp1->coef;
        else
            insertLast(&pSum,temp1->coef,temp1->x,temp1->y,temp1->z);
        temp1=temp1->next;
    }
    while(temp1!=p1);
    do{
        Node* term=isSameDegree(pSum,temp2->x,temp2->y,temp2->z);
        if(term)
            term->coef+=temp2->coef;
        else
            insertLast(&pSum,temp2->coef,temp2->x,temp2->y,temp2->z);
        temp2=temp2->next;
    }
    while(temp2!=p2);
    return pSum;
}

Node* isSameDegree(Node* head,int x,int y,int z){
    if(head==NULL)
        return NULL;
    Node* temp=head;
    do{
        if(temp->x==x && temp->y==y && temp->z==z)
            return temp;
        temp=temp->next;
    }
    while(temp!=head);
    return NULL;
}