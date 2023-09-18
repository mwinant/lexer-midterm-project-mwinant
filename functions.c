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

//Function Definition
/**
 * @brief Search
 * 
 * @param ptr 
 * @param size 
 * @param file 
 */
void search(char ptr[], int size, FILE** file)
{
    for(int i=0; i<size; i++)
    {
        int commentFound=0; //setting Found variables to false
        int operatorFound=0;
        int keywordFound=0;
        int stringFound=0;
        int numericFound=0;

        if((ptr)[i]=='/') //looking for comments
        {
            if(ptr[i+1]=='*')
            {
                int comment=isComment(ptr, size, i+2, file); //isComment searches for end of comment
                if(comment!=-1) //if end of comment is found
                {
                    i=comment; //i becomes next char after end of comment
                    commentFound=1;
                }
            }

        }
        if(commentFound==0) //if comment was not found
        {
            int operator=isOperator(ptr, i, file); //looking for operators
            if(operator!=-1)
            {
                i=operator; //i is moved to correct position in array
                operatorFound=1;
            }

        }
        if(commentFound==0 && operatorFound==0) //if both comment and operator aren't found
        {
            int numeric=isNumber(ptr, i, file);
            if(numeric!=-1)
            {
                i=numeric; //i is moved to correct position in array
                numericFound=1;
            }

        }
        if(commentFound==0 && operatorFound==0 && numericFound==0) //if comment, operator, and number aren't found
        {
            int string=isString(ptr, i, file);
            if(string!=-1)
            {
                i=string; //i is moved to correct position in array
                stringFound=1;
            }
        }
        if(commentFound==0 && operatorFound==0 && numericFound==0 && stringFound==0) 
        //if comment, operator, and number, and string aren't found
        {
            int keyword=isKeyword(ptr, i, file);
            if(keyword!=-1)
            {
                i=keyword; //i is moved to correct position in array
                keywordFound=1;
            }

        }
        if(commentFound==0 && operatorFound==0 && numericFound==0 && stringFound==0 && keywordFound==0)
        //if comment, operator, and number,string, and keyword aren't found
        {
            int identifier=isidentifier(ptr, i, file);
            if(identifier!=-1)
            {
                i=identifier; //i is moved to correct position in array
            }
        }
        
    }
}
/**
 * @brief beginning of comment has been found, this function looks for the end of the comment
 * 
 * @param arr 
 * @param size 
 * @param start 
 * @return int position of last element in comment
 */
int isComment(char arr[], int size, int start, FILE **file){
{
    for (int i= start; i< size; i++) //start=next char after /*
    {
        if (arr[i] == '*'&& arr[i+1]=='/'){
            int beginning=start-2; //beginning equals beginning of comment (starting with '/')
            int end=i+1; //end=the last '/' in comment
            while(beginning<=end)
            {
                fprintf(*file, "%c",arr[beginning]);
                beginning++;
            }
            fprintf(*file, " (comment)\n");
            return end+1; //position of i after comment
        }
    }
    return -1;
}  
}
/**
 * @brief checks element in array for " . if found, the function finds the next 
 * " and prints the string
 * 
 * @param arr 
 * @param position 
 * @return int position of last element of string
 */
int isString(char arr[], int position, FILE **file)
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
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (string)\n");
        return end; //return position of last element in string "

    }
    return -1;
}
/**
 * @brief checks element in array for an operator
 * prints operator if found
 * 
 * @param arr 
 * @param position 
 * @return int 
 */
int isOperator(char arr[], int position, FILE **file)
{
    int i=position;

        if(arr[i]==':'&& arr[i+1]=='=')
        {
            fprintf(*file,"%c%c", arr[i], arr[i+1]);
            fprintf(*file," (operator)\n");
            return i+1; //next position of char

        }
        else if(arr[i]=='*'&& arr[i+1]=='*')
        {
            fprintf(*file,"%c%c", arr[i], arr[i+1]);
            fprintf(*file," (operator)\n");
            return i+1; //next position of char
        }
        else if(arr[i]=='.' && arr[i+1]=='.')
        {
            fprintf(*file,"%c%c", arr[i], arr[i+1]);
            fprintf(*file," (operator)\n");
            return i+1; //next position of char

        }
        else if(arr[i]== '=' && arr[i+1]== '>')
        {
            fprintf(*file,"%c%c", arr[i], arr[i+1]);
            fprintf(*file," (operator)\n");
            return i+1; //next position of char
        }
        else if(arr[i]== '<' && (arr[i+1]=='<' || arr[i+1]== '='|| arr[i+1]== '>'))
        {
            fprintf(*file,"%c%c", arr[i], arr[i+1]);
            fprintf(*file," (operator)\n");
            return i+1; //next position of char

        }
        else if(arr[i]== '>' && (arr[i+1]=='>' || arr[i+1]== '='))
        {
            fprintf(*file,"%c%c", arr[i], arr[i+1]);
            fprintf(*file," (operator)\n");
            return i+1; //next position of char

        }
        else if(arr[i]=='!' && arr[i+1]=='=')
        {
            fprintf(*file,"%c%c", arr[i], arr[i+1]);
            fprintf(*file," (operator)\n");
            return i+1; //next position of char
        }
        else if(arr[i]=='(' ||arr[i]==')' ||arr[i]=='+' ||arr[i]=='-' ||arr[i]=='/' ||arr[i]=='|' 
        ||arr[i]=='&' ||arr[i]==';' ||arr[i]==',' ||arr[i]=='[' ||arr[i]==']' || arr[i]== ':' ||
        arr[i]== '*'|| arr[i]== '.' ||arr[i]== '=' || arr[i]=='<' || arr[i]== '>')
        {
            fprintf(*file,"%c", arr[i]);
            fprintf(*file," (operator)\n");
            return i;

        }
    return -1;
}
/**
 * @brief checks if element in array is a number, if so, it looks for the next non number 
 * character and stops unless it is a '.' or '#'
 * 
 * @param arr 
 * @param position 
 * @return int 
 */
int isNumber(char arr[], int position, FILE **file)
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
                    fprintf(*file,"%c", arr[x]); //print array
                }
                fprintf(*file," (numeric literal)\n");
                return i-1;
            }
            i++;
            while(arr[i]>='0'&& arr[i]<='9') //if there is a digit found
            {
                i++;
            }
    
            for(int x=position; x<i; x++) //printing array
            {
                fprintf(*file,"%c", arr[x]); //print array
            }
            fprintf(*file," (numeric)\n");
            return i;
        }
        else{
        for(int x=position; x<i; x++) //if we have found the end of the numeric string
        {
            fprintf(*file,"%c", arr[x]); //print array
        }
        fprintf(*file," (numeric)\n");
        return i;

        }
    }
    return -1;
}
/**
 * @brief checks if first element in array is a letter, if so
 * it prints until space or certain operator is reached
 * 
 * @param arr 
 * @param position 
 * @return int 
 */
int isidentifier(char arr[], int position, FILE **file)
{
    //isalpha tests if element is a letter. returns 0 if false

    if(isalpha(arr[position])!=0)
    {
        for(int i=position; i<position+20; i++)
        {
            if(arr[i]==' ' || arr[i]==';' || arr[i]=='(' || arr[i]==')' || arr[i]==':' ||arr[i]==',') //if end of identifier is found
            {
                for(int x=position; x<i; x++)
                {
                    fprintf(*file,"%c", arr[x]);
                }
                fprintf(*file," (identifier)\n");
                return i-1;
            }
        }
    }
    return -1;

}
/**
 * @brief searches array for keyword. if found, 
 * print keyword and return position of last letter in keyword
 * 
 * @param arr 
 * @param position 
 * @return int 
 */
int isKeyword(char arr[], int position, FILE **file)
{
    if(arr[position]=='b' && arr[position+1]=='e'&& arr[position+2]=='g' && arr[position+3]=='i' && arr[position+4]=='n') //begin
    {
        for(int i=position; i<=position+4; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+4;
    }
    else if(arr[position]=='a' && arr[position+1]=='c'&& arr[position+2]=='c' && arr[position+3]=='e' && arr[position+4]=='s' &&arr[position+5]=='s'
            && arr[position+6]=='o'&& arr[position+7]=='r') //accessor
    {
        for(int i=position; i<=position+7; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+7;
    }
    else if(arr[position]=='a' && arr[position+1]=='n'&& arr[position+2]=='d') //and
    {
        for(int i=position; i<=position+2; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+2;
    }
    else if(arr[position]=='a' && arr[position+1]=='r'&& arr[position+2]=='r' && arr[position+3]=='a' && arr[position+4]=='y') //array
    {
        for(int i=position; i<=position+4; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+4;

    }
    else if(arr[position]=='b' && arr[position+1]=='o'&& arr[position+2]=='o' && arr[position+3]=='l') //bool
    {
        for(int i=position; i<=position+3; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+3;  

    }
    else if(arr[position]=='c' && arr[position+1]=='a'&& arr[position+2]=='s' && arr[position+3]=='e') //case
    {
        for(int i=position; i<=position+3; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+3; 
    }
    else if(arr[position]=='c' && arr[position+1]=='h'&& arr[position+2]=='a' && arr[position+3]=='r' && arr[position+4]=='a' &&arr[position+5]=='c'
            && arr[position+6]=='t'&& arr[position+7]=='e' && arr[position+8]=='r') //character
    {
        for(int i=position; i<=position+8; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+8; 
    }
    else if(arr[position]=='c' && arr[position+1]=='o'&& arr[position+2]=='n' && arr[position+3]=='s' && arr[position+4]=='t' &&arr[position+5]=='a'
            && arr[position+6]=='n'&& arr[position+7]=='t') //constant
    {
        for(int i=position; i<=position+7; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+7; 
    }
    else if(arr[position]=='e' && arr[position+1]=='l'&& arr[position+2]=='s' && 
    arr[position+3]=='e' && arr[position+4]=='i' && arr[position+5]=='f') //elseif
    {
        for(int i=position; i<=position+5; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+5; 

    }
    else if(arr[position]=='e' && arr[position+1]=='l'&& arr[position+2]=='s' && arr[position+3]=='e') //else
    {
        for(int i=position; i<=position+3; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+3; 

    }
    else if(arr[position]=='e' && arr[position+1]=='n'&& arr[position+2]=='d') //end
    {
        for(int i=position; i<=position+2; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+2; 
    }
    else if(arr[position]=='e' && arr[position+1]=='x'&& arr[position+2]=='i' && arr[position+3]=='t') //exit
    {
        for(int i=position; i<=position+3; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+3; 

    }
    else if(arr[position]=='f' && arr[position+1]=='u'&& arr[position+2]=='n' && arr[position+3]=='c' && arr[position+4]=='t' &&arr[position+5]=='i'
            && arr[position+6]=='o'&& arr[position+7]=='n') //function
    {
        for(int i=position; i<=position+7; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+7; 
    }
    else if(arr[position]=='i' && arr[position+1]=='n'&& arr[position+2]=='t' && arr[position+3]=='e' && arr[position+4]=='g' &&arr[position+5]=='e'
            && arr[position+6]=='r') //integer
    {
        for(int i=position; i<=position+6; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+6; 
    }
    else if(arr[position]=='i' && arr[position+1]=='n'&& arr[position+2]=='t' && arr[position+3]=='e' && arr[position+4]=='r' &&arr[position+5]=='f'
            && arr[position+6]=='a'&& arr[position+7]=='c' && arr[position+8]=='e') //interface
    {
        for(int i=position; i<=position+8; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+8; 
    }
    else if(arr[position]=='l' && arr[position+1]=='o'&& arr[position+2]=='o' && arr[position+3]=='p') //loop
    {
        for(int i=position; i<=position+3; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+3; 

    }
    else if(arr[position]=='m' && arr[position+1]=='o'&& arr[position+2]=='d' && arr[position+3]=='u' 
            && arr[position+4]=='l' &&arr[position+5]=='e') //module
    {
        for(int i=position; i<=position+5; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+5; 
    }
    else if(arr[position]=='m' && arr[position+1]=='u'&& arr[position+2]=='t' && arr[position+3]=='a' && arr[position+4]=='t' &&arr[position+5]=='o'
            && arr[position+6]=='r') //mutator
    {
        for(int i=position; i<=position+6; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+6; 
    }
    else if(arr[position]=='n' && arr[position+1]=='a'&& arr[position+2]=='t' && arr[position+3]=='u' && arr[position+4]=='r' &&arr[position+5]=='a'
            && arr[position+6]=='l') //natural
    {
        for(int i=position; i<=position+6; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+6; 
    }
    else if(arr[position]=='n' && arr[position+1]=='u'&& arr[position+2]=='l' && arr[position+3]=='l') //null
    {
        for(int i=position; i<=position+3; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+3; 

    }
    else if(arr[position]=='o' && arr[position+1]=='u'&& arr[position+2]=='t') //out
    {
        for(int i=position; i<=position+2; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+2; 

    }
    else if(arr[position]=='o' && arr[position+1]=='t'&& arr[position+2]=='h' && arr[position+3]=='e' 
            && arr[position+4]=='r') //other
    {
        for(int i=position; i<=position+4; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+4; 
    }
    else if(arr[position]=='p' && arr[position+1]=='o'&& arr[position+2]=='s' && arr[position+3]=='i' && arr[position+4]=='t' &&arr[position+5]=='i'
            && arr[position+6]=='v' && arr[position+7]=='e') //positive
    {
        for(int i=position; i<=position+7; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+7; 
    }
    else if(arr[position]=='p' && arr[position+1]=='r'&& arr[position+2]=='o' && arr[position+3]=='c' && arr[position+4]=='e' &&arr[position+5]=='d'
            && arr[position+6]=='u' && arr[position+7]=='r' && arr[position+8]== 'e') //procedure
    {
        for(int i=position; i<=position+8; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+8; 
    }
    else if(arr[position]=='r' && arr[position+1]=='a'&& arr[position+2]=='n' && arr[position+3]=='g' 
            && arr[position+4]=='e') //range
    {
        for(int i=position; i<=position+4; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+4; 
    }
    else if(arr[position]=='s' && arr[position+1]=='t'&& arr[position+2]=='r' && arr[position+3]=='u' 
            && arr[position+4]=='c'&& arr[position+5]=='t') //struct
    {
        for(int i=position; i<=position+5; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+5; 
    }
    else if(arr[position]=='r' && arr[position+1]=='e'&& arr[position+2]=='t' && arr[position+3]=='u' 
            && arr[position+4]=='r'&& arr[position+5]=='n') //return
    {
        for(int i=position; i<=position+5; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+5; 
    }
    else if(arr[position]=='t' && arr[position+1]=='h'&& arr[position+2]=='e' && arr[position+3]=='n') //then
    {
        for(int i=position; i<=position+3; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+3; 
    }
    else if(arr[position-1]==' ' && arr[position]=='t'&& arr[position+1]=='y' && arr[position+2]=='p' && arr[position+3]=='e') //type
    {
        for(int i=position; i<=position+3; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+3; 
    }
    else if(arr[position]=='w' && arr[position+1]=='h'&& arr[position+2]=='e' && arr[position+3]=='n') //when
    {
        for(int i=position; i<=position+3; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+3; 
    }
    else if(arr[position]=='w' && arr[position+1]=='h'&& arr[position+2]=='i' && arr[position+3]=='l' && arr[position+4]=='e') //while
    {
        for(int i=position; i<=position+4; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+4; 
    }
    else if(arr[position]=='s' && arr[position+1]=='u'&& arr[position+2]=='b' && arr[position+3]=='t' && arr[position+4]=='y'
            && arr[position+5]=='p' && arr[position+6]=='e') //subtype
    {
        for(int i=position; i<=position+6; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+6; 
    }
    else if(arr[position]=='i' && arr[position+1]=='f') //if
    {
        for(int i=position; i<=position+1; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+1; 
    }
    else if(arr[position]=='o' && arr[position+1]=='f') //of
    {
        for(int i=position; i<=position+1; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+1; 
    }
    else if(arr[position]=='o' && arr[position+1]=='r') //or
    {
        for(int i=position; i<=position+1; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+1; 
    }
    else if(arr[position]=='i' && arr[position+1]=='s') //is
    {
        for(int i=position; i<=position+1; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+1; 
    }
    else if(arr[position]=='i' && arr[position+1]=='s') //in
    {
        for(int i=position; i<=position+1; i++)
        {
            fprintf(*file,"%c", arr[i]);
        }
        fprintf(*file," (keyword)\n");
        return position+1; 
    }

    else{
        return -1;
    }
}