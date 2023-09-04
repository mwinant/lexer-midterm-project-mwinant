#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[] ) //argc is the argument count. 
//It is the number of arguments passed into the program from the command line, including the name of the program.
{
    FILE *fp=NULL;
    char *filename;
    char ch;
    // Check if a filename has been specified in the command
    if (argc < 2)
    {
        printf("Missing Filename\n");
        return(1);
    }
    else
    {
        filename = argv[1];
        printf("Filename : %s\n", filename);
    }
    //if file does not exist        
    if ( filename == 0 )
    {
        printf( "Could not open file\n" );
        exit(0);
    }
    ch=fgetc(fp);
    while(ch != EOF)
    {
        printf("%c", ch);
    }

    //close file
    fclose( fp );
    return 0;
}
