#ifndef _MYCOMPLEX_
#define _MYCOMPLEX_

struct mycomplex
{
    int real;
    int img;
};

void add(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void sub(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void mul(struct mycomplex *, struct mycomplex *, struct mycomplex *);
void divv(struct mycomplex *, struct mycomplex *, struct mycomplex *);

#endif
