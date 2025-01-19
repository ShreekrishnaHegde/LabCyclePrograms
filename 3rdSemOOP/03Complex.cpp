/*
--------------------------------3-------------------------------------------
Write a C++ program to create a class called COMPLEX and implement the following
overloading functions ADD that return a COMPLEX number.
1. ADD (a, s2) – where a in an integer (real part) and s2 is a complex number.
2. ADD (s1, s2) – where s1 and s2 are complex numbers.
*/
#include <iostream>
using namespace std;
 
class Complex{
    private: 
            int real,img;
    public: void read();
            friend Complex add(int,Complex);
            friend Complex add(Complex,Complex);
            friend ostream& operator<<(ostream&,Complex&);
            
};
//to read the complex number
void Complex::read(){
    cin>>real;
    cin>>img;
}
//Function to add two Complex numbers
Complex add(Complex s1,Complex s2){
    Complex result;
    result.real=s1.real+s2.real;
    result.img=s1.img+s2.img;
    return result;
}
//Function to add a complex number and an integer
Complex add(int a,Complex s2){
    Complex result;
    result.real=s2.real+a;
    result.img=s2.img;
    return result;
}
//Function to display the complex number by overloading the operator <<
ostream& operator<<(ostream& print,Complex& c){
    print<<"\n"<<c.real<<" + "<<c.img<<" i";
    return print;
}

int main(){
    Complex s1,s2,r1,r2;
    int a;
    cout<<"Enter the real and imaginary part of complex number(s1) :  ";
    s1.read();
    cout<<"Enter the real and imaginary part of complex number(s2) :  ";
    s2.read();
    cout<<"\nEnter the integer(a): ";
    cin>>a;
    r1=add(a,s2);
    r2=add(s1,s2);
    cout<<"\ns1 is: "<<s1;
    cout<<"\ns2 is: "<<s2;
    cout<<"\nInteger a is: "<<a;
    cout<<"\nSum of s2 and a: "<<r1;
    cout<<"\nSum of s1 and s2: "<<r2;
    return 0;
}