#include <stdbool.h>
#include <stdlib.h>
#include "mastermind.h"


/*
**
** myStrcmp -- function compares two strings character by
** character and returns 0 if the strings are equal or none
** zero otherwise.
**
** @param {char*} first
**
** @param {char*} second
**
** @return {int}
**
*/


int my_strcmp(char *first, char *second) {


    int i = 0;
    while (first[i] != '\0' && second[i] != '\0' && first[i] == second[i]) {
        i++;
    }
    return first[i] - second[i];
   
}


/*
**
** my_is_digit -- function checks if characters in string
** is a digit, returns true if it is a digit or false otherwise
**
** @param {char*} str
**
** @return {bool}
**
*/


bool my_isdigit(char* str) {


    int i = 0;
    while (str[i] != '\0') {
        if(str[i] >= 48 && str[i] <= 56) {
            i++;
        }
        else{
            return false;
        }
    }
    return true;


}
