#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"


/*
** main -- Function to implement the famous mastermind game. See
** the readme.md file for more info.
**
** @param {int} argc
**
** @param {char**} argv
**
** @return {int}
**
*/




int max_guesses = 10;
int num_guesses = 0;


int main(int argc, char** argv) {
   
    int* guess = malloc(sizeof(int) * CODE_LEN);
    int code[CODE_LEN];
   
    char* flags[2] = {"-c", "-t"};
   
    arg_check(argv, flags, code, argc);
   
    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    while (num_guesses < max_guesses) {
        printf("---\nRound %d\n", num_guesses);


        //keep waiting for input if input returns error
        int return_val = -1;
        while(return_val < 0) {
            return_val = read_guess(guess);
            //End Of File signal received
            if(return_val == -2){
                return 0;
            }
        }


        //num_well_placed and num_miss_placed decleared in the header mastermind.h
        check_guess(guess, code);
        if (num_well_placed != CODE_LEN){
            printf("Well placed pieces: %d\nMisplaced pieces: %d\n", num_well_placed, num_miss_placed);
        }else{
            printf("Congratz! You did it!\n");
            return 0;
        }


        num_guesses++;
    }


    free(guess);
    return 0;
}




/*
**
** arg_check -- function takes some pointers to an array of string pointers
** and an int pointer and lastly an interger, where argv and argc serve same
** purpose as in main function parameter. where flag is a known string the
** function the int array code is updated based on the flag and argc count.
**
** @param {char**} argv
**
** @param {char**} flags
**
** @param {int*} code
**
** @param {int} argc
**
*/


void arg_check(char** argv, char** flags, int* code, int argc) {
   
     //if program is run with all 4 arguments
    if(argc == 5) {
        if(my_strcmp(argv[1], flags[0]) == 0 && my_isdigit(argv[2]) && my_strcmp(argv[3], flags[1]) == 0 && my_isdigit(argv[4])) {
            for(int i  = 0; i < CODE_LEN; i++) {
                code[i] = argv[2][i] - '0';
            }
            max_guesses = atoi(argv[4]);
        }else if(my_strcmp(argv[1], flags[1]) == 0 && my_isdigit(argv[2]) && my_strcmp(argv[3], flags[0]) == 0 && my_isdigit(argv[4])){
            for(int i = 0; i < CODE_LEN; i++) {
                code[i] = argv[4][i] - '0';
            }
            max_guesses = atoi(argv[2]);
        }
    }


     //if program is run with 2 arguments
    if(argc == 3) {
          if(my_strcmp(argv[1], flags[0]) == 0 && my_isdigit(argv[2])) {
            for(int i = 0; i < CODE_LEN; i++) {
                code[i] = argv[2][i] - '0';
            }
        }else if (my_strcmp(argv[1], flags[1]) == 0 && my_isdigit(argv[2])) {
            max_guesses = atoi(argv[2]);
            generate_code(code);
        }
    }
   
     //if program is run with no arguments
    if(argc == 1) {
        generate_code(code);
    }
}
