/*
-------------------------------2----------------------------------------
Design, Develop and Implement a Program for sorting the elements using
a. Insertion sort
b. Selection sort
*/

#include <stdio.h>

void printArray(int n,int a[]);
void InsertionSort(int n,int a[]);

void main(){
    int a[20],n;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nArray Before Sorting: ");
    printArray(n,a);
    InsertionSort(n,a);
    printf("\nArray after sorting (Using Insertion Sort):");
    printArray(n,a);
}
void printArray(int n,int a[]){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
void InsertionSort(int n,int a[]){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0;j--){
            if(a[j]<a[j-1]){
                int temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
            else
                break;
        }
    }
} 

/*
->Here, we divide the array into small parts and sort it then increase its size.
->Ex:
    Select first two indices then sort them, then select the 3rd index and sort.
->In essence, we have to insert the next element into the right part of the array ,then put it in the correct
    index of left side.
->After 1st pass , first two elements will be sorted, after 2nd pass, first 3 elements will be sorted.
->Hence it takes n-1 pass , where n is the length of the array.
->Time Complexity: Worst Case- O(n2) Best Case-Linear Complexity
->Steps get reduced when array is sorted and hence it is adaptive.
->It is stable sorting algorithm.
->It is used for smaller size arrays.
->Works good when array is partially sorted.
->It takes part in hybrid sorting algorithm.
 */