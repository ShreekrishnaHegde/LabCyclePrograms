/*
-------------------------------2----------------------------------------
Design, Develop and Implement a Program for sorting the elements using
a. Insertion sort
b. Selection sort
*/
#include <stdio.h>

void printArray(int n,int a[]);
void selectionSort(int n,int a[]);

void main(){
    int a[20],n;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nArray Before Sorting: ");
    printArray(n,a);
    selectionSort(n,a);
    printf("Array after sorting (Using Selection Sort):");
    printArray(n,a);
}
void printArray(int n,int a[]){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}
void selectionSort(int n,int a[]){
    for(int i=0;i<n-1;i++){
        int last=n-i-1;
        int max=0;
        //Finding the max element in current array
        for(int j=0;j<=last;j++){
            if(a[j]>a[max])
                max=j;
        }
        //Swapping
        int temp=a[last];
        a[last]=a[max];
        a[max]=temp;
    }
}

/*
->We are going to select an element and place it in the right place , hence the name selection sort.
->Ex for sorting in ascending order.
->Select the largest element and place it in the last position by swapping.
->Then select 2nd largest element place it in the last-1 position by swapping.
->Repeat this process
->To find the max. element n-1 comparisons are made in first iteration.
    similarly total number of comparison= 1+3+4+... n-1.
    Hence,
->Time Complexity: Worst Case-O(n2), Worst Case-O(n2).
->Space Complexity: O(1).
-<Not stable sorting algorithm
-performs well on small data.
 */