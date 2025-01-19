/*
----------------------------------------7-------------------------------------
Write a C++ program to create a class called DATE. Accept two valid dates in the form
dd/mm/yy. Implement the following operations by overloading the operations + and -.
After every operation display the results by overloading the operator<<.
1. no_of_days = d1 – d2 ; where d1 and d2 are DATE objects, d1>=d2 and
no_of_days is an integer.
2. d2 = d1 + no_of_days; where d1 is a DATE object and no_of_days is an
integer.
*/

#include <iostream>
using namespace std;


class Date{
    private:
            int dd,mm,yy;
    public:
            Date(int dd=0,int mm=0,int yy=0){
                this->dd=dd;
                this->mm=mm;
                this->yy=yy;
            }
            int operator-(Date);
            Date operator+(int);
            friend ostream& operator<<(ostream &print,Date &d);
};

int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ostream& operator<<(ostream &print,Date &d){
    print<<d.dd<<"/"<<d.mm<<"/"<<d.yy;
    return print;
}
int Date::operator-(Date d2){
    Date res;
    int temp,nod,noly=0;

    temp=d2.yy;
    for(temp;temp<yy;temp++){
        if(temp%4==0)
            noly++;
    }

    // temp=yy;
    // for(temp;temp>d2.yy;temp--){
    //     if(temp%4==0)
    //         noly++;
    // }
    res.dd=dd-d2.dd;
    if(res.dd<0){
        res.dd=dd+a[mm];
        res.mm=mm--;
    }
    res.mm=mm=d2.mm;
    if(res.mm<0){
        res.mm=mm+12;
        res.yy=yy--;
    }
    res.yy=yy-d2.yy;    
    if(yy<0)
        return -1;
    nod=res.dd+(res.yy*365);

    int months=d2.mm;
    for(int i=1;i<=res.mm;i++){
        nod+=a[months++];
    }
    nod+=noly;
    return nod;

}

Date Date::operator+(int ndays){
    Date d(dd,mm,yy);
    for(int i=1;i<=ndays;i++){
        d.dd++;
        if(d.yy%4==0){
            if(d.dd>b[d.mm]){
                d.dd=1;
                d.mm++;
            }
        }
        else{
            if(d.dd>a[d.mm]){
                d.dd=1;
                d.mm++;
            }
        }
        if(d.mm>12){
            d.mm=1;
            d.yy++;
        }
    }
    return d; 
}


int main(){
    int ndays,dd,mm,yy;
    cout<<"\nEnter two dates(d1>d2): ";
    cout<<"\nEnter Date 1(dd mm yyyy): ";
    cin>>dd>>mm>>yy;
    Date d1(dd,mm,yy);
    cout<<"\nEnter Date 2(dd mm yyyy): ";
    cin>>dd>>mm>>yy;
    Date d2(dd,mm,yy);
    ndays=d1-d2;
    cout<<"\nNumber of days between Date 1 and Date 2: "<<ndays<<endl;
    cout<<"\nEnter number of days to be added to date 1: ";
    cin>>ndays;
    d1=d1+ndays;
    cout<<"\nAfter adding: "<<d1;
    return 0;
}