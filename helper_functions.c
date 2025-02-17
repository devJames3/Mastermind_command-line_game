#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "mastermind.h"


 //variables of type int decleared in the header mastermind.h
int num_well_placed = 0;
int num_miss_placed = 0;

/*
** generate_code -- function fills and int buffer with
** generated random code of specified length without duplicate
** values
**
** @param {int*} code
**
*/


void generate_code(int code[CODE_LEN]) {


    int ran_num;
    srand(time(NULL));


    for (int i = 0; i < CODE_LEN; i++) {
        ran_num = rand() % 9;


        //check for duplicates as array is updated
        int duplicate = 0;
        for(int j = 0; j < i; j++) {
            if(code[j] == ran_num){
                duplicate = 1;
                break;
            }
        }


        //if dupilicate try again
        if(duplicate){
            i--;
        }else{
            code[i] = ran_num;
        }
    }
   
}


/*
** read_guess -- function read code from standard input one
** character at a time using read() system call and stores in an
** char buffer, return 0 on success, -2 on end of file and -1 on invalid input.
**
** @param {int*} code_guess
**
** @return 0 {success}, -1, -2 {error}
*/


int read_guess(int guess[CODE_LEN]) {
   
    int size_read = 0;
    char* buffer = malloc(sizeof(char) * 1000);
    int i = 0;


    //[i - 1] to check the element read at previous index before incrementing i;
    while(buffer[i - 1] != '\n'){
        size_read += read(0, &buffer[i], 1);
        //trigger End Of File
        if(size_read == 0){
            return -2;
        }
        if(buffer[i] == 0){
            int val = check_input(buffer, guess, size_read);
            if(val == -1){
                return -1;
            }
            return 0;
        }
       
       
        i++;
    }
   
    int val = check_input(buffer, guess, size_read);
    if(val == -1){
        return -1;
    }


    free(buffer);
    return 0;


}


/*
**
** check_input -- function checks if input copied to a char buffer is valid, and
** then converts the elements in the char buffer to integers and updates the int
** array passed as parameter. Returns 0 on success and -1 on error.
**
** @param {char*} buff  
**
** @param {int*} guess
**
** @param {int} copy_size
**
*/


int check_input(char* buff, int guess[CODE_LEN], int copy_size){


    //input with End Of File ends with 0 not '\n' and 0 is not copied
    if((copy_size == CODE_LEN && buff[CODE_LEN] != 0) || (copy_size == CODE_LEN && buff[CODE_LEN - 1] == '\n')) {
        write(2, "Please enter four digits from 0 - 8\n", 36);
        return -1;
    }


    if((copy_size == CODE_LEN + 1 && buff[CODE_LEN] != '\n') || (copy_size == CODE_LEN && buff[CODE_LEN] != 0)){
        write(2, "Please enter four digits from 0 - 8\n", 36);
        return -1;
    }


    if(copy_size != CODE_LEN + 1 && copy_size != CODE_LEN) {
        write(2, "Please enter four digits from 0 - 8\n", 36);
        return -1;
    }


    for (int i = 0; i < CODE_LEN + 1; i++) {
        if ((buff[i] < '0' || buff[i] > '8') && buff[i] != '\n' && buff[i] != 0) {
            write(2, "Wrong input!\n", 13);
            return -1;
        }
        guess[i] = buff[i] - '0';
    }


    return 0;
}


/*
**
** check_guess -- function compares two int array to check if the
** members at the same index are equal or members in the first
** array are contained in the second array, and updates accordingly
**
** @param {int*} guess
**
** @param {int*} code
**
*/


void check_guess(int guess[CODE_LEN], int code[CODE_LEN]) {

    for (int i = 0; i < CODE_LEN; i++) {
        if (guess[i] == code[i]) {
            num_well_placed++;
        }else{
            for (int j = 0; j < CODE_LEN; j++) {
                if (guess[i] == code[j]) {
                    num_miss_placed++;
                    break;
                }
            }
        }
    }


}
