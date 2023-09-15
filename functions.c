/**
 * @file functions.c
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-08-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "functions.h"

//Function Definitions
int isComment(char arr[], int size, int start){
{
    for (int i= start; i< size; i++) //start=next char after /*
    {
        if (arr[i] == '*'&& arr[i+1]=='/'){
            int beginning=start-2; //beginning equals beginning of comment (starting with '/')
            int end=i+1; //end=the last '/' in comment
            while(beginning<=end)
            {
                printf("%c", arr[beginning]);
                beginning++;
            }
            printf(" (comment)\n");
            return end+1; //position of i after comment
        }
    }
    return -1;
}  
}
int isOperator(char arr[], int size, int position) //do I need size?
{
    int i=position;

        if(arr[i]==':'&& arr[i+1]=='=')
        {
            printf("%c%c", arr[i], arr[i+1]);
            printf(" (operator)\n");
            return i+1; //next position of char

        }
        else if(arr[i]=='*'&& arr[i+1]=='*')
        {
            printf("%c%c", arr[i], arr[i+1]);
            printf(" (operator)\n");
            return i+1; //next position of char
        }
        else if(arr[i]=='.' && arr[i+1]=='.')
        {
            printf("%c%c", arr[i], arr[i+1]);
            printf(" (operator)\n");
            return i+1; //next position of char

        }
        else if(arr[i]== '=' && arr[i+1]== '>')
        {
            printf("%c%c", arr[i], arr[i+1]);
            printf(" (operator)\n");
            return i+1; //next position of char
        }
        else if(arr[i]== '<' && (arr[i+1]=='<' || arr[i+1]== '='|| arr[i+1]== '>'))
        {
            printf("%c%c", arr[i], arr[i+1]);
            printf(" (operator)\n");
            return i+1; //next position of char

        }
        else if(arr[i]== '>' && (arr[i+1]=='>' || arr[i+1]== '='))
        {
            printf("%c%c", arr[i], arr[i+1]);
            printf(" (operator)\n");
            return i+1; //next position of char

        }
        else if(arr[i]=='!' && arr[i+1]=='=')
        {
            printf("%c%c", arr[i], arr[i+1]);
            printf(" (operator)\n");
            return i+1; //next position of char
        }
        else if(arr[i]=='(' ||arr[i]==')' ||arr[i]=='+' ||arr[i]=='-' ||arr[i]=='/' ||arr[i]=='|' 
        ||arr[i]=='&' ||arr[i]==';' ||arr[i]==',' ||arr[i]=='[' ||arr[i]==']' || arr[i]== ':' ||
        arr[i]== '*'|| arr[i]== '.' ||arr[i]== '=' || arr[i]=='<' || arr[i]== '>')
        {
            printf("%c", arr[i]);
            printf(" (operator)\n");
            return i;

        }
    return -1;
}
int isNumericLiteral(char arr[], int position)
{
    int end=-1;
    if(isdigit(arr[position])!=0) //if digit is found at first char
    {
        for(int i=position; i<10; i++)
        {
            while(isdigit(arr[i])!=0) //while a digit is found
            {
                i++;
            }
            if(arr[i]!='.'|| arr[i]!='#') //if element after digit isnt a '.' or a '#
            {
                end=i-1; //end = last digit
                for(int x=position; x<=end; x++)
                {
                    printf("%c", arr[x]); //print array of digits found

                }
                printf(" (numeric)\n");
                return end; //return next char

            }
            else if(arr[i]== '.'|| arr[i]=='#')
            {
                i++;
                while(isdigit(arr[i]!=0)) //while a digit is found after a '. or '#
                {
                    i++;

                }
                if(arr[i]!='#'){ //if a # is not found after last digit
                {
                    end=i-1;
                    for(int x=position; x<=end; x++)
                    {
                        printf("%c", arr[x]); //print array of digits found
                    }
                    printf(" (numeric)\n");
                    return end; //return next char
                }
                
                }
            }
        }
    }
    return -1;
}


int isKeyword(char arr[], int position)
{
    // char *keyword[]={"accessor," "and," "array," "begin," "bool," "case," "character," "constant,"
    //             "else," "elseif," "end," "exit," "function," "if," "in," "integer," "interface,"
    //             "is," "loop," "module," "mutator," "natural," "null," "of," "or," "other," "out,"
    //             "positive," "procedure," "range," "return," "struct," "subtype," "then," "type," "when," "while"};
    // int start=position;
    // int space=-1;
    // char *str="";
    // for(int i=position; i<11; i++)
    // {
    //     if(isspace(arr[i]!=0)) //isspace returns non-zero int if there is a space
    //     {
    //         space=i;
    //         str = malloc(space* sizeof(char));
    //         for(int x=start; i<space; i++)
    //         {
    //             str[x]=arr[x]; //copying char array into string
    //         }
    //         str[space]='\0';
    //         break;
    //     }
    // }
    // int result=-1;
    // if(space!=-1)
    // {
    //     for(int i=0; i<space; i++)
    //     {
    //         result=strcmp(keyword[i], &str[i]);
    //     }
    //     if(result==0) //if the strings are equal
    //     {
    //         for(int i=start; i<space; i++)
    //         {
    //             printf("%c", arr[i]);
    //         }
    //         return space+1; //return next char in array
            
    //     }

    // }
    // return -1;
}





