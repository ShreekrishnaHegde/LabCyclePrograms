/*
Write a C++ program to create a class called COMPLEX and implement the following
overloading functions ADD that return a COMPLEX number.
1. ADD (a, s2) – where a in an integer (real part) and s2 is a complex number.
2. ADD (s1, s2) – where s1 and s2 are complex numbers.
*/
#include <iostream>
using namespace std;
 
class Complex{
    private: int real,img;
    public: 
            void set_data(){
                cin>>real;
                cin>>img;
            }
            //Function to add an integer to the complex number s1
            Complex add(int a){
                Complex result;
                result.real=a+real;
                result.img=img;
                return result;
            }
            //Function to add the complex number s1 and s2
            Complex add(Complex s2){
                Complex result;
                result.real=real+s2.real;
                result.img=img+s2.img;
                return result;
            }
            void display(){
                cout<<real<<"+"<<img<<"i"<<endl;
            }
};
int main(){
    Complex s1,s2,r1,r2;
    int n;
    cout<<"Enter the real and imaginary part of complex number(s1) :  ";
    s1.set_data();
    cout<<"Enter the real and imaginary part of complex number(s2) :  ";
    s2.set_data();
    cout<<"\nEnter the integer(a): ";
    cin>>n;
    r1=s1.add(n);
    r2=s1.add(s2);
    cout<<"\ns1 is: ";
    s1.display();
    cout<<"\ns2 is: ";
    s2.display();
    cout<<"\nSum of s1 and a: ";
    r1.display();
    cout<<"\nSum of s1 and s2: ";
    r2.display();
    return 0;
}