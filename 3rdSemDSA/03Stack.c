/*
--------------------------------------3--------------------------------------------
Design, Develop and Implement a menu driven Program for the following operations on
STACK of Integers (Array Implementation of Stack with maximum size MAX)
a. Push an Element onto Stack.
b. Pop an Element from Stack.
c. Demonstrate how Stack can be used to check Palindrome.
d. Demonstrate Overflow and Underflow situations on Stack.
e. Display the status of Stack.
f. Exit Supportthe programwith appropriate functionsfor each ofthe above operations.
*/


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 50

int stack[MAX],n,top=-1;

bool isPalindrome();
void display();
void pop();
void push(int ele);
bool isFull();
bool isEmpty();


int main(){
    int ch,ele;
    printf("\n1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.Exit");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the element to be pushed(0-9): ");
                    scanf("%d",&ele);
                    push(ele);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: if(isPalindrome())
                        printf("\nPalindrome");
                    else
                        printf("\nNot Palindrome");
                    break;
            case 5:
                    break;
        }
    }   
    while(ch!=5);
    return 0;
}
/*
-----------------Algorithm to check if the stack is palindrome-------------------------
1. Check if the stack is empty
    If empty, 
        return false
2. Create a temporary stack and a temporary top
3. Push all the elements of the stack to the temporary stack
4. Compare the elements of the stack and the temporary stack
    If they are equal, 
        return true
    Else, 
        return false

*/
bool isPalindrome(){
    if(isEmpty())
        return false;
    int tempStack[MAX];
    int tempTop=-1;
    //Pushing all the elements to temporary stack
    for(int i=0;i<=top;i++){
        tempStack[++tempTop]=stack[i];
    }
    for(int i=0;i<=top;i++){
        if(stack[i]!=tempStack[tempTop--])
            return false;
    }
    return true;
}
/*
--------------------------Algorithm for display()-------------------------------------
1. Check if the stack is empty
    If empty, 
    print "The Stack is empty"
3. Else,
    Check if the stack is full
    If full, 
        print "The Stack is full"
4. Else,
        print the stack elements
*/
void display(){
        if(isEmpty())
            printf("\n The Stack is empty!");
        else if(isFull())
            printf("\n The Stack is full!");
        else{
            printf("\nStack elements: ");
            for(int i=0;i<=top;i++)
                printf("%d ",stack[i]);
            printf("\n");
        }
}
/*
--------------------------Algorithm for pop()-------------------------------------
1. Check if the stack is empty
2. If empty, 
    print "Stack is Empty"
3. Else, 
    print the popped element and decrement the top
*/
void pop(){        
    if(isEmpty())
        printf("\n Stack is Empty");
    else
        printf("\nThe popped element is %d",stack[top--]);
}
/*
---------------------------Algorithm for push()-------------------------------------
1. Check if the stack is full
2. If full, 
    print "Stack is Full"
3. Else,
    increment the top and push the element into the stack
    print the pushed element
*/
void push(int ele){
    if(isFull())
        printf("\nStack is Full");
    else{
        stack[++top]=ele;
        printf("\nElement pushed is: %d",ele);
    }
}
/*
-----------------------Algorithm for isFull()--------------------------------------
1. Check if the top is equal to MAX-1
If true, 
    return true
3. Else, 
    return false
*/
bool isFull(){
    return top>=MAX-1;
}
/*
-----------------------------Algorithm for isEmpty()--------------------------------
1. Check if the top is equal to -1
If true, 
    return true
3. Else,
    return false
*/
bool isEmpty(){
    return top==-1;
}



