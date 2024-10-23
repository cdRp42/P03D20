
#include <stdlib.h>

#ifndef DSTACK_H
#define DSTACK_H

typedef struct {
    double* data;
    int size;
    int capac;
} doub_stack;

doub_stack* d_init(int cap);
void d_push(doub_stack* root, double num);
double d_pop(doub_stack* root);
void d_destroy(doub_stack* root);

#endif
