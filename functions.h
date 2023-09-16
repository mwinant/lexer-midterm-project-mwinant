/**
 * @file functions.h
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-08-31
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//strcpy will be helpful for this assignment
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Function Headers
int isComment(char arr[], int size, int start);
int isOperator(char arr[], int size, int position);
//int isKeyword(char arr[], int position);
//int isNumericLiteral(char arr[], int position);
int isString(char arr[], int position);
int isNumber(char arr[], int position);
int getWord(char arr[], int position);





#endif