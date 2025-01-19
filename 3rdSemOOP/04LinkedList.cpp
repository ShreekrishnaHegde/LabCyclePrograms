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
to insert an element into the list at first position
->Make the first node of Linked List linked to the new node
->Remove the head from the original first node of Linked List
->Make the new node as the Head of the Linked List.
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
to delete first elelement from the list.
->store the current head in a temporary variable (temp)
->move the head pointer to the next node
->delete the temporary head node
*/
void LinkedList::deleteFirst(){
    if(head==NULL){
        cout<<"\nList is Empty" ;
        return;
    }
    Node* temp=head;
    head=head->next;
    cout<<"\nThe deleted element is: "<<temp->value;
    delete temp;
}
/*
to display the content of the list
->Initialize a pointer temp to the head of the list.
->if temp is null print list is empty.
->else Use a while loop to iterate through the list until the current pointer reaches NULL.
->Inside the loop, print the data of the current node and move the current pointer to the next node
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