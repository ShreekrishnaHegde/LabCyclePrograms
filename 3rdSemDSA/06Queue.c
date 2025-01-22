/*
-------------------------------------------6---------------------------------------------
Design, Develop and Implement a menu driven Program for the following operations on
CircularQUEUE of Characters(Array Implementation of Queue withmaximum size MAX)
.
a. Insert an Element onto Circular QUEUE.
b. Delete an Element from Circular QUEUE.
c. Demonstrate Overflow and Underflow situations on Circular QUEUE.
d. Display the status of Circular QUEUE.
e. Exit Support the program with appropriate functionsfor each ofthe above operations.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int front=-1,rear=-1,queue[MAX];

int isFull();
int isEmpty();
void enqueue(int data);
void dequeue();
void display();

void main(){

    int ch,data;
    printf("\n\tMenu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the element: ");
                    scanf("%d",&data);
                    enqueue(data);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nInvalid Choice");
        }
    }
    while(ch!=4);
}

int isFull(){
    return (rear+1)%MAX==front;
}
int isEmpty(){
    return front==-1;
}
void enqueue(int data){
    if(isFull()){
        printf("\nQueue is Full(Overflow)");
        return;
    }
    if(front==-1)
        front=0;
    rear=(rear+1)%MAX;
    queue[rear]=data;
    printf("\n%d is inerted successfully!",data);
}
void dequeue(){
    if(isEmpty()){
        printf("\nQueue is Empty(Underflow)");
        return;
    }
    printf("\n%d has been removed",queue[front]);
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;
}
void display(){
    if(isEmpty()){
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue status: ");
    int i=front;
    while(i!=rear){
        printf("%d ",queue[i]);
        i=(i+1)%MAX;
    }
    printf("%d\n",queue[rear]);
}
