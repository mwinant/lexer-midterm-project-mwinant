#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include "functions.h"

int main(int argc, char *argv[] ) //argc is the argument count. 

{
    FILE *fp; //file for reading
    FILE *answerFile; //file for writing
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
    //opening file
    fp = fopen(filename,"r"); //"r" means read only
    //if file does not open       
    if (!fp)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char fileStart[50];
    strcpy(fileStart, filename);

    char file[50]=".lexer";
    char *newFile=strcat(fileStart, file);
    answerFile = fopen(newFile, "w"); // write only
    if (!answerFile)
    {
        printf( "Error opening answer file\n" );
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

    search(ptr, size, &answerFile); //search ptr for operators, keywords, etc and write to answer file

    //close file
    fclose(fp);
    free(ptr);
    return 0;
}
 //char *token=strtok(fp, " ");