/*
---------------------------08-----------------------------
Write a C++ program to create a class called MATRIX using a two-dimensional array of
integers. Implement the following operations by overloading the operator = = which
checks the compatibility of two matrices to be added and subtracted. Perform the
addition and subtraction by overloading the operators + and – respectively. Display the
results by overloading the operator <<.
If (m1= = m2)
{
m3 = m1 + m2;
m4 = m1 – m2;
}
else
display error
*/


#include <iostream>
using namespace std;


class Matrix{
    private:
            int row,col,a[10][10];
    public:
            Matrix(int row,int col){
                this->row=row;
                this->col=col;
            }
            void getMatrix();
            int operator==(Matrix);
            Matrix operator+(Matrix);
            Matrix operator-(Matrix);
            friend ostream& operator<<(ostream&,Matrix &);

};

//To input the matrix elememts
void Matrix::getMatrix(){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cin>>a[i][j];
    }
}

//Overloading == operator two check whether two matrices have same order
int Matrix::operator==(Matrix m1){  
    if(m1.row==this->row && m1.col==this->col)
        return 1;
    else   
        return 0;
}

//Overloading + operator to add the corresponding elements of the matrix
Matrix Matrix::operator+(Matrix m1){
    Matrix m3(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            m3.a[i][j]=this->a[i][j]+m1.a[i][j];
    }
    return m3;
}
//Overloading - operator to subtract the coressponding elements of the matrix
Matrix Matrix::operator-(Matrix m1){
    Matrix m4(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            m4.a[i][j]=this->a[i][j]-m1.a[i][j];
    }
    return m4;
}

ostream& operator<<(ostream& print,Matrix &res){
    for(int i=0;i<res.row;i++){
        for(int j=0;j<res.col;j++)
            print<<res.a[i][j]<<"\t";
        print<<endl;
    }
    return print;
}

int main(){
    int m,n,p,q;
    cout<<"\nEnter the order of the First Matrix: ";
    cin>>m>>n;
    Matrix m1(m,n);
    cout<<"\nEnter the order of the Second Matrix: ";
    cin>>p>>q;
    Matrix m2(p,q);

    if(m1==m2){
        cout<<"\nEnter the elements of First Matrix: ";
        m1.getMatrix();
        cout<<"\nEnter the elements of Second Matrix: ";
        m2.getMatrix();
        Matrix m3(m,n),m4(m,n);
        m3=m1+m2;
        m4=m1-m2;
        cout<<m1<<"    +\n"<<m2<<"    =\n"<<m3<<endl;
        cout<<m1<<"    -\n"<<m2<<"    =\n"<<m4<<endl;
    }
    else{
        cout<<"\nTwo matrices are not compitable for addition/subtraction";
    }
    return 0;
}