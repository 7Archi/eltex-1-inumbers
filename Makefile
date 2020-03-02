GCC = gcc -Wall -Werror

.PHONY: all clean 

all: main

main:   main.o
	$(GCC) main.o -o main

main.o: main.c
	$(GCC) -c main.c


clean:
	rm -rf *.o main
