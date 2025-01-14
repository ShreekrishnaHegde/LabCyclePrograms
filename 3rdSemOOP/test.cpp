#include <iostream>
using namespace std;

class Publication{
    private:
        string title;
    public:
        Publication(string title){
            this->title=title;
    }
};

class Book: public Publication{
    private:
        int acc_no;
    public:
        Book(int acc_no){
            this->acc_no=acc_no;
        }
};
class Magzine:public Publication{
    private:
        int vol_no;
    public:
        Magzine(int vol_no){
            this->vol_no=vol_no;
        }
};

class Journal: public Book,public Magzine{
    public:
        Journal(string title,int acc_no,int vol_no){
            Magzine(vol_no);
        }
};
int main(){
    Journal IeeOop("IEEOOP",123,1234);
    return 0;
}