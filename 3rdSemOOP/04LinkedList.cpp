/*
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
        Node(){
            this->value=0;
            this->next=NULL;
        }
        Node(int value){
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
        void insertFirst(int value){
            Node *newNode=new Node(value);
            if(head==NULL){
                head=newNode;
                return;
            }
            newNode->next=this->head;
            this->head=newNode;

        }
        void deleteFirst(){
            if(head==NULL){
                cout<<"\nNothing to delete";
            }
            head=head->next;
        }
        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->value<<"->";
                temp=temp->next;
            }
        }
};
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
                    
        }
    }
    while(choice!=4);
    return 0;
}