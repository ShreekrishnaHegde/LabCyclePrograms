/*
---------------------------------------6---------------------------------------
Write a C++ program to create a class called STACK using an array of integers. Implement
the following operations by overloading the operators + and -.
1. s1 = s1 + element; where s1 is an object of the class STACK and element is an
integer to be pushed on the top of the stack.
2. s1 = s1 - ; where s1 is an object of the class STACK – operator pops the element.
Handle the STACK empty and STACK full conditions. Also display the contents ofthe stack
after each operation, by overloading the operator<<.
*/

#include <iostream>
using namespace std;

class Stack{
    private:
            int a[100],size,top;
    public:
            Stack(int n){
                top=-1;
                size=n;
            }
            friend Stack operator+(Stack,int);
            friend Stack operator-(Stack);
            friend int isFull(Stack);
            friend int isEmpty(Stack);
            friend ostream& operator<<(ostream& print,Stack s);

};
Stack operator+(Stack s,int ele){
    s.a[++s.top]=ele;
    return s;
}
Stack operator-(Stack s){
    cout<<s.a[s.top--]<<" has been popped out!";
    return s;
}
int isFull(Stack s){
    if(s.top==s.size-1)
        return 1;
    else 
        return 0;
}
int isEmpty(Stack s){
    if(s.top==-1)
        return 1;
    else 
        return 0;
}
ostream& operator<<(ostream& print,Stack s){
    if(isEmpty(s))
        cout<<"\nStack is Empty.";
    else{
        print<<"\nStack Status: ";
        for(int i=s.top;i>=0;i--)
            print<<"\t"<<s.a[i];
        return print;
    }
}
int main(){
    int n,ch,ele;
    cout<<"\nEnter the size of the stack: ";
    cin>>n;
    Stack s(n);
    cout<<"\n\tMenu\n1.Push\n2.Pop\n3.Display\n4.Exit";
    do{
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 1: if(isFull(s)){
                        cout<<"\nStack is Full";
                        break;
                    }
                    else{
                        cout<<"\nEnter the element to be pushed: ";
                        cin>>ele;
                        s=s+ele;
                        cout<<s;
                    }
                    break;
            case 2: if(isEmpty(s))
                        cout<<"\nStack is Empty";
                    else{
                        s=-s;
                        cout<<s;
                    }
                    break;
            case 3: cout<<s;
                    break;
            case 4: cout<<"\nExiting\nThank you!";
                    break;
            default: cout<<"\nInvalid choice";
        }
    }
    while(ch!=4);
    return 0;
}
