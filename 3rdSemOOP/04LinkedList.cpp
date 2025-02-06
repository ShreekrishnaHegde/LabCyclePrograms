/*
-----------------------------------4----------------------------------------------
Write a C++ program to create a class called LIST (linked list) with member functions to
insert an element at the front as well as to delete an element from the front of the list.
Demonstrate all the functions after creating a list object.
*/

#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int value=0){
            this->value=value;
            this->next=NULL;
        }
};

class LinkedList{
    private:
        Node *head;
    public:
        LinkedList(){
            head=NULL;
        }
        void insertFirst(int);
        void deleteFirst();
        void display();
};
/*
------------------------------------Algorithm to insert the node at first pos---------------------------
1. Create a new Node
2. if head is NULL, 
    assign the newNode to head
3. else,
    assign head to the next of newNode. 
    assign newNode to head
*/
void LinkedList:: insertFirst(int value){
    Node *newNode=new Node(value);
    if(head==NULL){
        head=newNode;
        return;
    }
    newNode->next=this->head;
    this->head=newNode;
}
/*
-----------------------------Algorithm to delete the first Node----------------------------
1. if head is NULL, print "List is Empty"
2. else if head->next is NULL (means there is only one node), 
    free head and assign NULL to head
3. else,
    assign head to temp.
    update head to head->next.
    free temp.
*/
void LinkedList:: deleteFirst(){
    if(head==NULL){
        cout<<"\nList is empty";
        return;
    }
    else if(head->next==NULL){
        delete head;
        head=NULL;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}
/*
----------------------------------Algorithm to display the list----------------------------
1. if head is NULL, print "List is Empty"
2. else,
    assign head to temp.
    iterate through the list till the last Node and print the data of each Node.
*/
void LinkedList:: display(){
    Node* temp=head;
    if(temp==NULL){
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nElements in the linked list are: ";
    while(temp!=NULL){
        cout<<temp->value<<"-->";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main(){
    int choice,item;
    LinkedList list;
    cout<<"\n\t1.InsertFirst\n\t2.DeleteFirst\n\t3.Display\n\t4.Exit";
    do{
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"\nEnter the element: ";
                    cin>>item;
                    list.insertFirst(item);
                    break;
            case 2: list.deleteFirst();
                    break;
            case 3: list.display();
                    break;
            case 4: cout<<"\nExiting!!!\nThank you!";
                    exit(0);
            default: exit(0);                    
        }
    }
    while(choice!=4);
    return 0;
}