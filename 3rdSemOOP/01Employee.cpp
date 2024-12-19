/*
Given that an EMPLOYEE class contains following members:
Data members: Employee_Number, Employee_Name, Basic, DA, IT, Net_Sal
Member functions: to read the data, to calculate Net_Sal and to print data members.
Write a C++ program to read the data of N employees and compute Net_Sal of each
Employee
(DA=52% of Basic and Income Tax (IT) = 30% of the gross salary).
*/
#include <iostream>
using namespace std;
class Employee{
    int Employee_Number;
    string Employee_Name;
    int Employee_basic;
    float Employee_Da;
    float Employee_It;
    float Employee_Net_Salary;

    public: 
        void read();
        void display();
        void compute_salary(int Employee_basic);
};
void Employee::read(){
    cout<<"\nEnter employee number: ";
    cin>>Employee_Number;
    cout<<"\nEnter employee name: ";
    cin>>Employee_Name;
    cout<<"\nEnter employee basic: ";
    cin>>Employee_basic;
}
void Employee:: display(){
    compute_salary(Employee_basic);
	cout<<"\nEmployee Name      :  "<<Employee_Name;
	cout<<"\nEmployee number    :  "<<Employee_Number;
	cout<<"\nBasic salary       :  "<<Employee_basic;
	cout<<"\nEmployee DA        :  "<<Employee_Da;
	cout<<"\nIncome Tax         :  "<<Employee_It;
	cout<<"\nNet Salary         :  "<<Employee_Net_Salary<<endl;
}
void Employee::compute_salary(int Employee_basic){
    /*
    Net salary=Basic+DA-IT
    In question given that DA=52% of basic and IT=30% of gross salary.
    where gross salary is the total money an employee earns.
    */
    Employee_Da=0.52*Employee_basic;
    Employee_It=0.3*(Employee_basic+Employee_Da);
    Employee_Net_Salary=Employee_basic+Employee_Da-Employee_It;
}
int main(){
    //To store number of employees
    int n;
    //Creating array of objects of Employee type.
    Employee employee[10];
    cout<<"\nEnter the number of employees: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\n\tEnter the details of employee "<<i+1<<endl;
        employee[i].read();
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"\n\tEmployee "<<i+1<<" details"<<endl;
        employee[i].display();
    }
    return 0;
}