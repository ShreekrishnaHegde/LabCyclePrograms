/*
Design, Develop and Implement a menu driven Program for the following array
operations.
a. Creating an array of N Integer Elements.
b. Display array Elements with Suitable Headings.
c. Inserting an Element (ELEM) at a given valid Position (POS).
d. Deleting an Element at a given valid Position (POS).
e. Exit. Support the program with functions for each of the above operations.
*/
#include <stdio.h>

void insertion(int arr[],int n,int index,int value){
    printf("Array before insertion: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    for(int i=n-1;i>=index;i--)
        arr[i+1]=arr[i];
    arr[index]=value;
    printf("\n");
    printf("\nArray after insertion: ");
    for(int i=0;i<n+1;i++)
        printf(" %d",arr[i]);
}  

void deletion(int arr[],int n,int index){
    printf("Array before deletion: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    for(int i=index;i<n;i++)
        arr[i]=arr[i+1];
    printf("\n");
    printf("Array after deletion: ");
    for(int i=0;i<n-1;i++)
        printf("%d ",arr[i]); 
}

void main(){
    int n,arr[15],pos,value,ch;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\n\t1.Insertion\n\t3.Deletion");
    do{
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the index and the element for insertion: ");
                scanf("%d%d",&pos,&value);
                insertion(arr,n++,pos,value);
                break;
            case 2:
                printf("\nEnter the index: ");
                scanf("%d",&pos);
                deletion(arr,n--,pos);
                break;
            default:
                printf("Invalid Choice");
                break;
        }
    }
    while(ch!=4);
}