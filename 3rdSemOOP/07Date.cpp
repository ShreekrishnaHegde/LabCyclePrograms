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

class Date {
    private:
        int dd, mm, yy;

    public:
        void read() {
            cin >> dd >> mm >> yy;
        }
        int operator-(Date);
        Date operator+(int);
        friend ostream& operator<<(ostream &print, Date &d);
};

int b[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

ostream& operator<<(ostream &print, Date &d) {
    print << d.dd << "/" << d.mm << "/" << d.yy;
    return print;
}

//To determine whether given year is leap year or not
bool isLeapYear(int year) {
    return (year%4==0&&year%100!=0) || (year%400==0);
}

int Date::operator-(Date d2) {
    int noly = 0, nod = 0;
    for (int year = d2.yy; year < yy; year++) {
        noly += isLeapYear(year) ? 1 : 0;
    }
    nod+=(yy-d2.yy)*365;
    //To add remaining number of days from no leap years(1 day)
    nod+=(yy-d2.yy-noly);
    
    //If days of d1's day is less that d2, then days are borrowed from previous month, 
    //Days of previous month are added by checking the year is leap year or not.
    if (dd<d2.dd) {
        mm--;
        dd+=isLeapYear(yy) ? b[mm] : a[mm];
    }

    nod+=dd-d2.dd;

    //Similarly if mm of d1 is less that d2, months are borrowed from previous year
    if (mm<d2.mm) {
        yy--;
        mm+=12;
    }
    nod+=(mm-d2.mm)*30;
    return nod;
}

Date Date::operator+(int ndays) {
    Date d= *this;
    while (ndays--) {
        d.dd++;
        if (d.dd >(isLeapYear(d.yy) ? b[d.mm] : a[d.mm])) {
            d.dd = 1;
            d.mm++;
            if (d.mm>12) {
                d.mm=1;
                d.yy++;
            }
        }
    }
    return d;
}

int main() {
    Date d1, d2;
    int ndays = 0;
    cout<<"\nEnter two dates (d1 > d2): ";
    cout<<"\nEnter Date 1 (dd mm yyyy): ";
    d1.read();
    cout<<"\nEnter Date 2 (dd mm yyyy): ";
    d2.read();
    ndays=d1-d2;
    cout<<"\nNumber of days between Date 1 and Date 2: " <<ndays<< endl;
    cout<<"\nEnter number of days to be added to Date 1: ";
    cin>>ndays;
    d1=d1+ndays;
    cout<<"\nAfter adding given days: " <<d1;
    return 0;
}
