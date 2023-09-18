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
#include <stdarg.h>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Function Headers
int isComment(char arr[], int size, int start, FILE** file);
int isOperator(char arr[], int position, FILE** file);
int isidentifier(char arr[], int position, FILE **file);
int isString(char arr[], int position, FILE **file);
int isNumber(char arr[], int position, FILE** file);
int isKeyword(char arr[], int position, FILE ** file);
void search(char ptr[], int size, FILE** file);

#endif