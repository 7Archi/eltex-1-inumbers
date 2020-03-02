#include "mycomplex.h"

void mul(struct mycomplex* a, struct mycomplex* b, struct mycomplex* c)
{
    c->real = a->real * b->real - a->img * b->img;
    c->img = a->real * b->img + a->img * b->real;
}
