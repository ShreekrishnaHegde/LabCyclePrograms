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
                Publication(string title){
                    this->title=title;
                }
                virtual void print(){
                    cout<<"Title: "<<title<<endl;
                }
};

class Book: public Publication{
    protected:
            int acc_no;
    public:
            Book(string title,int acc_no):Publication(title),acc_no(acc_no){};
            void print() override{
                Publication::print();
                cout<<"\nAccession Number: "<<acc_no;
            }

};

class Magazine: public Publication{
    protected:
            int vol_number;
    public:
            Magazine(string title,int vol_no):Publication(title),vol_number(vol_number){}; 
            void print() override{
                Publication::print();
                cout<<"\nVolume Number: "<<vol_number;
            }
};

class Journal: public Book, public Magazine{

    public:
            Journal(string t,int a,int v):Book(t,a),Magazine(t,v){};
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