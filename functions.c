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
bool isKeyword(FILE *fp)
{
    char keyword[]={"accessor," "and," "array," "begin," "bool," "case," "character," "constant,"
                "else," "elseif," "end," "exit," "function," "if," "in," "integer," "interface,"
                "is," "loop," "module," "mutator," "natural," "null," "of," "or," "other," "out,"
                "positive," "procedure," "range," "return," "struct," "subtype," "then," "type," "when," "while"};

    int i;
    for(i = 0; i < 32; ++i){
       // if(strcmp(keyword[i], fp) == 0){
        return true;
        break;
        }
    
    return false;
}




