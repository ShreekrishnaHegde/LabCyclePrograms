/*
Write a C++ program to create a template function for Quick sort and demonstrate
sorting of integers and doubles.
*/
#include <iostream>
using namespace std;
//Recursive Template function to sort the array elements using Quick sort algorithm.
template <typename T>
void quick(T nums[],int l,int h){
        if(l>=h)
            return;
        int start=l;
        int end=h;
        int m=start+(end-start)/2;
        T pivot=nums[m];
        while (start<=end){
            //if the array is sorted it ll not swap.
            while(nums[start]<pivot)
                start++;
            while (nums[end]>pivot)
                end--;
            if(start<=end){
                T temp=nums[start];
                nums[start]=nums[end];
                nums[end]=temp;
                start++;
                end--;
            }
        }
        quick<T>(nums,l,end);
        quick<T>(nums,start,h);

}
//Template function to read the array elements
template <typename t1>
void read(t1 nums[],int n){
    cout<<"\nEnter the elements:  ";
    for(int i=0;i<n;i++)
        cin>>nums[i];
}
//Template function to display the array elenments
template <typename t2>
void display(t2 nums[],int n){
    cout<<"\nArray after sorting: ";
    for(int i=0;i<n;i++)
        cout<<" "<<nums[i];
}
int main(){
    int choice,n;
    int Int[10];
    double Dbl[10];
    cout<<"\n\t1.Integer\n\t2.Double\nEnter your choice: ";
    cin>>choice;
    cout<<"\nEnter the number of elements: ";
    cin>>n;
    switch(choice){
        case 1: read<int>(Int,n);
                quick<int>(Int,0,n-1);
                display<int>(Int,n);
                break;
        case 2: read<double>(Dbl,n);
                quick<double>(Dbl,0,n-1);
                display<double>(Dbl,n);
                break;
    }
    return 0;
}



/*
----------Algorithm--------
->Choose any element as pivot
->After first pass, all the elements less than pivot will be on left side of pivot
    and elements on greater than pivot will be on right side of the pivot.
->After every pass you are putting pivot at the current position.

Complexity:
T(N)=T(K)+T(N-K-1)+O(N)
When one part of array is empty then it is worst case.
T(N)=T(n-1)+O(N)
Complexity:O(N2)
Best case
Complexity:T(N/2)+T(N/2)+O(N)
O(NlogN)
--------------------------------------------------
->Not stable
->In place sorting algorithm
*/


