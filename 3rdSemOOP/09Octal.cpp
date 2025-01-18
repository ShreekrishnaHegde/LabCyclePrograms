/*
Write a C++ program to create a class called OCTAL which has the characteristics of an
octal number. Implement the following operations by writing an appropriate
constructor and an overloaded operator +.
1. OCTAL h = x; where x is an integer.
2. Int y = h + k; where h is anOCTAL object and k is an integer.
Display the OCTAL result by overloading the operator <<. Also display the values of
h and Y.
*/

#include <iostream>
#include <math.h>
using namespace std;

class Octal{
    private:
            int oct[15],count;
    public:
            Octal(int);
            int operator+(int);
            friend ostream& operator<<(ostream&,Octal);

};

Octal::Octal(int x){
    int i=0,rem,a[15];
    while(x!=0){
        rem=x%8;
        a[i++]=rem;
        x/=8;
    }
    count=i;
    int n=count-1;
    for(int i=0;i<count;i++){
        oct[i]=a[n];
        n--;
    }
}

int Octal::operator+(int k){
    int x=0,j=count-1;
    for(int i=0;i<count;i++){
        x=x+oct[j]*pow(8,i);
        j--;
    }
    return x+k;
}

ostream& operator<<(ostream& print,Octal O){
    for(int i=0;i<O.count;i++)
        print<<O.oct[i];
    return print;
}

int main(){
    int x,k,y=0;
    cout<<"\nEnter the integer value (x): ";
    cin>>x;
    Octal h=Octal(x);
    cout<<"\nThe corresponding octal equivalent of "<<x<<" is: "<<h;
    cout<<"\nEnter the integer to be added to the Octal Value: ";
    cin>>k;
    y=h+k;
    cout<<"\n"<<h<<" (Octal) + "<<k<<" (Decimal) ="<<y<<" (Decimal)";
    return 0;
}