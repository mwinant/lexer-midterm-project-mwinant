#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[] ) //argc is the argument count. 

{
    FILE *fp;
    char *filename;
    // Check if a filename has been specified in the command
    if (argc < 2)
    {
        printf("File name not entered\n");
        return(1);
    }
    else
    {
        filename = argv[1];
    }
    char file[50]="files/";
    char *newFile=strcat(file, filename);

    //open file
    fp = fopen(newFile,"r"); //"r" means read only
    //if file does not open       
    if (!fp)
    {
        printf( "Error opening file\n" );
        exit(1);
    }
    //Get size of file 
    fseek(fp, 0, SEEK_END);
    size_t size=ftell(fp);
    fseek(fp, 0, SEEK_SET);
    // //Allocate memory
    char *ptr=NULL;
    ptr=malloc(size*sizeof(char)+1); //plus 1 to add null terminator
    
    fread(ptr, 1, size, fp); //read file into ptr
    ptr[size]='\0'; //added null terminator to ptr
    //printf("%s", ptr); //print ptr

    search(ptr, size); //search ptr for operators, keywords, etc and display them

    //close file
    fclose( fp );
    free(ptr);
    return 0;
}
 //char *token=strtok(fp, " ");