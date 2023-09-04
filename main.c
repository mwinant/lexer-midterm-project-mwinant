#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[] ) //argc is the argument count. 

{
    char keyword[]={"accessor," "and," "array," "begin," "bool," "case," "character," "constant,"
                "else," "elseif," "end," "exit," "function," "if," "in," "integer," "interface,"
                "is," "loop," "module," "mutator," "natural," "null," "of," "or," "other," "out,"
                "positive," "procedure," "range," "return," "struct," "subtype," "then," "type," "when," "while"};

    FILE *fp;
    char *filename;
    char ch;
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
    //open file
    //TODO change directory to folders
    fp = fopen(filename,"r"); //"r" means read only
    //if file does not open       
    if (!fp)
    {
        printf( "Error opening file\n" );
        exit(1);
    }
    //Get size of file for memory allocation
    fseek(fp, 0, SEEK_END);
    size_t size=ftell(fp);
    fseek(fp, 0, SEEK_SET);
    //Allocate memory
    char *array=malloc(size*sizeof(char)+1); //plus 1 to add null terminator
    ch = fgetc(fp);
    fread(array, 1, size, fp); //read file into array
    array[size]='\0'; //added null terminator to array
    printf("%s", array); //print array

    //close file
    fclose( fp );
    return 0;
}
 //char *token=strtok(fp, " ");