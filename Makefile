GCC = gcc -Wall -Werror
LIB = build/add.o build/sub.o build/divv.o build/mul.o

.PHONY: all clean 

all: build lib default

lib: libmycomplex.a

default: mycomplex

libmycomplex.a: $(LIB)
	ar rc libmycomplex.a $(LIB)

mycomplex: build/main.o $(LIB)
	$(GCC) build/main.o -o mycomplex -L. -l mycomplex

build/add.o: src/add.c src/mycomplex.h
	$(GCC) -c src/add.c -o build/add.o

build/sub.o: src/sub.c src/mycomplex.h
	$(GCC) -c src/sub.c -o build/sub.o

build/mul.o: src/mul.c src/mycomplex.h
	$(GCC) -c src/mul.c -o build/mul.o

build/divv.o: src/divv.c src/mycomplex.h
	$(GCC) -c src/divv.c -o build/divv.o

build/main.o: src/main.c src/mycomplex.h
	$(GCC) -c src/main.c -o build/main.o

build:
	mkdir build

clean: 
	rm -rf build libmycomplex.a mycomplex



