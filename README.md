# Welcome to My Mastermind
***
A command-line implementation of the classic code-breaking game Mastermind, written in C.


### Synopsis
my_mastermind [-ct]


-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.


-t [ATTEMPTS]: specifies the number of attempts; by default, the player has 10 attempts.


## Task
The challenge was to write a program called my mastermind; it will be an implementation of the famous game.


## Description
My Mastermind is a code-breaking game where one player creates a secret code and the other player attempts to guess it. The code can consist of a combination of 4 colors or numbers within the range of 0 to 8, and the guessing player must use their deduction skills to figure out the exact combination. After each guess, the program provides feedback in the form of Well placed and Misplaced pieces, where a Well placed piece indicates a correct color in the correct position, and a Misplaced piece indicates a correct color in the wrong position. The guessing player must use this feedback to make more informed guesses until they are able to crack the code or exhaust the maximum guess limit.


## Installation
To get started with this project, simply clone the repository to your local machine and compile the files with extension .c, using a C compiler. Once the code is compiled, you can run the program and play the game.


Alternatively if you have make utility installed run command `make my_mastermind` to compile the files and `make clean` to remove the object files created, then you can run the program and play the game.


## Usage
To play the game after compilation run:
```
./my_mastermind [-ct]


-c : to set the code, if not specified a random code is generated


-t: to set the maximum number of trials allowed if not specified 10 is assumed.


```


## Acknowledgments
The original game of Mastermind was created by Mordecai Meirowitz.


This implementation was inspired by Qwasar Software Engineering School


### The Core Team
James Okolie
