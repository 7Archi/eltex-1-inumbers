#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

struct mycomplex
{
    int real;
    int img;
};

void add(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = a->real + b->real;
    c->img = a->img + b->img;
}

void sub(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = a->real - b->real;
    c->img = a->img - b->img;
}

void mul(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = a->real * b->real - a->img * b->img;
    c->img = a->real * b->img + a->img * b->real;
}

void divv(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = (a->real * b->real + a->img * b->img) / (b->real * b->real + b->img * b->img);
    c->img = (b->real * a->img - b->img * a->real) / (b->real * b->real + b->img * b->img);
}

int main(int argc, char* argv[])
{                      
    int op = 0;
    struct mycomplex* a = malloc(sizeof(struct mycomplex));
    struct mycomplex* b = malloc(sizeof(struct mycomplex));
    struct mycomplex* c = malloc(sizeof(struct mycomplex));

    while((op!=1)&&(op!=2)&&(op!=3)&&(op!=4)&&(op!=5)){
	system("clear");
        printf("Choose the operation\n1 - Add\n2 - Sub\n3 - Mul\n4 - Div\n5 - Quit\n");
        scanf("%d", &op);
    }
    
    if(op==5) return 0;
    printf("Input A\n");
    scanf("%d%d", &a->real, &a->img);
    printf("Input B\n");
    scanf("%d%d", &b->real, &b->img);

    if(op==1) {
	add(a, b, c);
	printf("A + B = %d + %di\n", c->real, c->img);
    }
    if(op==2) {
	sub(a, b, c);
	printf("A - B = %d + %di\n", c->real, c->img);
    }  
    if(op==3) {
	mul(a, b, c);
	printf("A * B = %d + %di\n", c->real, c->img);
    }
    if(op==4) {
	divv(a, b, c);
	printf("A / B = %d + %di\n", c->real, c->img);
    }

    return 0;
} 
