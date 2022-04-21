CC = gcc
FLAGS = -Wall -Wextra

project: main.o test.o
    $(CC) $(FLAGS) main.o test.o -o project

main.o: main.c
    $(CC) $(FLAGS) -c main.c

test.o: test.c test.h
    $(CC) $(FLAGS) -c test.c

clean:
    del /Q /S *.o project