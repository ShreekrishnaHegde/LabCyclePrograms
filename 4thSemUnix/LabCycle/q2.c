/*
Write a C program to implement copy command using general file API's
*/
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 4096
int main(int argc,char** argv){
    FILE *src,*dst;
    char buffer[BUFFER_SIZE];
    // Number of bytes read in each iteration
    size_t bytes_read;
    if(argc!=3){
        fprintf(stderr,"Usafe %s <source_file> <destinatio_file>\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    src=fopen(argv[1],"rb");
    if(src==NULL){
        printf("Error opening source file");
        exit(EXIT_FAILURE);
    }
    dst=fopen(argv[2],"rb");
    if(dst==NULL){
        printf("Error opening destionation file");
        fclose(src);
        exit(EXIT_FAILURE);
    }
    dst=fopen(argv[2],"wb");
    while((bytes_read=fread(buffer,1,BUFFER_SIZE,src))>0)
        fwrite(buffer,1,bytes_read,dst);
    if(ferror(src))
        perror("Error reading from source file");
    if(ferror(dst))
        perror("Error writing to destination file");
    fclose(src);
    fclose(dst);
    printf("File Copy sccessfull");
    return 0;
}
