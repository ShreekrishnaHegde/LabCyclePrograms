/*
Write a C++ program to create a class called QUEUE with member functions to add an
element and to delete an element from the queue. Using these member functions,
implement a queue of integer and double. Demonstrate the operations by displaying
the content of the queue after every operation.
*/

#include <iostream>
using namespace std;

template <class t>
class Queue{
    private:
            t a[100];
            int rear;
    public:
            Queue(){
                rear=-1;
            } 
            void add(t);
            void del();
            void display();
};

//To perform enqueue operation
template <class t>
void Queue<t>::add(t ele){
    a[++rear]=ele;
}

//To perform dequeue operation
template <class t>
void Queue<t>::del(){
    if(rear==-1)
        cout<<"\nQueue is Empty";
    else{
        t ele=a[0];
        for(int i=0;i<=rear;i++)
            a[i]=a[i+1];
        rear--;
        cout<<"\nElement deleted from the queue is: "<<ele;
    }
}

//To display the contents of the queue
template <class t>
void Queue<t>::display(){
    cout<<"\nContents of the queue are: ";
    if(rear==-1){
        cout<<"\nQueue is empty";
        return;
    }
    for(int i=0;i<=rear;i++)
        cout<<"\t"<<a[i];
}
int main(){
    Queue<int> iq;
    Queue<double> dq;
    int ch,choice,Iele,Dele;
    cout<<"\nEnter\n\t1 for Queue of Integers\n\t2 for Queue of Doubles: ";
    cin>>ch;
    cout<<"\n\tMenu\n1.Add\n2.Delete\n3.Display\n4.Exit";
    do{
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: cout<<"\nEnter the element to be added: ";
                    if(ch==1){
                        cin>>Iele;
                        iq.add(Iele);
                        iq.display();
                    }
                    else{
                        cin>>Dele;
                        dq.add(Dele);
                        dq.display();
                    }
                    break;
            case 2: if(ch==1){
                        iq.del();
                        iq.display();
                    }
                    else{
                        dq.del();
                        dq.display();
                    }
                    break;
            case 3: ch==1 ? iq.display() : dq.display();
                    break;
            case 4: cout<<"\nExiting Program";
                    break;
            default: cout<<"\nInvalid Choice";
        }
    }
    while(ch!=4);
    return 0;
}