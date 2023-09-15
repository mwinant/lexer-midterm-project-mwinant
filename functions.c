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
int isString(char arr[], int position)
{
    int end=position+1;
    if(arr[position]=='"')
    {
        while(arr[end]!='"')
        {
            end++;
        }
        for(int i=position; i<=end; i++)
        {
            printf("%c", arr[i]);
        }
        printf(" (string)\n");
        return end;

    }
    return -1;
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
int isNumber(char arr[], int position)
{
    int i=position;
    if(arr[i]>='0'&& arr[i]<='9') //if first element is a number 0-9
    {
        while(arr[i]>='0'&& arr[i]<='9') //while loop for numbers
        {
            i++;
        }
        if(arr[i]=='.'|| arr[i]== '#') //after leaving while loop if '.' or '#' is found
        {
            if(arr[i+1]=='.') //if there are two . found in a row
            {
                for(int x=position; x<i; x++) //printing array
                {
                    printf("%c", arr[x]); //print array
                }
                printf(" (numeric)\n");
                return i-1;
            }
            i++;
            while(arr[i]>='0'&& arr[i]<='9') //if there is a digit found
            {
                i++;
            }
    
            for(int x=position; x<i; x++) //printing array
            {
                printf("%c", arr[x]); //print array
            }
            printf(" (numeric)\n");
            return i;
        }
        else{
        for(int x=position; x<i; x++) //if we have found the end of the numeric string
        {
            printf("%c", arr[x]); //print array
        }
        printf(" (numeric)\n");
        return i;

        }
    }
    return -1;
}

// int isKeyword(char arr[], int position)
// {
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
// /}





