# Lexer
## Project Details
Built a lexer in C language that successfully scans through a set of programs expressed in the CCX programming language. 
  
 A sample CCX program is below. This program simply prints the string "Hello, world" to the screen and then prints the arguments to the program if any were provided. 
 ````c
/* 
* Hello world with args. 
*/ 
procedure main(argc: integer; argv: string_vector_type) is 
begin printf("Hello, world\n"); 
loop 
argc := argc - 1; 
exit when (argc = 0);
 printf("arg[%d]: %s\n", argc, argv[argc]); 
end loop; 
end main;
````
The lexer classifies each lexeme found in a given source file into one of 8 categories. These categories are: **comment**, **string**, **keyword**, **character literal**, **numeric literal**, **operator**, **identifier**, and **UNK**. 

* a single space appears between each lexeme and its classification
* the classification appears in parentheses.

## Example Output
````
/* 
* Hello world with args. 
*/ (comment) 
procedure (keyword) 
main (identifier) 
( (operator) 
argc (identifier) 
: (operator) 
integer (keyword) 
; (operator) 
argv (identifier) 
: (operator) 
string vector type (identifier) 
) (operator) 
is (keyword) 
begin (keyword) 
printf (identifier) 
( (operator) 
"Hello, world\n" (string) 
) (operator) 
; (operator) 
loop (keyword)
argc (identifier) 
:= (operator) 
argc (identifier) 
- (operator) 
1 (numeric literal) 
; (operator) 
exit (keyword) 
when (keyword) 
( (operator) 
argc (identifier) 
= (operator) 
0 (numeric literal) 
) (operator) 
; (operator) 
printf (identifier) 
( (operator) 
"arg[%d]: %s\n" (string) 
, (operator) 
argc (identifier) 
, (operator) 
argv (identifier) 
[ (operator) 
argc (identifier) 
] (operator) 
) (operator) 
; (operator) 
end (keyword) 
loop (keyword) 
; (operator) 
end (keyword) 
main (identifier) 
; (operator)
````