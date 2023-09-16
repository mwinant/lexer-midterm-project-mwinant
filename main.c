#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[] ) //argc is the argument count. 

{
    FILE *fp;
    char *filename;
    //char ch;
    // Check if a filename has been specified in the command
    if (argc < 2)
    {
        printf("File name not entered\n");
        return(1);
    }
    else
    {
        filename = argv[1];
        printf("Filename : %s\n", filename);
    }
    //char file[50]="files/";
    //string cat strcat();
    //open file
    //TODO change directory to folders
    fp = fopen(filename,"r"); //"r" means read only
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

    for(int i=0; i<size; i++)
    {
        if((ptr)[i]=='/') //looking for comments
        {
            if(ptr[i+1]=='*')
            {
                int comment=isComment(ptr, size, i+2); //isComment searches for end of comment
                if(comment!=-1) //if end of comment is found
                {
                    i=comment; //i becomes next char after end of comment
                }
            }

        }
        int operator=isOperator(ptr, size, i); //looking for operators
        if(operator!=-1)
        {
            i=operator;
        }
        int numeric=isNumber(ptr, i);
        if(numeric!=-1)
        {
            i=numeric;
        }
        int string=isString(ptr, i);
        if(string!=-1)
        {
            i=string;
        }
        int word=getWord(ptr, i);
        if(word!=-1)
        {
            i=word;
        }
        
    }

    //close file
    fclose( fp );
    free(ptr);
    return 0;
}
 //char *token=strtok(fp, " ");