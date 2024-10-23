#include <stdlib.h>
#ifndef STACK_H
#define STACK_H

typedef struct {
    char** data;
    int size;
    int capac;
} stack;

stack* init(int cap);
void push(stack* root, char* str);
char* pop(stack* root);
void destroy(stack* root);
int isEmpty(stack* root);
char* peek(stack* root);

#endif
