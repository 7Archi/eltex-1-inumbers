#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "mycomplex.h"

int main(int argc, char* argv[])
{                      
    int op = 0;
    struct mycomplex* a = malloc(sizeof(struct mycomplex));
    struct mycomplex* b = malloc(sizeof(struct mycomplex));
    struct mycomplex* c = malloc(sizeof(struct mycomplex));
    void* lib1;
    void* lib2;
    void* lib3;
    void* lib4;
    void* (*func)(struct mycomplex *, struct mycomplex *, struct mycomplex *);	
    while((op!=1)&&(op!=2)&&(op!=3)&&(op!=4)&&(op!=5)){
	system("clear");
        printf("Choose the operation\n1 - Add\n2 - Sub\n3 - Mul\n4 - Div\n5 - Quit\n");
        scanf("%d", &op);
    }

    if(op==5) exit(1);
    printf("Input A\n");
    scanf("%d%d", &a->real, &a->img);
    printf("Input B\n");
    scanf("%d%d", &b->real, &b->img);

    if(op==1) {
	lib1 = dlopen("libs/libadd.so", RTLD_LAZY);
	if(!lib1) 
        {
            printf("Can't open libadd.so ");
            exit(1);
        }
        func = dlsym(lib1, "add");
	(*func)(a, b, c);
	dlclose(lib1);
	printf("A + B = %d + %di\n", c->real, c->img);
    }

    if(op==2) {
	lib2 = dlopen("libs/libsub.so", RTLD_LAZY);
	if(!lib2) 
        {
            printf("Can't open libsub.so ");
            exit(1);
        }
	func = dlsym(lib2, "sub");
	(*func)(a, b, c);
	dlclose(lib2);
	printf("A - B = %d + %di\n", c->real, c->img);
    }  

    if(op==3) {
	lib3 = dlopen("libs/libmul.so", RTLD_LAZY);
	if(!lib3) 
        {
            printf("Can't open libmul.so ");
            exit(1);
        }
	func = dlsym(lib3, "mul");
	(*func)(a, b, c);
	dlclose(lib3);
	printf("A * B = %d + %di\n", c->real, c->img);
    }

    if(op==4) {
	lib4 = dlopen("libs/libdivv.so", RTLD_LAZY);
	if(!lib4) 
        {
            printf("Can't open libdivv.so ");
            exit(1);
        }
	func = dlsym(lib4, "divv");
	(*func)(a, b, c);
	dlclose(lib4);
	printf("A / B = %d + %di\n", c->real, c->img);
    }

    return 0;
} 
