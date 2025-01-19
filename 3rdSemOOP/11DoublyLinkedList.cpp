/*
--------------------------------------11----------------------------------------
Write a C++ program to create a class called DLIST (Doubly Linked List) with member
functions to insert a node at a specified position and delete a node from a specified
position of the list. Demonstrate the operations by displaying the content of the list after
every operation.
*/

#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *rlink,*llink;
}Node;

class DLL{
    private:
            Node *first,*last;
            int count;
    public:
            DLL(){
                first=last=NULL;
                count=0;
            }
            void insertNode(int,int);
            void insertFirst(int);
            void deleteNode(int);
            void display();
};

void DLL::insertFirst(int data){
    first=last=new Node;
    first->data=data;
    first->llink=first->rlink=NULL;
    count++;
}

void DLL::insertNode(int data,int pos){
    if(pos>count+1){
        cout<<"\nInvalid Position";
        return;
    }
    Node* newNode=new Node;
    newNode->data=data;
    if(pos==1){
        newNode->llink=NULL;
        newNode->rlink=first;
        if(first!=NULL)
            first->llink=newNode;
        first=newNode;
        if(last==NULL)
            last=newNode;
    }
    else if(pos==count+1){
        newNode->rlink=NULL;
        newNode->llink=last;
        last->rlink=newNode;
        last=newNode;
    }
    else{
        Node* temp=first;
        int i=1;
        for(int i=1;i<pos-1 && temp!=NULL;i++){
            temp=temp->rlink;
        }
        newNode->rlink=temp->rlink; 
        newNode->llink=temp; 
        if(temp->rlink != NULL){ 
            temp->rlink->llink = newNode; 
        } 
        temp->rlink = newNode;
    }
    count++;
    cout<<"\n"<<data<<" has been successfully inserted at position "<<pos;
}

void DLL::deleteNode(int pos){
    
    if(first==NULL){
        cout<<"\nList is already empty!";
        return;
    }
    else if(pos>count){
        cout<<"\nInvalid Position.";
        return;
    }
    int data;
    Node* temp=first;
    if(pos==1){
        data=first->data;
        if(first==last){
            delete first;
            first=last=NULL;
        }
        else{
            first=first->rlink;
            first->llink=NULL;
            delete temp;
        }
    }
    else if(pos==count){
        temp=last;
        last=temp->llink;
        last->rlink=NULL;
        data=temp->data;
        delete temp;
    }
    else if(pos==1 && first==last){
        data=first->data;
        delete first;
        first=last=NULL;
    }
    
    else{
        for(int i=1;i<pos && temp!=NULL;i++){
            temp=temp->rlink;
        }
        data=temp->data;
        Node* prev=temp->llink;
        Node* next=temp->rlink;
        prev->rlink=next;
        next->llink=prev;
        delete temp;
    }
    cout<<"\nData "<<data<<" has been successfully deleted from position "<<pos;
    count--;
    return;
}

void DLL::display(){
    Node* temp=first;
    cout<<"\nList Status: ";
    if(temp==NULL)
        cout<<"\nList is Empty!";
    else{
        cout<<"\nNumber of nodes in the list is: "<<count;
        cout<<"\nThe contents of the list are: ";
        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp=temp->rlink;
        }
        cout<<"NULL";
    }
}

int main(){
    DLL L;
    int choice,pos,flag=0,data;
    cout<<"\n\tMenu\n1.Insert\n2.Delete\n3.Display\n4.Exit";
    do{
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"\nEnter the data to be inserted: ";
                    cin>>data;
                    if(flag==0){
                        L.insertFirst(data);
                        flag=1;
                        break;
                    }
                    cout<<"\nEnter the position: ";
                    cin>>pos;
                    L.insertNode(data,pos);
                    break;
            case 2: cout<<"\nEnter the position of node to be deleted: ";
                    cin>>pos;
                    L.deleteNode(pos);
                    break;
            case 3: L.display();
                    break;
            case 4: cout<<"\nExiting Program";
                    break;
            default: cout<<"\nInvalid choice";
        }
    }
    while(choice!=4);
    return 0;
}