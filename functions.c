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
bool isKeyword(FILE *fp)
{
    char keyword[]={"accessor," "and," "array," "begin," "bool," "case," "character," "constant,"
                "else," "elseif," "end," "exit," "function," "if," "in," "integer," "interface,"
                "is," "loop," "module," "mutator," "natural," "null," "of," "or," "other," "out,"
                "positive," "procedure," "range," "return," "struct," "subtype," "then," "type," "when," "while"};

    int i;
    for(i = 0; i < 32; ++i){
       // if(strcmp(keyword[i], fp) == 0){ //0 ==false
        return true;
        break;
        }
    
    return false;
}




