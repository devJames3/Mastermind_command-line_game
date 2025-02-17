#ifndef MASTERMIND_H
#define MASTERMIND_H


#define CODE_LEN 4
#include <stdbool.h>


/*
* global variable decleared here, updated in check_guess
* function
*/
extern int num_well_placed;
extern int num_miss_placed;


// functions prototypes
int check_input(char* buff, int guess[CODE_LEN], int copy_size);
void generate_code(int code[CODE_LEN]);
int read_guess(int code[CODE_LEN]);
void check_guess(int guess[CODE_LEN], int code[CODE_LEN]);
void arg_check(char** argv, char** flags, int* code, int argc);
int my_strcmp(char *first, char *second);
bool my_isdigit(char* str);




#endif
