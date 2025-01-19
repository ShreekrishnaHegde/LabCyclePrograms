/*
------------------------------2--------------------------------------
Define a STUDENT class with USN, Name, and Marks in 3 tests of a subject.
Declare an array of 10 STUDENT objects. Using appropriate functions, find the average
of two better marks for each student. Print the USN, Name and the average marks of all
the students.
*/
#include <iostream>
using namespace std;
#define MAX 10 //to count the number of students
#define N 3    //Total number of tests
class Student{
    private:
        string usn;
        string name;
        int marks[N];
    public:
        void set();
        float findAvg();
        void displayAll();
};

//to find the average marks
float Student::findAvg(){
    int sum=0;
    int min=marks[0];
    for(int i=0;i<N;i++){
        sum+=marks[i];
        if(marks[i]<min)
            min=marks[i];
    }
    return (float)(sum-min)/2;
}
void Student::set(){
    cout<<"\nUSN                  : ";
    cin>>usn;
    cout<<"Name                 : ";
    cin>>name;
    for(int i=0;i<N;i++){
        cout<<"Enter marks in test "<<i+1<<":";
        cin>>marks[i];
    }
}
//To display the student details
void Student::displayAll(){
    cout<<"\nStudent Name: "<<name;
    cout<<"\nStudent USN : "<<usn;
    cout<<"\nAverge Marks: "<<findAvg()<<endl;
}

int main(){
    Student student[MAX];
    int n;
    cout<<"\nEnter the number of students: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\n\tEnter the details of student "<<i+1<<endl;
        student[i].set();
    }
    for(int i=0;i<n;i++){
        cout<<"\n\tDetails of student "<<i+1<<endl;
        student[i].displayAll();
    }
    return 0;
}