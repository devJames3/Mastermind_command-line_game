CC=gcc
CFLAGS= -Wall -Wextra -Werror
OBJ= my_mastermind.o library_fun.o helper_functions.o


%.o: %.c
    $(CC) -c $< $(CFLAGS) -o $@


my_mastermind: $(OBJ)
    $(CC) $^ $(CFLAGS) -o $@


.PHONY: clean


clean:
    rm -f *.o


fclean: clean
    rm -f my_mastermind


re: fclean my_mastermind
