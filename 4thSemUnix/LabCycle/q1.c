/*
Write a C program to implement cat command using general file APIs.
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char** argv){
    FILE *p;
    // Buffer to store each line read from the file
    char str[100];
    if(argc!=2){
        puts("Usage: command(./a.out) filename(examplefile.txt)");
    }
    //Open file in read mode
    p=fopen(argv[1],"r");
    if(p==NULL){
        puts("File doesn't exists");
        exit(0);
    }
    while(fgets(str,100,p)!=NULL){
        printf("%s",str);
    }
    fclose(p);
    return 0;
}