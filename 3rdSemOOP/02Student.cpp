/*
Define a STUDENT class with USN, Name, and Marks in 3 tests of a subject.
Declare an array of 10 STUDENT objects. Using appropriate functions, find the average
of two better marks for each student. Print the USN, Name and the average marks of all
the students.
*/
#include <iostream>
using namespace std;
#define MAX 2
#define N 3
class Student{
    private:
        string usn;
        string name;
        int marks[N];
    public:
        void set();
        float findAvg(int n,int arr[]);
        void displayAll();
};
//to fine the average marks
float Student::findAvg(int n,int arr[]){
    int sum=0;
    int min=arr[0];
    for(int i=0;i<N;i++){
        sum+=arr[i];
        if(arr[i]<min)
            min=arr[i];
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
    cout<<"\nAverge Marks: "<<findAvg(N,marks)<<endl;
}
int main(){
    Student student[MAX];
    for(int i=0;i<MAX;i++){
        cout<<"\n\tEnter the details of student "<<i+1<<endl;
        student[i].set();
    }
    for(int i=0;i<MAX;i++){
        cout<<"\n\tDetails of student "<<i+1<<endl;
        student[i].displayAll();
    }
    return 0;
}