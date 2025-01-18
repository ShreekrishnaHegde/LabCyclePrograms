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
        first->llink=newNode;
        first=newNode;
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
        for(int i=1;i<=count;i++){
            if(i==pos){
                Node* prev=temp->llink;
                newNode->llink=prev;
                prev->rlink=newNode;
                newNode->rlink=temp;
                temp->llink=newNode;
            }
            temp=temp->rlink;
        }
    }
    count++;
    cout<<"\n"<<data<<" has been successfully inserted at position "<<pos;
}

void DLL::deleteNode(int pos){
    int data;
    Node* temp;
    if(first==NULL){
        cout<<"\nList is already empty!";
        return;
    }
    else if(pos>count){
        cout<<"\nInvalid Position.";
        return;
    }
    else if(pos==1 && first==last){
        data=first->data;
        delete first;
        first=last=NULL;
    }
    else if(pos==count){
        temp=last;
        last=temp->llink;
        last->rlink=NULL;
        data=temp->data;
        delete temp;
    }
    else if(pos==1){
        temp=first;
        first=temp->rlink;
        data=temp->data;
        first->llink=NULL;
        delete temp;
    }
    else{
        int i=1;
        for(int i=1;i<=count;i++){
            if(i==pos){
                Node* prev=temp->llink;
                data=temp->data;
                prev->rlink=temp->rlink;
                Node* next=temp->rlink;
                next->llink=prev;
                delete temp;
            }
            temp=temp->rlink;
        }
    }
    cout<<"Data "<<data<<" has been successfully deleted from position "<<pos;
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