/*
-------------------------------12--------------------------------
Define a class Publication which has a title. Derive two classes from it – a class Book
which has an accession number and a class Magazine which has volume number.With
these two as bases,derive the class Journal. Define a function print() in each of these
classes.Ensure that the derived class function always invokes the base(s) class function.
In main() create a Journal called IEEEOOP with an accession number 681.3 and a volume
number 1.Invoke the print() function for this object.
*/

#include <iostream>
using namespace std;
class Publication{
    protected:
                string title;
    public:
                Publication(string title):title(title){}
                virtual void print(){
                    cout<<"Title: "<<title<<endl;
                }
};

class Book: virtual public Publication{
    protected:
            float acc_no;
    public:
            Book(string title,float acc_no):Publication(title),acc_no(acc_no){};
            void print() override{
                Publication::print();
                cout<<"\nAccession Number: "<<acc_no<<endl;
            }
};

class Magazine: virtual public Publication{
    protected:
            int vol_number;
    public:
            Magazine(string title,int vol_number):Publication(title),vol_number(vol_number){}; 
            void print() override{
                Publication::print();
                cout<<"\nVolume Number: "<<vol_number<<endl;
            }
};

class Journal: public Book, public Magazine{

    public:
            Journal(string t,float a,int v):Publication(t),Book(t,a),Magazine(t,v){};
            void print() override{
                Book::print();
                Magazine::print();
            }

};


int main(){

    Journal IEEEOOP("IEEEOOP", 681.3, 1); 
    IEEEOOP.print();
    return 0;
}